#include "diff_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/select_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include <stdlib.h>

#define DIFFICULTY_ROW		17
#define DIFF_SOUND_DELAY	50

static unsigned char event_stage;
static unsigned char select_type;

void screen_diff_screen_load()
{
	select_type = select_type_diff;

	devkit_SMS_displayOff();
	engine_text_manager_clear( TOP_Y + 8, TOP_Y + 22 );
	engine_content_manager_load_logo_big();
	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );

	devkit_SMS_mapROMBank( FIXED_BANK );
	engine_font_manager_draw_text( ( unsigned char * ) diff_texts[ 0 ], LEFT_X + 14, TOP_Y + DIFFICULTY_ROW + 0 );
	engine_font_manager_draw_text( ( unsigned char * ) diff_texts[ 1 ], LEFT_X + 14, TOP_Y + DIFFICULTY_ROW + 1 );

	engine_font_manager_draw_text( LOCALE_DIFFICULTY, LEFT_X + 7, TOP_Y + 12 );
	engine_graphics_manager_draw_border();

	engine_select_manager_load( select_type, LEFT_X + 12, TOP_Y + DIFFICULTY_ROW, 2 );
	devkit_SMS_displayOn();

	engine_timer_manager_load( DIFF_SOUND_DELAY );
	event_stage = event_stage_start;
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

	unsigned char selection;
	unsigned char timer;

	rand();
	if( event_stage_pause == event_stage )
	{
		timer = engine_timer_manager_update();
		if( timer )
		{
			if( go->intro_once )
			{
				engine_game_manager_intro_off();
				*screen_type = screen_type_intro;
				return;
			}
			else
			{
				*screen_type = screen_type_load;
				return;
			}
		}
	}
	else
	{
		selection = engine_select_manager_update( select_type );
		if( NO_SELECTION == selection )
		{
			*screen_type = screen_type_diff;
			return;
		}

		// Set difficulty.
		engine_game_manager_difficulty( selection );

		event_stage = event_stage_pause;
		if( !ho->hack_delays )
		{
			engine_sound_manager_play( sound_type_5 );
		}
	}
}
