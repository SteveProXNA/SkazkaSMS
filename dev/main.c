#include "main.h"

void main( void )
{
	// Global variables.
	static bool global_pause;
	unsigned char open_screen_type;

	devkit_SMS_init();
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();

	devkit_SMS_useFirstHalfTilesforSprites( false );

	open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_title;

	// Initialize player first!
	engine_player_manager_init();
	engine_hack_manager_init();
	engine_hack_manager_load();
	engine_hack_manager_invert();

	engine_enemy_manager_init();
	engine_game_manager_init();
	engine_sound_manager_init();

	engine_select_manager_init();
	engine_screen_manager_init( open_screen_type );
	engine_content_manager_load_tiles();

	devkit_SMS_displayOn();
	for( ;; )
	{
		if( devkit_SMS_queryPauseRequested() )
		{
			devkit_SMS_resetPauseRequest();
			global_pause = !global_pause;
			if( global_pause )
			{
				devkit_PSGSilenceChannels();
			}
			else
			{
					devkit_PSGRestoreVolumes();
			}
		}

		if( global_pause )
		{
			continue;
		}

		engine_input_manager_update();
		engine_screen_manager_update();

		devkit_SMS_waitForVBlank();
		devkit_PSGFrame();
		devkit_PSGSFXFrame();
	}
}
