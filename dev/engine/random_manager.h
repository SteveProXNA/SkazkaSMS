#ifndef _RANDOM_MANAGER_H_
#define _RANDOM_MANAGER_H_

#include <stdbool.h>

unsigned char engine_random_manager_next();
bool engine_random_manager_diff( unsigned char level );

#endif//_RANDOM_MANAGER_H_
