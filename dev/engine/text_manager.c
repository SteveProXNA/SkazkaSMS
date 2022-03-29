#include "text_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include <stdarg.h>

void engine_text_manager_clear( unsigned char start, unsigned char stop )
{
	unsigned char row;
	for( row = start; row <= stop; row++ )
	{
		engine_font_manager_text( LOCALE_29_SPCS, LEFT_X + 2, row );
	}
}

void engine_text_manager_border()
{
	unsigned char row, col;

	engine_font_manager_char( 0x8A, LEFT_X + 1, 0 );
	engine_font_manager_char( 0x8C, LEFT_X + 31, 0 );
	engine_font_manager_char( 0x8B, LEFT_X + 1, 23 );
	engine_font_manager_char( 0x8D, LEFT_X + 31, 23 );

	for( col = LEFT_X + 2; col <= LEFT_X + 30; col++ )
	{
		engine_font_manager_char( 0x81, LEFT_X + col, 0 );
		engine_font_manager_char( 0x81, LEFT_X + col, 23 );
	}

	for( row = 1; row <= 22; row++ )
	{
		engine_font_manager_char( 0x80, LEFT_X + 1, row );
		engine_font_manager_char( 0x80, LEFT_X + 31, row );
	}
}

void engine_text_manager_title( unsigned char row )
{
	engine_text_manager_args( LEFT_X + 3, row + 0, 26, 0x90, 0x90, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90, 0x90, 0x20, 0x20, 0x90, 0x90, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90, 0x90 );
	engine_text_manager_args( LEFT_X + 3, row + 1, 27, 0x90, 0x20, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90 );
	engine_text_manager_args( LEFT_X + 3, row + 2, 27, 0x90, 0x90, 0x90, 0x20, 0x90, 0x90, 0x20, 0x20, 0x20, 0x90, 0x90, 0x90, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90, 0x90, 0x20, 0x20, 0x20, 0x90, 0x90, 0x90, 0x90 );
	engine_text_manager_args( LEFT_X + 3, row + 3, 27, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x20, 0x90 );
	engine_text_manager_args( LEFT_X + 3, row + 4, 27, 0x90, 0x90, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x90, 0x90, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90, 0x20, 0x90, 0x20, 0x20, 0x90 );
}

void engine_text_manager_fire()
{
	engine_font_manager_text( LOCALE_FIRE1_CONT, LEFT_X + 5, FIRE1_ROW );
}

void engine_text_manager_diff()
{
	struct_game_object *go = &global_game_object;
	devkit_SMS_mapROMBank( FIXED_BANK );

	engine_font_manager_text( ( unsigned char * ) diff_texts[ go->difficulty ], LEFT_X + 27, LINES_ROW + 4 );
	engine_font_manager_text( LOCALE_MODES_WORD, LEFT_X + 27, LINES_ROW + 5 );
}

void engine_text_manager_args( unsigned char x, unsigned char y, unsigned char num, ... )
{
	unsigned char ch;
	unsigned char idx;

	va_list arglist;
	va_start( arglist, num );

	for( idx = 0; idx < num; idx++ )
	{
		ch = va_arg( arglist, int );
		engine_font_manager_char( ch, x++, y );
	}

	va_end( arglist );
}	
