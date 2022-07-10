#include "font_manager.h"
#include "locale_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

#define TEXT_ROOT	64		// 64 is "A" (65-01).
#define DATA_ROOT	27		// 27 is "0" (48-27).
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	3		// 3 placeholder

// Private helper functions.
static unsigned char get_tile( unsigned char ch );
static void draw_char( unsigned int tile, unsigned char x, unsigned char y );

void engine_font_manager_draw_punc( unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = get_tile( ch );
	draw_char( tile, x, y );
}
void engine_font_manager_draw_flip( unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = get_tile( ch );
	unsigned int flipX = devkit_TILE_FLIPPED_X();
	draw_char( ( tile | flipX ), x, y );
}

void engine_font_manager_draw_char( unsigned char ch, unsigned char x, unsigned char y )
{
	unsigned char tile = ch - TEXT_ROOT;
	draw_char( tile, x, y );
}

void engine_font_manager_draw_text( unsigned char *text, unsigned char x, unsigned char y )
{
	unsigned char idx = 0;
	while( '\0' != text[idx] )
	{
		unsigned char ch = text[ idx ];
		unsigned char tile = ch - TEXT_ROOT;
		draw_char( tile, x, y );
		x++;
		idx++;
	}
}

void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	signed char tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	char hold[DATA_LONG];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;

		hold[idx] = remainder;
		data /= UNIT_ROOT;

		tile = hold[idx] + DATA_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		draw_char( tile, x, y );
		x--;
	}
}

void engine_font_manager_draw_numb( unsigned char numb, unsigned char x, unsigned char y )
{
	unsigned char tile = numb + DATA_ROOT;
	draw_char( tile, x, y );
}

void engine_font_manager_draw_zero( unsigned int data, unsigned char x, unsigned char y )
{
	unsigned char idx;
	unsigned char tile;

	char hold[DATA_LONG];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		hold[idx] = data % UNIT_ROOT;
		data /= UNIT_ROOT;

		tile = hold[idx] + DATA_ROOT;
		draw_char( tile, x, y );
		x--;
	}
}

static unsigned char get_tile( unsigned char ch )
{
	if( LOCALE_PLUS == ch ) { return 37; }
	else if( LOCALE_HYPHEN == ch ) { return 38; }
	else if( LOCALE_QUOTE == ch ) { return 39; }
	else if( LOCALE_STOP == ch ) { return 40; }
	else if( LOCALE_COMMA == ch ) { return 41; }
	else if( LOCALE_COLON == ch ) { return 42; }
	else if( LOCALE_QMARK == ch ) { return 43; }
	else if( LOCALE_POINT == ch ) { return 44; }
	else if( LOCALE_SLASH == ch ) { return 45; }
	else if( ')' == ch ) { return 46; }
	else if( LOCALE_ARROW == ch ) { return 47; }
	return 0;
}
static void draw_char( unsigned int tile, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font__tilemap__bin;
	devkit_SMS_setNextTileatXY( x, y );
	devkit_SMS_setTile( *pnt + tile );
}