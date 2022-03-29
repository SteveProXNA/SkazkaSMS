#include "start_screen.h"
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
#include "../banks/fixedbank.h"

#define START_FLASH_DELAY		50
#define START_FLASH_TOTAL		3
static unsigned char flash_index;
static unsigned char flash_count;

void screen_start_screen_load()
{
	unsigned char row = 1;

	devkit_SMS_displayOff();
	engine_content_manager_load_title( row );
	engine_text_manager_border();
	engine_text_manager_clear( row + 2, row + 9 );

	engine_game_manager_print_stats();
	engine_game_manager_print_village();
	engine_game_manager_print_player();
	engine_game_manager_print_version();
	engine_game_manager_print_texts();
	engine_text_manager_diff();

	engine_font_manager_text( LOCALE_ARROWS, LEFT_X + 10, OPTION_ROW );
	devkit_SMS_displayOn();

	engine_timer_manager_load( START_FLASH_DELAY );
	flash_index = 0;
	flash_count = 0;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char timer;
	unsigned char input1;
	unsigned char input2;
	unsigned char nextr;

	nextr = 0;
	timer = engine_timer_manager_update();
	if( timer )
	{
		if( !ho->hack_delays )
		{
			flash_count = 1 - flash_count;
		}

		if( flash_count )
		{
			engine_font_manager_text( LOCALE_2_SPCS, LEFT_X + 10, OPTION_ROW );
		}
		else
		{
			engine_font_manager_text( LOCALE_ARROWS, LEFT_X + 10, OPTION_ROW );
			flash_index++;

			if( flash_index >= START_FLASH_TOTAL )
			{
				nextr = 1;
			}
		}
	}

	input1 = engine_input_manager_move( input_type_left );
	input2 = engine_input_manager_move( input_type_right );
	if( !nextr )
	{
		nextr = input1 || input2;
	}

	if( nextr )
	{
		*screen_type = screen_type_stats;
		return;
	}

	*screen_type = screen_type_start;
}
