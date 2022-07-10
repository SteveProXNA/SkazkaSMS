#include "text_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"

void engine_text_manager_clear( unsigned char start, unsigned char stop )
{
	unsigned char row;
	for( row = start; row <= stop; row++ )
	{
		engine_font_manager_draw_text( LOCALE_30_SPCS, LEFT_X + 1, TOP_Y + row );
	}
}

void engine_text_manager_cont()
{
	engine_font_manager_draw_text( LOCALE_FIRE1_CONT, LEFT_X + 4, TOP_Y + 21 );
	engine_text_manager_one();
}

void engine_text_manager_one()
{
	engine_font_manager_draw_numb( 1, LEFT_X + 15, TOP_Y + 21 );
}