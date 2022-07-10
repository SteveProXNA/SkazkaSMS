#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <stdbool.h>

typedef struct tag_struct_game_object
{
	bool intro_once;
	bool play_music;
	bool flash_arrow;
	unsigned char difficulty;

} struct_game_object;

#endif//_GAME_OBJECT_H_