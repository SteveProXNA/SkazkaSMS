#include "over_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"

#define OVER_SCREEN_DELAY		200

static bool first_time;

void screen_over_screen_load()
{
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
		engine_font_manager_draw_text( ( unsigned char * ) over_texts[ idx ], LEFT_X + 9, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 21, TOP_Y + 9 );

	engine_graphics_manager_draw_border();
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	engine_text_manager_cont();
	devkit_SMS_displayOn();

	engine_timer_manager_load( OVER_SCREEN_DELAY );
	first_time = true;
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;
	unsigned char index;

	if( first_time )
	{
		first_time = false;
		engine_game_manager_intro_off();
		engine_game_manager_music_off();

		// Play over music.
		engine_sound_manager_init();
		for( index = 8; index < 10; index++ )
		{
			engine_music_manager_play( index );
			engine_input_manager_update();

			input1 = engine_input_manager_move( input_type_fire1 );
			input2 = engine_input_manager_move( input_type_fire2 );
			if( input1 || input2 )
			{
				*screen_type = screen_type_title;
				return;
			}
		}
	}

	input1 = engine_input_manager_hold( input_type_fire1 );
	input2 = engine_input_manager_hold( input_type_fire2 );
	timer = engine_timer_manager_update();
	if( input1 || input2 || timer )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_over;
}
