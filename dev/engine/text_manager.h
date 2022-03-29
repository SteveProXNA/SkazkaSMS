#ifndef _TEXT_MANAGER_H_
#define _TEXT_MANAGER_H_

void engine_text_manager_clear( unsigned char start, unsigned char stop );
void engine_text_manager_border();
void engine_text_manager_title( unsigned char row );
void engine_text_manager_fire();
void engine_text_manager_diff();
void engine_text_manager_args( unsigned char x, unsigned char y, unsigned char num, ... );

#endif//_TEXT_MANAGER_H_