#include "complete_screen.h"
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
#include "../devkit/_snd_manager.h"
#include "../banks/fixedbank.h"

#define BEAT_SCREEN_DELAY	900
static void beat_game();

void screen_complete_screen_load()
{
	unsigned char row = 1;

	devkit_SMS_displayOff();
	engine_content_manager_load_title( row );
	engine_text_manager_border();
	engine_text_manager_clear( row + 2, row + 9 );

	beat_game();

	engine_text_manager_fire();
	devkit_SMS_displayOn();

	engine_timer_manager_load( BEAT_SCREEN_DELAY );
	engine_music_manager_beat();
}

void screen_complete_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	input1 = engine_input_manager_hold( input_type_fire1 );
	input2 = engine_input_manager_hold( input_type_fire2 );
	timer = engine_timer_manager_update();

	if( input1 || input2 || timer )
	{
		devkit_PSGStop();
		engine_game_manager_intro_off();
		engine_game_manager_music_off();
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_complete;
}

static void beat_game()
{
	unsigned char row;
	unsigned char idx;

	row = 7;
	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 11; idx++ )
	{
		engine_font_manager_text( ( unsigned char * ) beat_texts[ idx ], LEFT_X + 3, row++ );
	}
}