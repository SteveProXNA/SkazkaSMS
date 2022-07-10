#include "prep_screen.h"
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

static unsigned char select_type;

void screen_prep_screen_load()
{
	unsigned char row;
	unsigned char idx;

	select_type = select_type_prep;

	devkit_SMS_displayOff();
	engine_content_manager_load_logo_small();
	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );

	engine_text_manager_clear( TOP_Y + 5, TOP_Y + 22 );

	row = 7;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 9; idx++ )
	{
		engine_font_manager_draw_text( ( unsigned char * ) prep_texts[ idx ], LEFT_X + 3, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 22, TOP_Y + 8 );
	engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 28, TOP_Y + 11 );

	engine_graphics_manager_draw_border();
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	engine_select_manager_load( select_type, LEFT_X + 13, TOP_Y + 14, 2 );
	devkit_SMS_displayOn();
}

void screen_prep_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char selection;

	input = engine_input_manager_hold( input_type_fire2 );
	if( input )
	{
		*screen_type = screen_type_stats;
		return;
	}

	selection = engine_select_manager_update( select_type );
	if( NO_SELECTION == selection )
	{
		*screen_type = screen_type_prep;
		return;
	}

	*screen_type = binary_type_no == selection ? screen_type_stats : screen_type_boss;
}
