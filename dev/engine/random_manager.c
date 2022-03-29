#include "random_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include <stdlib.h>

unsigned char engine_random_manager_next()
{
	return rand() % MAX_RANDOM;
}

bool engine_random_manager_diff( unsigned char level )
{
	unsigned char value = rand() % HLF_RANDOM;
	return level <= value;
}