#include "credit_screen.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"

#define CREDIT_SCREEN_DELAY		500
static void display();

void screen_credit_screen_load()
{
	devkit_SMS_displayOff();
	engine_text_manager_clear( TOP_Y + 8, TOP_Y + 22 );
	engine_content_manager_load_logo_big();
	engine_graphics_manager_draw_logo_big( LEFT_X + 2, TOP_Y + 3 );

	engine_font_manager_draw_text( LOCALE_CREDITS, LEFT_X + 12, TOP_Y + 10 );
	display();

	engine_graphics_manager_draw_border();
	engine_text_manager_cont();
	devkit_SMS_displayOn();
	engine_timer_manager_load( CREDIT_SCREEN_DELAY );
}

void screen_credit_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	input1 = engine_input_manager_hold( input_type_fire1 );
	input2 = engine_input_manager_hold( input_type_fire2 );
	timer = engine_timer_manager_update();
	if( input1 || input2 || timer )
	{
		engine_game_manager_music_off();
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_credit;
}

static void display()
{
	unsigned char row;
	unsigned char idx;

	unsigned char x1;
	unsigned char x2;

	x1 = 4;
	x2 = 4 + 12 + 4;

	row = 13;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 12; idx += 2 )
	{
		engine_font_manager_draw_text( ( unsigned char * ) credit_texts[ idx + 0 ], LEFT_X + x1, TOP_Y + row );
		engine_font_manager_draw_text( ( unsigned char * ) credit_texts[ idx + 1 ], LEFT_X + x2, TOP_Y + row );
		row++;
	}

	engine_font_manager_draw_numb( 2, LEFT_X + 28, TOP_Y + 22 );
	engine_font_manager_draw_punc( LOCALE_STOP, LEFT_X + 29, TOP_Y + 22 );
	engine_font_manager_draw_numb( 0, LEFT_X + 30, TOP_Y + 22 );
}