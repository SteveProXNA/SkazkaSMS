#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

void engine_font_manager_char( unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_text( unsigned char *text, unsigned char x, unsigned char y );
void engine_font_manager_data( unsigned int data, unsigned char x, unsigned char y );
void engine_font_manager_zero( unsigned int data, unsigned char x, unsigned char y );

#endif//_FONT_MANAGER_H_