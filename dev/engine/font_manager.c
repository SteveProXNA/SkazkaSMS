#include "font_manager.h"
#include "../devkit/_sms_manager.h"
#include "../content/gfx.h"

#define BASE_ROOT 44 // 44 is title starts.
#define TEXT_ROOT 32 // 32 is " " in ASCII.
#define DATA_ROOT 16 // 16 is "0" (48=16+32)
#define UNIT_ROOT 10 // 10 is decimal
#define DATA_LONG 3	 // 3 placeholder

static unsigned char get_tile( unsigned char ch );

void engine_font_manager_char( unsigned char ch, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;
	unsigned char tile = get_tile( ch );
	devkit_SMS_setNextTileatXY(x, y);
	devkit_SMS_setTile(*pnt + tile);
}

void engine_font_manager_text( unsigned char *text, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;
	unsigned char idx = 0;

	while ( '\0' != text[idx] )
	{
		unsigned char ch = text[idx];
		unsigned char tile = get_tile( ch );
		devkit_SMS_setNextTileatXY(x++, y);
		devkit_SMS_setTile(*pnt + tile);
		idx++;
	}
}

void engine_font_manager_data( unsigned int data, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;

	unsigned char idx;
	unsigned int tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	char hold[ DATA_LONG ];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;

		hold[ idx ] = remainder;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT + BASE_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		devkit_SMS_setNextTileatXY( x--, y );
		devkit_SMS_setTile( *pnt + tile );
	}
}

void engine_font_manager_zero( unsigned int data, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;

	unsigned char idx;
	unsigned int tile;

	char hold[ DATA_LONG ];
	for( idx = 0; idx < DATA_LONG; ++idx )
	{
		hold[ idx ] = data % UNIT_ROOT;
		data /= UNIT_ROOT;

		tile = hold[ idx ] + DATA_ROOT + BASE_ROOT;

		devkit_SMS_setNextTileatXY( x--, y );
		devkit_SMS_setTile( *pnt + tile );
	}
}

static unsigned char get_tile( unsigned char ch )
{
	unsigned char tile = ch;

	// Awful hacks!
	if( 0xEE == ch )
	{
		return 0xE8;
	}
	if( 0xEF == ch )
	{
		return 0x16;
	}
	if( ' ' == ch )
	{
		tile = ch - TEXT_ROOT;
		return tile;
	}

	// Last section.
	if( tile >= 0xF5 )
	{
		tile -= 12;
	}
	else if( tile >= 0xE0 )
	{
		tile -= 5;
	}
	else
	{
		tile = ch - TEXT_ROOT;
		tile += BASE_ROOT;
		if( tile >= 0x80 )
		{
			tile -= 1;
		}
	}

	return tile;
}