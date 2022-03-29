#include "over_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include <stdbool.h>

#define OVER_SCREEN_DELAY		200

static void game_over();
static bool first_time;

void screen_over_screen_load()
{
	unsigned char row = 1;

	devkit_SMS_displayOff();
	engine_content_manager_load_title( row );
	engine_text_manager_border();
	engine_text_manager_clear( row + 2, row + 9 );

	game_over();
	engine_text_manager_fire();
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

static void game_over()
{
	unsigned char row;
	unsigned char idx;

	row = 9;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 4; idx++ )
	{
		engine_font_manager_text( ( unsigned char * ) over_texts[ idx ], LEFT_X + 10, row++ );
	}
}
