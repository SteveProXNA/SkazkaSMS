#include "game_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "player_manager.h"
#include "text_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	engine_game_manager_blue();

	engine_game_manager_intro_on();
	engine_game_manager_music_on();
	engine_game_manager_flash_on();

	engine_game_manager_difficulty( diff_type_easy );
}

void engine_game_manager_black()
{
	struct_game_object *go = &global_game_object;
	go->blue_screen = false;
}
void engine_game_manager_blue()
{
	struct_game_object *go = &global_game_object;
	go->blue_screen = true;
}

void engine_game_manager_intro_on()
{
	struct_game_object *go = &global_game_object;
	go->intro_once = true;
}
void engine_game_manager_intro_off()
{
	struct_game_object *go = &global_game_object;
	go->intro_once = false;
}

void engine_game_manager_music_on()
{
	struct_game_object *go = &global_game_object;
	go->play_music = true;
}
void engine_game_manager_music_off()
{
	struct_game_object *go = &global_game_object;
	go->play_music = false;
}

void engine_game_manager_flash_on()
{
	struct_game_object *go = &global_game_object;
	go->flash_arrow = true;
}
void engine_game_manager_flash_off()
{
	struct_game_object *go = &global_game_object;
	go->flash_arrow = false;
}

void engine_game_manager_difficulty( unsigned char difficulty )
{
	struct_game_object *go = &global_game_object;
	go->difficulty = difficulty;
}


// Common game rendering functions.
void engine_game_manager_print_stats()
{
	engine_player_manager_stats();
	engine_font_manager_text( LOCALE_STATISTICS, LEFT_X + 2, STATS_ROW + 2 );
	engine_font_manager_text( LOCALE_HP, LEFT_X + 2, STATS_ROW + 3 );
	engine_font_manager_text( LOCALE_XP, LEFT_X + 2, STATS_ROW + 4 );
	engine_font_manager_text( LOCALE_GOLD, LEFT_X + 2, STATS_ROW + 5 );
	engine_font_manager_text( LOCALE_YOU_HAVE, LEFT_X + 4, STATS_ROW + 6 );
	engine_font_manager_text( LOCALE_YOUR_LVL, LEFT_X + 2, 22 );
}

void engine_game_manager_print_village()
{
	unsigned char row = 2;
	engine_font_manager_text( LOCALE_OLD_VILLAGE, LEFT_X + 15, row + 2 );
	engine_text_manager_args( LEFT_X + 13, row + 5, 15, 0x20, 0x20, 0xE1, 0x20, 0xE4, 0xE9, 0xE9, 0x20, 0x20, 0x20, 0xE0, 0x20, 0x20, 0x20, 0xE8 );
	engine_text_manager_args( LEFT_X + 13, row + 6, 16, 0x95, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0x96, 0x20, 0x20, 0x95, 0xEF, 0x96, 0x20, 0xE8, 0x90, 0xE8 );
	engine_text_manager_args( LEFT_X + 13, row + 7, 16, 0xEF, 0xE5, 0xEF, 0xE5, 0xEF, 0xE5, 0xEF, 0x20, 0x20, 0xEF, 0xE5, 0xEF, 0x20, 0x90, 0x90, 0x90 );
	engine_text_manager_args( LEFT_X + 13, row + 8, 16, 0xEF, 0x92, 0xEF, 0x92, 0xEF, 0x92, 0xEF, 0x20, 0x20, 0xEF, 0x92, 0xEF, 0x20, 0x90, 0x90, 0x90 );
	engine_text_manager_args( LEFT_X + 13, row + 9, 16, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xFD, 0x20, 0xEF, 0xEF, 0xEF, 0xFD, 0x20, 0xE6, 0x20 );
}

void engine_game_manager_print_player()
{
	unsigned char row = 2;
	engine_text_manager_args( LEFT_X + 2, row + 11, 5, 0x20, 0x20, 0x8A, 0x81, 0x8C );
	engine_text_manager_args( LEFT_X + 2, row + 12, 5, 0x20, 0x20, 0x80, 0x20, 0x80 );
	engine_text_manager_args( LEFT_X + 2, row + 13, 5, 0x8E, 0x20, 0x8B, 0x83, 0x8D );
	engine_text_manager_args( LEFT_X + 2, row + 14, 8, 0x80, 0x20, 0x86, 0x82, 0x88, 0x8A, 0x81, 0x8C );
	engine_text_manager_args( LEFT_X + 2, row + 15, 8, 0xF8, 0x81, 0x84, 0x20, 0x85, 0x84, 0x20, 0x80 );
	engine_text_manager_args( LEFT_X + 2, row + 16, 8, 0x20, 0x20, 0x87, 0x83, 0x89, 0x8B, 0x81, 0x8D );
	engine_text_manager_args( LEFT_X + 2, row + 17, 5, 0x20, 0x20, 0x93, 0x20, 0x94 );
	engine_text_manager_args( LEFT_X + 2, row + 18, 6, 0x20, 0x93, 0x20, 0x20, 0x20, 0x94 );
}

void engine_game_manager_print_version()
{
	engine_font_manager_text( LOCALE_BUILD_VER, LEFT_X + 27, FIRE1_ROW );
}

void engine_game_manager_print_texts()
{
	unsigned char row = 13;
	unsigned char idx;

	devkit_SMS_mapROMBank( FIXED_BANK );
	for( idx = 0; idx < 8; idx++ )
	{
		engine_font_manager_text( ( unsigned char * ) stats_texts[ idx ], LEFT_X + 12, row++ );
	}
}

