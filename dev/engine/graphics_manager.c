#include "graphics_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"
#include "../banks/bank2.h"
#include "../banks/bank3.h"

void engine_graphics_manager_draw_border()
{
	engine_graphics_manager_draw_borderX( 0, 0, OUTER_WIDE, OUTER_HIGH );
	engine_graphics_manager_draw_borderX( LEFT_X, TOP_Y, INNER_WIDE, INNER_HIGH );
}

void engine_graphics_manager_draw_borderX( unsigned char top, unsigned char left, unsigned char wide, unsigned char high )
{
	const unsigned char *pnt = border__tilemap__bin;
	unsigned char idx;

	devkit_SMS_setNextTileatXY( left, top ); devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( wide - 1, top ); devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( left, high - 1 ); devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( wide - 1, high - 1 ); devkit_SMS_setTile( *pnt + 0 );

	// Vertical.
	for( idx = top + 1; idx <= high - 2; idx++ )
	{
		devkit_SMS_setNextTileatXY( left, idx ); devkit_SMS_setTile( *pnt + 1 );
		devkit_SMS_setNextTileatXY( wide - 1, idx ); devkit_SMS_setTile( *pnt + 1 );
	}
	// Horizontal.
	for( idx = left + 1; idx <= wide - 2; idx++ )
	{
		devkit_SMS_setNextTileatXY( idx, top ); devkit_SMS_setTile( *pnt + 2 );
		devkit_SMS_setNextTileatXY( idx, high - 1 ); devkit_SMS_setTile( *pnt + 2 );
	}
}

void engine_graphics_manager_draw_underline( unsigned char y )
{
	const unsigned char *pnt = border__tilemap__bin;
	unsigned char idx;

	devkit_SMS_setNextTileatXY( LEFT_X, y ); devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( INNER_WIDE - 1, y ); devkit_SMS_setTile( *pnt + 0 );

	// Horizontal.
	for( idx = LEFT_X + 1; idx <= INNER_WIDE - 2; idx++ )
	{
		devkit_SMS_setNextTileatXY( idx, y ); devkit_SMS_setTile( *pnt + 2 );
	}
}

void engine_graphics_manager_draw_splash()
{
	unsigned char x, y;
	unsigned int index = 0;
	unsigned int value = 0;
	unsigned int tile = 0;
	unsigned char i, j;

	x = 0;
	y = 0;
	for( j = 0; j < OUTER_HIGH - 2; j++ )
	{
		for( i = 0; i < OUTER_WIDE; i++ )
		{
			index = j * OUTER_WIDE + i;
			value = index * 2;
			tile = splash__tilemap__bin[ value ];
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( tile );
		}
	}
}

void engine_graphics_manager_draw_splash2( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = logo_new__tilemap__bin;
	unsigned char wide;
	unsigned char high;
	unsigned char i, j;
	unsigned char idx = 0;
	unsigned int tile;
	unsigned int palette;

	palette = devkit_TILE_USE_SPRITE_PALETTE();
	wide = 28;
	high = 5;
	j = 0;
	i = 0;
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

void engine_graphics_manager_draw_logo_big( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = logo_big__tilemap__bin;
	unsigned char wide = 28;
	unsigned char high = 5;
	unsigned char i, j;

	unsigned int tile = 0;
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

void engine_graphics_manager_draw_logo_small( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = logo_small__tilemap__bin;
	unsigned char wide = 30;
	unsigned char high = 3;
	unsigned char i, j;

	unsigned int tile = 0;
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

void engine_graphics_manager_draw_village( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = stats_village__tilemap__bin;
	unsigned char wide = 18;
	unsigned char high = 7;
	unsigned char i, j;
	unsigned char idx = 0;

	unsigned int palette = devkit_TILE_USE_SPRITE_PALETTE();
	unsigned int tile;
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

void engine_graphics_manager_draw_koschey( unsigned char x, unsigned char y, unsigned int palette )
{
	const unsigned char *pnt = koschey__tilemap__bin;
	unsigned char wide = 12;
	unsigned char high = 15;
	unsigned char i, j;
	unsigned char idx = 0;

	unsigned int tile = 0;
	for( j = 0; j < high; j++ )
	{
		for( i = 0; i < wide; i++ )
		{
			tile = ( SPRITE_TILES + idx) | palette;
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + tile );
			idx++;
		}
	}
}

void engine_graphics_manager_draw_leshy( unsigned char x, unsigned char y )
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