#include "forest_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enemy_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/fight_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
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

static unsigned char curr_selection;
static unsigned char prev_selection;

static unsigned char event_stage;
static unsigned char enemys_damage;
static unsigned char player_damage;
static unsigned char player_gold;
static unsigned char select_type;
static unsigned char run_away_val;

static void setup();
static bool calc_add_armor();

unsigned char run_away_hit[ MAX_ENEMIES ] = { 1, 2, 1 };

void screen_forest_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;
	select_type = select_type_forest;

	engine_enemy_manager_load( po->level );

	devkit_SMS_displayOff();
	setup();
	devkit_SMS_displayOn();

	curr_selection = 0;
	prev_selection = 0;
	event_stage = scene_type_select;

	enemys_damage = 0;
	player_damage = 0;
	player_gold = 0;
	run_away_val = run_away_hit[ go->difficulty ];
	if( po->level == 1 && go->difficulty == diff_type_hard )
	{
		run_away_val = 1;
	}
}

void screen_forest_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	unsigned char random;
	unsigned char input;
	unsigned char value;
	unsigned char xp = 0;
	bool add_armor = true;

	if( scene_type_pushon == event_stage )
	{
		input = engine_input_manager_hold( input_type_fire1 );
		if( input )
		{
			engine_font_manager_text( LOCALE_FIGHT_BLANKS, LEFT_X + 5, FIGHT_ROW - 3 );
			engine_font_manager_text( LOCALE_FIGHT_BLANKS, LEFT_X + 5, FIGHT_ROW - 2 );

			if( fight_type_battle == curr_selection )
			{
				// Calculate whether to add armor on hard difficulty.
				add_armor = calc_add_armor();
				if( add_armor )
				{
					engine_player_manager_armor( po->armor );
				}

				// If both you and enemy have 0 HP then you get game over first!
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
					engine_fight_manager_gold( &xp, &player_gold );
					engine_player_manager_inc_gold( xp, player_gold );

					*screen_type = screen_type_victory;
					return;
				}
			}

			// Display updated HP after checking deaths.
			engine_player_manager_hplo();
			engine_enemy_manager_hplo();

			event_stage = scene_type_select;
			*screen_type = screen_type_forest;
			return;
		}
	}

	if( scene_type_select == event_stage )
	{
		input = engine_input_manager_hold( input_type_fire2 );
		if( input )
		{
			// If difficulty not hard then cheat and run away unconditionally.
			if( diff_type_hard != go->difficulty )
			{
				*screen_type = screen_type_stats;
				return;
			}

			// If invincible then run away.
			if( ho->hack_nodead )
			{
				*screen_type = screen_type_stats;
				return;
			}
		}

		curr_selection = engine_select_manager_update( select_type );
		if( NO_SELECTION == curr_selection )
		{
			*screen_type = screen_type_forest;
			return;
		}

		prev_selection = curr_selection;
		event_stage = scene_type_decide;
	}

	if( scene_type_decide == event_stage )
	{
		if( fight_type_run == curr_selection )
		{
			// If invincible then run away.
			if( ho->hack_nodead )
			{
				*screen_type = screen_type_stats;
				return;
			}

			value = rand() % MAX_RANDOM;
			if( value < HLF_RANDOM )
			{
				*screen_type = screen_type_stats;
				return;
			}
			else
			{
				// Subtract HP as cannot currently run away.
				engine_player_manager_hit( run_away_val );
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

				engine_sound_manager_play( sound_type_10 );
				engine_font_manager_text( LOCALE_FIGHT_NOTRUN, LEFT_X + 5, FIGHT_ROW - 3 );
				event_stage = scene_type_pushon;
			}
		}
		if( fight_type_battle == curr_selection )
		{
			engine_sound_manager_fight();

			random = engine_random_manager_next();
			engine_fight_manager_player_to_enemy( &enemys_damage, random );

			random = engine_random_manager_next();
			engine_fight_manager_enemy_to_player( &player_damage, random );

			engine_font_manager_text( LOCALE_FIGHT_ENEMYS, LEFT_X + 5, FIGHT_ROW - 3 );
			engine_font_manager_text( LOCALE_FIGHT_PLAYER, LEFT_X + 5, FIGHT_ROW - 2 );

			engine_font_manager_data( enemys_damage, LEFT_X + 23, FIGHT_ROW - 3 );
			engine_font_manager_data( player_damage, LEFT_X + 23, FIGHT_ROW - 2 );

			event_stage = scene_type_pushon;
		}
	}

	*screen_type = screen_type_forest;
}

static void setup()
{
	unsigned char row;
	unsigned char idx;

	row = 1;
	engine_content_manager_load_title( row );
	engine_text_manager_border();
	engine_text_manager_clear( row + 2, row + 9 );

	row = 5;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 2; idx++ )
	{
		engine_font_manager_text( ( unsigned char * ) forest_texts[ idx ], LEFT_X + 5, row++ );
	}

	row = 11;
	for( idx = 0; idx < 3; idx++ )
	{
		engine_font_manager_text( ( unsigned char * ) fight_texts[ idx ], LEFT_X + 5, row++ );
	}

	row = 12;
	engine_select_manager_load( select_type, LEFT_X + 3, row, 2 );

	engine_player_manager_draw();
	engine_enemy_manager_draw();

	engine_font_manager_text( LOCALE_FIGHT_MSG1, LEFT_X + 3, FIGHT_ROW + 3 );
	engine_font_manager_text( LOCALE_FIGHT_MSG2, LEFT_X + 17, FIGHT_ROW + 3 );

	engine_player_manager_hplo();
	engine_enemy_manager_hplo();
}

static bool calc_add_armor()
{
	struct_game_object *go = &global_game_object;
	struct_enemy_object *eo = &global_enemy_object;
	struct_player_object *po = &global_player_object;

	bool add_armor = true;
	if( diff_type_hard == go->difficulty )
	{
		if( po->level >= 2 )
		{
			// For weaker enemies on hard difficulty do not factor in armor.
			if( enemy_type_razboynik == eo->index || enemy_type_hungry_wolf == eo->index )
			{
				add_armor = false;
			}
		}
		if( add_armor )
		{
			add_armor = engine_random_manager_diff( po->level );
		}
	}

	return add_armor;
}