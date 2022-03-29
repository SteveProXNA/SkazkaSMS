#include "func_screen.h"
#include "../engine/enemy_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/fight_manager.h"
#include "../engine/player_manager.h"
#include "../engine/random_manager.h"

static void player();
static void enemy( unsigned char index );

static unsigned char enemys_damage;
static unsigned char player_damage;

void screen_func_screen_load()
{
	unsigned char random;
	unsigned char index;
	engine_font_manager_text( "FUNC SCREEN...!!", 2, 0 );

	player();
	for( index = 0; index < 6; index++ )
	{
		engine_target_manager_load( index );
		enemy( index );
	}


	// Forest screen.
	engine_target_manager_load( 2 );
	random = engine_random_manager_next();
	engine_fight_manager_player_to_enemy( &enemys_damage, random );

	random = engine_random_manager_next();
	engine_fight_manager_enemy_to_player( &player_damage, random );


	// Boss screen.
	engine_target_manager_load( 5 );
	random = engine_random_manager_next();
	engine_fight_manager_player_to_boss( &enemys_damage, random, weapon_type_axe );

	random = engine_random_manager_next();
	engine_fight_manager_boss_to_player( &player_damage, random );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}

static void player()
{
	struct_player_object *po = &global_player_object;
	po->weapon = 1;
	engine_font_manager_data( po->hp, 5, 2 );
	engine_font_manager_data( po->xp, 10, 2 );
	engine_font_manager_data( po->weapon, 15, 2 );
	engine_font_manager_data( po->armor, 20, 2 );
}
static void enemy( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_object;
	engine_font_manager_data( eo->index, 5, index + 4 );
	engine_font_manager_data( eo->hplo, 10, index + 4 );
	engine_font_manager_data( eo->ax, 15, index + 4 );
	engine_font_manager_data( eo->gldo, 20, index + 4 );
	engine_font_manager_data( eo->xpo, 25, index + 4 );
}