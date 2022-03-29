#include "content_manager.h"
#include "game_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"
#include "../banks/bank3.h"
#include <stdbool.h>

#define LOAD_TILES		0

void engine_content_manager_load_splash()
{
	// Splash tiles.
	devkit_SMS_mapROMBank( splash__tilemap__stmcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( ( unsigned char* ) splash__tiles__psgcompr, LOAD_TILES );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) splash__tilemap__stmcompr );
	devkit_SMS_loadBGPalette( ( void * ) splash__palette__bin );
}

void engine_content_manager_load_title( unsigned char y )
{
	// Title tiles.
	struct_game_object *go = &global_game_object;
	bool blue_screen = go->blue_screen;

	devkit_SMS_loadPSGaidencompressedTiles( ( unsigned char* ) font_tiles__tiles__psgcompr, LOAD_TILES );
	devkit_SMS_loadSTMcompressedTileMap( 0, y, ( void * ) font_tiles__tilemap__stmcompr );
	devkit_SMS_loadBGPalette( ( void * ) font_tiles__palette__bin );

	// Change on easter egg splash screen.
	if( blue_screen )
	{
		devkit_SMS_setBGPaletteColor( 0, devkit_RGB( 1, 0, 3 ) );
		devkit_SMS_setSpritePaletteColor( 0, devkit_RGB( 1, 0, 3 ) );
	}
}
