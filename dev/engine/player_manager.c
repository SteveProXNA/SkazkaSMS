#include "player_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "text_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"

// Global variable.
struct_player_object global_player_object;

void engine_player_manager_init()
{
	struct_player_object *po = &global_player_object;
	po->def_xp = 0;							// Z
	po->def_hp = 10;						// N
	po->def_gold = 10;						// V
	po->def_weapon = weapon_type_dagger;	// Q$	ATK
	po->def_armor = armor_type_none;		// W$	ARM
	po->def_life = life_type_none;			// E$	UP
}

void engine_player_manager_load()
{
	struct_player_object *po = &global_player_object;
	po->xp = po->def_xp;					// Z
	po->hp = po->def_hp;					// N
	po->gold = po->def_gold;				// V
	po->weapon = po->def_weapon;			// Q$	ATK
	po->armor = po->def_armor;				// W$	ARM
	po->life = po->def_life;				// E$	UP
}

void engine_player_manager_calc()
{
	struct_player_object *po = &global_player_object;
	if( po->xp > 34 && po->xp <= 60 )
	{
		po->level = 3;						// X
		po->max_hp = 30;					// M
		po->max_xp = 60;					// Y
	}
	else if( po->xp > 11 && po->xp <= 34 )
	{
		po->level = 2;						// X
		po->max_hp = 20;					// M
		po->max_xp = 34;					// Y
	}
	else if( po->xp > 60  )
	{
		po->level = 3;						// X
		po->max_hp = 30;					// M
		po->max_xp = 99;					// Y
	}
	else if( po->xp <= 11 )
	{
		po->level = 1;						// X
		po->max_hp = 10;					// M
		po->max_xp = 11;					// Y
	}
}

void engine_player_manager_stats()
{
	struct_player_object *po = &global_player_object;

	// Print HP, XP, gold, level.
	engine_font_manager_draw_numb( po->level, LEFT_X + 9, TOP_Y + 6 );

	engine_font_manager_draw_data( po->max_hp, LEFT_X + 9, TOP_Y + 7 );
	engine_font_manager_draw_punc( LOCALE_SLASH, LEFT_X + 7, TOP_Y + 7 );
	engine_font_manager_draw_data( po->hp, LEFT_X + 6, TOP_Y + 7 );

	engine_font_manager_draw_data( po->max_xp, LEFT_X + 9, TOP_Y + 8 );
	engine_font_manager_draw_punc( LOCALE_SLASH, LEFT_X + 7, TOP_Y + 8 );
	engine_font_manager_draw_data( po->xp, LEFT_X + 6, TOP_Y + 8 );

	engine_font_manager_draw_data( po->gold, LEFT_X + 9, TOP_Y + 9 );
	

	// Print inventory.
	devkit_SMS_mapROMBank( FIXED_BANK );
	engine_font_manager_draw_text( ( unsigned char * ) weapon_texts[ po->weapon ], LEFT_X + 2, TOP_Y + 11 );
	engine_font_manager_draw_text( ( unsigned char * ) armor_texts[ po->armor ], LEFT_X + 2, TOP_Y + 12 );
	if( po->life )
	{
		engine_font_manager_draw_punc( LOCALE_PLUS, LEFT_X + 2, TOP_Y + 13 );
		engine_font_manager_draw_numb( 1, LEFT_X + 3, TOP_Y + 13 );
		engine_font_manager_draw_text( ( unsigned char * ) life_texts[ po->life ], LEFT_X + 5, TOP_Y + 13 );
	}

	if( po->xp > 60 )
	{
		engine_font_manager_draw_text( LOCALE_HERO, LEFT_X + 7, TOP_Y + 20 );
	}
}

void engine_player_manager_rest()
{
	struct_player_object *po = &global_player_object;
	po->hp = po->max_hp;
}

