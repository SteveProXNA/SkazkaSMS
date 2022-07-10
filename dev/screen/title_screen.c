#include "title_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include <stdbool.h>
#include <stdlib.h>

#define TITLE_FLASH_DELAY	50
#define TITLE_SOUND_DELAY	50

static bool first_time;
static unsigned char event_stage;
static unsigned char flash_count;

void screen_title_screen_load()
{
	devkit_SMS_displayOff();

	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles();
	engine_content_manager_load_logo_big();

	engine_text_manager_clear( TOP_Y + 1, TOP_Y + 22 );
	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );

	engine_font_manager_draw_text( LOCALE_TITLE_MSG1, LEFT_X + 6, TOP_Y + 10 );
	engine_font_manager_draw_text( LOCALE_TITLE_MSG2, LEFT_X + 3, TOP_Y + 15 );
	engine_font_manager_draw_numb( 8, LEFT_X + 16, TOP_Y + 15 );

	engine_graphics_manager_draw_border();
	devkit_SMS_displayOn();

	engine_timer_manager_load( TITLE_FLASH_DELAY );
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
					input = engine_input_manager_hold( input_type_fire2 );
					if( input )
					{
						engine_input_manager_update();
						index = 5;
					}
				}
			}

			engine_text_manager_cont();
		}

		// Navigate to hidden credits screen.
		input = engine_input_manager_hold( input_type_fire2 );
		if( input )
		{
			*screen_type = screen_type_credit;
			return;
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
				engine_font_manager_draw_char( LOCALE_1_SPCS, LEFT_X + 15, TOP_Y + 21 );
			}
			else
			{
				engine_text_manager_one();
			}
		}

		input = engine_input_manager_hold( input_type_fire1 );
		if( input )
		{
			engine_text_manager_one();
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
