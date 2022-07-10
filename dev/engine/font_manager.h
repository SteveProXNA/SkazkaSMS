#ifndef _FONT_MANAGER_H_
#define _FONT_MANAGER_H_

void engine_font_manager_draw_char( unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_punc( unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_flip( unsigned char ch, unsigned char x, unsigned char y );
void engine_font_manager_draw_text( unsigned char *text, unsigned char x, unsigned char y );
void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y );
void engine_font_manager_draw_numb( unsigned char numb, unsigned char x, unsigned char y );
void engine_font_manager_draw_zero( unsigned int data, unsigned char x, unsigned char y );

#endif//_FONT_MANAGER_H_