void engine_player_manager_draw_inventory( unsigned char x, unsigned char y )
{
	const unsigned char *pnt1 = stats_items__tilemap__bin;
	const unsigned char *pnt2 = stats_inventory__tilemap__bin;

	struct_player_object *po = &global_player_object;
	unsigned char delta = 2;
	unsigned char size = delta * delta;

	unsigned char wide = 8;
	unsigned char high = 8;
	unsigned char i, j;

	unsigned int tile = 0;
	for( j = 0; j < high; j++ )
	{
		for( i = 0; i < wide; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt1 + tile );
			tile++;
		}
	}

	tile = po->weapon * size;
	for( j = 0; j < delta; j++ )
	{
		for( i = 0; i < delta; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j + 1 );
			devkit_SMS_setTile( *pnt2 + tile );
			tile++;
		}
	}
	if( po->armor )
	{
		tile = 2 * size + po->armor * size;
		for( j = 0; j < delta; j++ )
		{
			for( i = 0; i < delta; i++ )
			{
				devkit_SMS_setNextTileatXY( x + i + 6, y + j + 3 );
				devkit_SMS_setTile( *pnt2 + tile );
				tile++;
			}
		}
	}
	if( po->life )
	{
		tile = 4 * size + po->life * size;
		for( j = 0; j < 2; j++ )
		{
			for( i = 0; i < 2; i++ )
			{
				devkit_SMS_setNextTileatXY( x + i + 1, y + j + 6 );
				devkit_SMS_setTile( *pnt2 + tile );
				tile++;
			}
		}
	}
}

void engine_player_manager_hplo()
{
	struct_player_object *po = &global_player_object;
	engine_font_manager_draw_data( po->hp, LEFT_X + 13, TOP_Y + 21 );
}

void engine_player_manager_draw( unsigned char x, unsigned char y )
{
	struct_player_object *po = &global_player_object;
	const unsigned char wide = 3;
	const unsigned char high = 4;

	const unsigned char start = ( po->armor * 36 ) + ( po->weapon * 3 );
	unsigned char index = 0;
	unsigned char value = 0;
	unsigned int tile = 0;
	unsigned char i, j;

	for( j = 0; j < high; j++ )
	{
		for( i = 0; i < wide; i++ )
		{
			index = ( j * 9 ) + i + start;
			value = index * 2;
			tile = battle_player__tilemap__bin[ value ];
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( tile );
		}
	}
}

void engine_player_manager_dec_gold( unsigned char gold )
{
	struct_player_object *po = &global_player_object;
	if( po->gold > gold )
	{
		po->gold -= gold;
	}
	else
	{
		po->gold = 0;
	}
}

void engine_player_manager_inc_gold( unsigned char xp, unsigned char gold )
{
	struct_player_object *po = &global_player_object;
	po->won = gold;

	po->xp += xp;
	if( po->xp >= MAX_XP )
	{
		po->xp = MAX_XP;
	}

	po->gold += gold;
	if( po->gold >= MAX_GOLD )
	{
		po->gold = MAX_GOLD;
	}
}

void engine_player_manager_hit( char hp )
{
	struct_player_object *po = &global_player_object;
	if( po->hp > hp )
	{
		po->hp -= hp;
	}
	else
	{
		po->hp = 0;
	}
}

void engine_player_manager_armor( unsigned char armor )
{
	struct_player_object *po = &global_player_object;
	po->hp += armor;
}

bool engine_player_manager_dead()
{
	struct_player_object *po = &global_player_object;
	return po->hp <= 0;
}

bool engine_player_manager_life()
{
	struct_player_object *po = &global_player_object;
	return life_type_oneup == po->life;
}

void engine_player_manager_def_currxp( unsigned currxp )
{
	struct_player_object *po = &global_player_object;
	po->def_xp = currxp;
}
void engine_player_manager_def_currhp( unsigned currhp )
{
	struct_player_object *po = &global_player_object;
	po->def_hp = currhp;
}
void engine_player_manager_def_goldno( unsigned goldno )
{
	struct_player_object *po = &global_player_object;
	po->def_gold = goldno;
}
void engine_player_manager_def_weapon( unsigned weapon )
{
	struct_player_object *po = &global_player_object;
	po->def_weapon = weapon;
}
void engine_player_manager_def_armors( unsigned armors )
{
	struct_player_object *po = &global_player_object;
	po->def_armor = armors;
}
void engine_player_manager_def_oneups( unsigned oneups )
{
	struct_player_object *po = &global_player_object;
	po->def_life = oneups;
}

void engine_player_manager_set_weapon( unsigned weapon )
{
	struct_player_object *po = &global_player_object;
	po->weapon = weapon;
}
void engine_player_manager_set_armors( unsigned armors )
{
	struct_player_object *po = &global_player_object;
	po->armor = armors;
}
void engine_player_manager_set_oneups( unsigned oneups )
{
	struct_player_object *po = &global_player_object;
	po->life = oneups;
}
