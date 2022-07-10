#include "victory_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/player_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/fixedbank.h"

void screen_victory_screen_load()
{
	struct_player_object *po = &global_player_object;
	unsigned char row;
	unsigned char idx;

	devkit_SMS_displayOff();
	engine_content_manager_load_logo_small();
	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );

	engine_text_manager_clear( TOP_Y + 5, TOP_Y + 22 );

	row = 9;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 4; idx++ )
	{
		engine_font_manager_draw_text( ( unsigned char * ) gold_texts[ idx ], LEFT_X + 7, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 19, TOP_Y + 9 );
	engine_font_manager_draw_punc( LOCALE_HYPHEN, LEFT_X + 20, TOP_Y + 12 );
	engine_font_manager_draw_data( po->won, LEFT_X + 24, TOP_Y + 12 );

	engine_graphics_manager_draw_border();
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	engine_text_manager_cont();
	devkit_SMS_displayOn();

	engine_sound_manager_play( sound_type_7 );
}

void screen_victory_screen_update( unsigned char *screen_type )
{
	unsigned char input1 = engine_input_manager_hold( input_type_fire1 );
	unsigned char input2 = engine_input_manager_hold( input_type_fire2 );

	if( input1 || input2 )
	{
		if( !devkit_PSGSFXGetStatus() )
		{
			*screen_type = screen_type_stats;
			return;
		}
	}

	*screen_type = screen_type_victory;
}
