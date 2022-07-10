#include "boss_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enemy_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/fight_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/player_manager.h"
#include "../engine/random_manager.h"
#include "../engine/select_manager.h"
#include "../engine/text_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include <stdbool.h>
#include <stdlib.h>

static unsigned char select_type;
static unsigned char event_stage;
static unsigned char enemys_damage;
static unsigned char player_damage;
static unsigned char player_weapon;
static unsigned char player_armor;
static unsigned char beg_boss_val;
static bool first_time;

static void boss_init( unsigned char *p_weapon, unsigned char *p_armor );
static void boss_stats( unsigned char *p_weapon, unsigned char *p_armor );
static void boss_laugh( unsigned char selection );

unsigned char beg_boss_hit[ 2 ] = { 2, 4 };

void screen_boss_screen_load()
{
	struct_game_object *go = &global_game_object;
	unsigned char row;
	unsigned char idx;

	select_type = select_type_boss;
	row = 1;

	devkit_SMS_displayOff();
	engine_text_manager_clear( TOP_Y + 1, TOP_Y + 22 );

	engine_content_manager_load_koschey();

	row = 19;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 2; idx++ )
	{
		engine_font_manager_draw_text( ( unsigned char* ) query_texts[ idx ], LEFT_X + 2, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_QUOTE, LEFT_X + 8, TOP_Y + 19 );
	engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 19, TOP_Y + 20 );

	engine_graphics_manager_draw_koschey( LEFT_X + 10, TOP_Y + 2, devkit_TILE_USE_SPRITE_PALETTE() );
	engine_graphics_manager_draw_border();

	devkit_SMS_displayOn();
	event_stage = scene_type_select;

	event_stage = scene_type_select;
	enemys_damage = 0;
	player_damage = 0;

	engine_target_manager_load( enemy_type_koschey );
	player_weapon = 0;
	player_armor = 0;

	// Easy mode gets increases weapon + armor.
	boss_init( &player_weapon, &player_armor );
	boss_stats( &player_weapon, &player_armor );

	if( diff_type_hard != go->difficulty )
	{
		boss_stats( &player_weapon, &player_armor );
	}

	beg_boss_val = beg_boss_hit[ go->difficulty ];
	first_time = true;
}

void screen_boss_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char selection;
	unsigned char random;
	unsigned char input;
	unsigned char idx;
	unsigned char row;

	if( first_time )
	{
		first_time = false;

		// Play boss music.
		engine_sound_manager_init();
		for( idx = 5; idx < 8; idx++ )
		{
			engine_music_manager_play( idx );
			engine_input_manager_update();
			input = engine_input_manager_move( input_type_fire2 );
			if( input )
			{
				idx = 8;
			}
		}

		// Erase wide text.
		engine_font_manager_draw_text( LOCALE_30_SPCS, LEFT_X + 1, TOP_Y + 19 );
		engine_font_manager_draw_text( LOCALE_30_SPCS, LEFT_X + 1, TOP_Y + 20 );

		row = 18;
		devkit_SMS_mapROMBank( FIXED_BANK );
		for( idx = 0; idx < 2; idx++ )
		{
			engine_font_manager_draw_text( ( unsigned char* ) boss_texts[ idx ], LEFT_X + 8, TOP_Y + row );
			row++;
		}
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 13, TOP_Y + 19 );
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 14, TOP_Y + 19 );

		// Print fight text and reset selection.
		engine_font_manager_draw_text( LOCALE_FIGHT_MSG1, LEFT_X + 2, TOP_Y + TOP_Y + 21 );
		engine_font_manager_draw_text( LOCALE_BOSSX_MSG2, LEFT_X + 16, TOP_Y + TOP_Y + 21 );
		engine_font_manager_draw_punc( LOCALE_HYPHEN, LEFT_X + 10, TOP_Y + TOP_Y + 21 );
		engine_font_manager_draw_punc( LOCALE_HYPHEN, LEFT_X + 26, TOP_Y + TOP_Y + 21 );
		engine_font_manager_draw_punc( LOCALE_QUOTE, LEFT_X + 23, TOP_Y + TOP_Y + 21 );

		engine_player_manager_hplo();
		engine_enemy_manager_hplo();

		engine_select_manager_load( select_type, LEFT_X + 5, TOP_Y + 18, 2 );
	}

	selection = 0;
	if( scene_type_select == event_stage )
	{
		selection = engine_select_manager_update( select_type );
		if( NO_SELECTION == selection )
		{
			*screen_type = screen_type_boss;
			return;
		}

		event_stage = scene_type_decide;
	}

	if( scene_type_decide == event_stage )
	{
		if( boss_type_beg == selection )
		{
			// If not invincible.
			if( !ho->hack_nodead )
			{
				// Subtract HP if you beg.
				engine_player_manager_hit( beg_boss_val );
				if( engine_player_manager_dead() )
				{
					// Check if player has extra life!
					if( engine_player_manager_life() )
					{
						*screen_type = screen_type_relive;
						return;
					}

					*screen_type = screen_type_over;
					return;
				}
			}
		}
		if( boss_type_battle == selection )
		{
			random = engine_random_manager_next();
			engine_fight_manager_player_to_boss( &enemys_damage, random, player_weapon );

			random = engine_random_manager_next();
			engine_fight_manager_boss_to_player( &player_damage, random );

			// If both you and boss have 0 HP then you get game over first!
			engine_player_manager_armor( player_armor );
			engine_player_manager_hit( player_damage );

			if( engine_player_manager_dead() )
			{
				// Check if player has extra life!
				if( engine_player_manager_life() )
				{
					*screen_type = screen_type_relive;
					return;
				}

				*screen_type = screen_type_over;
				return;
			}

			engine_enemy_manager_hit( enemys_damage );
			if( engine_enemy_manager_dead() )
			{
				engine_enemy_manager_hplo();
				*screen_type = screen_type_kill;
				return;
			}
		}

		// Display updated HP after checking deaths.
		engine_player_manager_hplo();
		engine_enemy_manager_hplo();

		boss_laugh( selection );
		engine_sound_manager_fight();
		event_stage = scene_type_select;
	}

	*screen_type = screen_type_boss;
}

static void boss_init( unsigned char *p_weapon, unsigned char *p_armor )
{
	struct_player_object *po = &global_player_object;

	*p_weapon = po->weapon;
	*p_armor = po->armor;
}

static void boss_stats( unsigned char *p_weapon, unsigned char *p_armor )
{
	struct_player_object *po = &global_player_object;
	if( po->xp > 60 )
	{
		*p_weapon += 1;
		*p_armor += 1;
	}
}

static void boss_laugh( unsigned char selection )
{
	devkit_SMS_mapROMBank( FIXED_BANK );
	if( boss_type_battle == selection )
	{
		selection = rand() % 2;
		selection += 1;
	}

	engine_font_manager_draw_text( ( unsigned char* ) laugh_texts[ selection ], LEFT_X + 22, TOP_Y + 12 );
	if( 1 == selection )
	{
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 29, TOP_Y + 12 );
	}
}
