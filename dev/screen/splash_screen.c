#include "splash_screen.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/game_manager.h"
#include "../engine/input_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdbool.h>

#define SPLASH_SCREEN_DELAY		150
static bool first_time;

void screen_splash_screen_load()
{
	engine_timer_manager_load( SPLASH_SCREEN_DELAY );

	devkit_SMS_displayOff();
	engine_content_manager_load_splash();
	devkit_SMS_displayOn();

	first_time = true;
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char input2;
	unsigned char timer;

	if( first_time )
	{
		input1 = engine_input_manager_move( input_type_down );
		input2 = engine_input_manager_move( input_type_fire2 );
		if( input1 && input2 )
		{
			engine_game_manager_black();
		}
	}
	
	input1 = engine_input_manager_hold( input_type_fire1 );
	timer = engine_timer_manager_update();

	if( input1 || timer )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_splash;
}
