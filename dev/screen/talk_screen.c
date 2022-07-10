#include "talk_screen.h"
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
#include "../engine/player_manager.h"
#include "../engine/select_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/fixedbank.h"
#include <stdlib.h>

#define MAX_CHAT	3
#define NUM_GOLD	5

static void display_msg();
static unsigned char prev_msg;

void screen_talk_screen_load()
{
	prev_msg = NO_SELECTION;

	devkit_SMS_displayOff();
	engine_content_manager_load_logo_small();
	engine_graphics_manager_draw_logo_small( LEFT_X + 1, TOP_Y + 1 );

	engine_text_manager_clear( TOP_Y + 10, TOP_Y + 22 );
	display_msg();

	engine_graphics_manager_draw_border();
	engine_graphics_manager_draw_underline( TOP_Y + 4 );

	engine_text_manager_cont();
	devkit_SMS_displayOn();
}

void screen_talk_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char input1;
	unsigned char input2;

	if( devkit_PSGSFXGetStatus() )
	{
		*screen_type = screen_type_talk;
		return;
	}

	input1 = engine_input_manager_hold( input_type_fire1 );
	if( input1 )
	{
		*screen_type = screen_type_stats;
		return;
	}

	input2 = engine_input_manager_hold( input_type_fire2 );
	if( input2 )
	{
		if( ho->hack_talker )
		{
			display_msg();
		}
		else
		{
			*screen_type = screen_type_stats;
			return;
		}
	}

	*screen_type = screen_type_talk;
}

static void display_msg()
{
	struct_player_object *po = &global_player_object;
	unsigned char row;
	unsigned char msg;
	unsigned char idx = 0;
	unsigned char beg = 0;
	unsigned char txt = 0;
	unsigned char max = MAX_RANDOM;

	// If no gold then can never issue "No gold chat"
	if( 0 == po->gold )
	{
		max = MAX_RANDOM - 1;
	}

	while( 1 )
	{
		msg = ( unsigned char ) ( rand() % max );
		if( msg != prev_msg )
		{
			prev_msg = msg;
			break;
		}
	}

	beg = msg * MAX_CHAT;
	row = 6;
	for( idx = 0; idx < MAX_CHAT + 1; idx++ )
	{
		engine_font_manager_draw_text( LOCALE_30_SPCS, LEFT_X + 1, TOP_Y + row );
		row++;
	}

	row = 7;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < MAX_CHAT; idx++ )
	{
		txt = beg + idx;
		engine_font_manager_draw_text( ( unsigned char * ) villager_texts[ txt ], LEFT_X + 2, TOP_Y + row );
		row++;
	}

	if( 0 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 24, TOP_Y + 7 );
		engine_sound_manager_play( sound_type_7 );
		engine_player_manager_inc_gold( 0, NUM_GOLD );
	}
	else if( 1 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 12, TOP_Y + 9 );
	}
	else if( 2 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_COMMA, LEFT_X + 20, TOP_Y + 8 );
		engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 27, TOP_Y + 9 );
	}
	else if( 3 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 10, TOP_Y + 9 );
	}
	else if( 4 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_QUOTE, LEFT_X + 15, TOP_Y + 7 );
	}
	else if( 6 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_QMARK, LEFT_X + 9, TOP_Y + 9 );
	}
	else if( 7 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_COMMA, LEFT_X + 26, TOP_Y + 8 );
		engine_font_manager_draw_punc( LOCALE_QUOTE, LEFT_X + 12, TOP_Y + 9 );
	}
	else if( 8 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_COMMA, LEFT_X + 8, TOP_Y + 7 );
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 15, TOP_Y + 7 );
	}
	else if( 9 == msg )
	{
		engine_font_manager_draw_punc( LOCALE_POINT, LEFT_X + 23, TOP_Y + 7 );
		engine_sound_manager_play( sound_type_6 );
		engine_player_manager_dec_gold( NUM_GOLD );
	}
}