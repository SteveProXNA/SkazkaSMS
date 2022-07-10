#include "enemy_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "text_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"
#include <stdlib.h>

// Global variable.
struct_enemy_object global_enemy_object;

unsigned char hplo_num[ MAX_ENEMIES ] =	{ 10, 10, 25, 25, 35, 50 };
unsigned char ax_num[ MAX_ENEMIES ] =	{  1,  1,  2,  2,  3,  4 };
unsigned char gldo_num[ MAX_ENEMIES ] = {  5,  5, 10, 10, 15,  0 };
unsigned char xpo_num[ MAX_ENEMIES ] =	{  2,  2,  4,  4, 10,  0 };

static void draw_enemy( unsigned char idx, unsigned char x, unsigned char y );
static void draw_leshy( unsigned char x, unsigned char y );

void engine_enemy_manager_init()
{
	struct_enemy_object *eo = &global_enemy_object;
	eo->index = 0;
	eo->hplo = 0;
	eo->ax = 0;
	eo->gldo = 0;
	eo->xpo = 0;
}

void engine_enemy_manager_load( unsigned char level )
{
	unsigned char value = rand() % MAX_RANDOM;
	unsigned char index = 0;

	switch( level )
	{
	case 1:
		index = value < 5 ? enemy_type_razboynik : enemy_type_hungry_wolf;
		break;
	case 2:
		if( value < 3 )
		{
			index = enemy_type_razboynik;
		}
		else if( value < 6 )
		{
			index = enemy_type_kikimora;
		}
		else if( value < 8 )
		{
			index = enemy_type_hungry_wolf;
		}
		else
		{
			index = enemy_type_leshy;
		}
		break;
	case 3:
		if( value < 1 )
		{
			index = enemy_type_razboynik;
		}
		else if( value < 2 )
		{
			index = enemy_type_hungry_wolf;
		}
		else if( value < 5 )
		{
			index = enemy_type_kikimora;
		}
		else if( value < 8 )
		{
			index = enemy_type_leshy;
		}
		else
		{
			index = enemy_type_baby_yaga;
		}
		break;
	}

	engine_target_manager_load( index );
}

void engine_target_manager_load( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_object;
	eo->index = index;
	eo->hplo = hplo_num[ index ];
	eo->ax = ax_num[ index ];
	eo->gldo = gldo_num[ index ];
	eo->xpo = xpo_num[ index ];
}

void engine_enemy_manager_draw( unsigned char x, unsigned char y )
{
	struct_enemy_object *eo = &global_enemy_object;
	if( enemy_type_leshy != eo->index )
	{
		draw_enemy( eo->index, x, y );
	}
	else
	{
		draw_leshy( x, y );
	}
}

static void draw_enemy( unsigned char idx, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = battle_enemies__tilemap__bin;

	unsigned char wide = 3;
	unsigned char high = 4;
	unsigned char i, j;

	unsigned int tile = idx * ( wide * high );
	for( j = 0; j < high; j++ )
	{
		for( i = 0; i < wide; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + tile );
			tile++;
		}
	}
}
static void draw_leshy( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = battle_enemies_leshy__tilemap__bin;

	unsigned char wide = 3;
	unsigned char high = 4;
	unsigned char i, j;
	unsigned char idx = 0;

	unsigned int tile = 0;
	unsigned int palette = devkit_TILE_USE_SPRITE_PALETTE();
	for( j = 0; j < high; j++ )
	{
		for( i = 0; i < wide; i++ )
		{
			tile = ( SPRITE_TILES + idx ) | palette;
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + tile );
			idx++;
		}
	}
}

void engine_enemy_manager_text()
{
	struct_enemy_object *eo = &global_enemy_object;
	engine_font_manager_draw_text( ( unsigned char * ) enemy_texts[ eo->index ], LEFT_X + 16, TOP_Y + 9 );
}

void engine_enemy_manager_hplo()
{
	struct_enemy_object *eo = &global_enemy_object;
	engine_font_manager_draw_data( eo->hplo, LEFT_X + 29, TOP_Y + 21 );
}

void engine_enemy_manager_hit( char hp )
{
	struct_enemy_object *eo = &global_enemy_object;
	if( eo->hplo > hp )
	{
		eo->hplo -= hp;
	}
	else
	{
		eo->hplo = 0;
	}
}

bool engine_enemy_manager_dead()
{
	struct_enemy_object *eo = &global_enemy_object;
	return eo->hplo <= 0;
}
