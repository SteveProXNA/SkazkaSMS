#include "relive_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/player_manager.h"
#include "../engine/text_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"

#define RELIVE_SCREEN_DELAY		30
#define RELIVE_ROW				12

static unsigned char count;

void screen_relive_screen_load()
{
	unsigned char row = 1;

	devkit_SMS_displayOff();
	engine_content_manager_load_title( row );
	engine_text_manager_clear( row + 2, row + 9 );
	engine_text_manager_border();

	engine_font_manager_text( LOCALE_REVITALISING, LEFT_X + 9, RELIVE_ROW );
	devkit_SMS_displayOn();

	engine_timer_manager_load( RELIVE_SCREEN_DELAY );
	count = 0;
}

void screen_relive_screen_update( unsigned char *screen_type )
{
	unsigned char timer;

	timer = engine_timer_manager_update();
	if( timer )
	{
		engine_timer_manager_load( RELIVE_SCREEN_DELAY );
		if( count == 0 || count == 2 )
		{
			engine_sound_manager_play( sound_type_9 );
		}

		if( count != 3 )
		{
			engine_font_manager_text( LOCALE_DOT, LEFT_X + 21 + count, RELIVE_ROW );
		}

		count++;
		if( count > 3 )
		{
			// Replenish HP and remove +1.
			engine_player_manager_rest();
			engine_player_manager_set_oneups( life_type_none );
			*screen_type = screen_type_stats;
			return;
		}
		
	}

	*screen_type = screen_type_relive;
}
