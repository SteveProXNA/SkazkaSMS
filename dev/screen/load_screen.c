#include "load_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/game_manager.h"
#include "../engine/player_manager.h"
#include "../engine/select_manager.h"

void screen_load_screen_load()
{
	engine_player_manager_load();
	engine_player_manager_calc();

	engine_select_manager_once();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	bool flash_arrow = go->flash_arrow;

	if( flash_arrow )
	{
		*screen_type = screen_type_start;
		return;
	}

	*screen_type = screen_type_stats;
}
