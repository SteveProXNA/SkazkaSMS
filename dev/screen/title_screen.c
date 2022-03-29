#include "title_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdbool.h>
#include <stdlib.h>

#define TITLE_FLASH_DELAY	50
#define TITLE_SOUND_DELAY	50

static bool first_time;
static unsigned char event_stage;
static unsigned char flash_count;

void screen_title_screen_load()
{
	unsigned char row = 1;
	engine_timer_manager_load( TITLE_FLASH_DELAY );

	devkit_SMS_displayOff();
	engine_content_manager_load_title( row );
	engine_text_manager_border();
	engine_text_manager_clear( row + 0, row + 9 );

	// SKAZKA.
	engine_text_manager_title( row + 2 );
	engine_font_manager_text( LOCALE_TITLE_MSG1, LEFT_X + 7, 12 );
	engine_font_manager_text( LOCALE_TITLE_MSG2, LEFT_X + 3, 17 );

	devkit_SMS_displayOn();
	first_time = true;
	event_stage = event_stage_start;
	flash_count = 0;
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	unsigned char input;
	unsigned char timer;
	unsigned char index;

	rand();
	if( event_stage_pause == event_stage )
	{
		timer = engine_timer_manager_update();
		if( timer )
		{
			*screen_type = screen_type_diff;
			return;
		}
	}
	else
	{
		if( first_time )
		{
			first_time = false;
			if( go->play_music )
			{
				// Play intro music.
				engine_sound_manager_init();
				for( index = 0; index < 5; index++ )
				{
					engine_music_manager_play( index );
					engine_input_manager_update();
					input = engine_input_manager_move( input_type_fire2 );
					if( input )
					{
						index = 5;
					}
				}
			}

			engine_text_manager_fire();
		}

		rand();
		timer = engine_timer_manager_update();
		if( timer )
		{
			if( !ho->hack_delays )
			{
				flash_count = 1 - flash_count;
			}

			if( flash_count )
			{
				engine_font_manager_text( LOCALE_6_SPCS, LEFT_X + 11, FIRE1_ROW );
			}
			else
			{
				engine_font_manager_text( LOCALE_FIRE1_WORD, LEFT_X + 11, FIRE1_ROW );
			}
		}

		input = engine_input_manager_hold( input_type_fire1 );
		if( input )
		{
			engine_font_manager_text( LOCALE_FIRE1_WORD, LEFT_X + 11, FIRE1_ROW );
			engine_timer_manager_load( TITLE_SOUND_DELAY );

			if( !ho->hack_delays )
			{
				engine_sound_manager_play( sound_type_5 );
			}

			event_stage = event_stage_pause;
		}

		rand();
	}

	*screen_type = screen_type_title;
}
