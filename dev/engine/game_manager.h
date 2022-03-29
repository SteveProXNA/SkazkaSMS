#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "../object/game_object.h"

// Global variable.
extern struct_game_object global_game_object;

void engine_game_manager_init();

void engine_game_manager_black();
void engine_game_manager_blue();

void engine_game_manager_intro_on();
void engine_game_manager_intro_off();
void engine_game_manager_music_on();
void engine_game_manager_music_off();

void engine_game_manager_flash_on();
void engine_game_manager_flash_off();

void engine_game_manager_difficulty( unsigned char difficulty );

void engine_game_manager_print_stats();
void engine_game_manager_print_village();
void engine_game_manager_print_player();
void engine_game_manager_print_version();
void engine_game_manager_print_texts();

#endif//_GAME_MANAGER_H_