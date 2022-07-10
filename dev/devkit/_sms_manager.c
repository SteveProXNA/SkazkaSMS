#include "_sms_manager.h"
#include "../game.h"
#include <stdbool.h>

#ifdef _CONSOLE
#include "../../tmp/SMSlib.h"
#else
#include "../../lib/SMSlib.h"
#endif

/* library initialization. you don't need to call this if you use devkitSMS crt0.rel */
void devkit_SMS_init()
{
	SMS_init();
}

/* VDP operative mode handling functions */
void devkit_SMS_VDPturnOnFeature( unsigned int feature )
{
	SMS_VDPturnOnFeature( feature );
}
void devkit_SMS_VDPturnOffFeature( unsigned int feature )
{
	SMS_VDPturnOffFeature( feature );
}

/* group 0 */
unsigned int devkit_VDPFEATURE_EXTRAHEIGHT()
{
	return VDPFEATURE_EXTRAHEIGHT; 
}
unsigned int devkit_VDPFEATURE_SHIFTSPRITES()
{
	return VDPFEATURE_SHIFTSPRITES; 
}
unsigned int devkit_VDPFEATURE_HIDEFIRSTCOL() 
{
	return VDPFEATURE_HIDEFIRSTCOL; 
}
unsigned int devkit_VDPFEATURE_LEFTCOLBLANK()
{
	return VDPFEATURE_LEFTCOLBLANK; 
}
unsigned int devkit_VDPFEATURE_LOCKHSCROLL()
{
	return VDPFEATURE_LOCKHSCROLL; 
}
unsigned int devkit_VDPFEATURE_LOCKVSCROLL() 
{
	return VDPFEATURE_LOCKVSCROLL; 
}

/* group 1 */
unsigned int devkit_VDPFEATURE_ZOOMSPRITES()
{
	return VDPFEATURE_ZOOMSPRITES; 
}
unsigned int devkit_VDPFEATURE_USETALLSPRITES()
{
	return VDPFEATURE_USETALLSPRITES; 
}
unsigned int devkit_VDPFEATURE_240LINES()
{
	return VDPFEATURE_240LINES; 
}
unsigned int devkit_VDPFEATURE_224LINES()
{
	return VDPFEATURE_224LINES; 
}
unsigned int devkit_VDPFEATURE_FRAMEIRQ()
{
	return VDPFEATURE_FRAMEIRQ;
}
unsigned int devkit_VDPFEATURE_SHOWDISPLAY()
{
	return VDPFEATURE_SHOWDISPLAY; 
}

/* handy macros :) */
void devkit_SMS_displayOn()
{
	SMS_displayOn();
}
void devkit_SMS_displayOff()
{
	SMS_displayOff();
}

void devkit_SMS_setBGScrollX( unsigned char scrollX )
{
	SMS_setBGScrollX( scrollX );
}
void devkit_SMS_setBGScrollY( unsigned char scrollY )
{
	SMS_setBGScrollY( scrollY );
}
void devkit_SMS_setBackdropColor( unsigned char entry )
{
	SMS_setBackdropColor( entry );
}
void devkit_SMS_useFirstHalfTilesforSprites( unsigned char usefirsthalf )
{
	SMS_useFirstHalfTilesforSprites( usefirsthalf );
}
void devkit_SMS_setSpriteMode( unsigned char mode )
{
	SMS_setSpriteMode( mode );
}

/* modes for SMS_setSpriteMode */
unsigned char devkit_SPRITEMODE_NORMAL() 
{
	return SPRITEMODE_NORMAL; 
}
unsigned char devkit_SPRITEMODE_TALL()
{
	return SPRITEMODE_TALL; 
}
unsigned char devkit_SPRITEMODE_ZOOMED()
{ 
	return SPRITEMODE_ZOOMED; 
}
unsigned char devkit_SPRITEMODE_TALL_ZOOMED()
{
	return SPRITEMODE_TALL_ZOOMED; 
}

/* macro for ROM bankswitching */
///*volatile __at (0xffff)*/ unsigned char ROM_bank_to_be_mapped_on_slot2;
void devkit_SMS_mapROMBank( unsigned char n )
{
	SMS_mapROMBank( n );
}

/* macro for SRAM access */
void devkit_SMS_enableSRAM()
{
	SMS_enableSRAM();
}
void devkit_SMS_enableSRAMBank( unsigned char n )
{
	SMS_enableSRAMBank( n );
}
void devkit_SMS_disableSRAM()
{
	SMS_disableSRAM();
}

/* SRAM access is as easy as accessing an array of char */
unsigned char* devkit_SMS_SRAM()
{
	return SMS_SRAM;
}

/* wait until next VBlank starts */
void devkit_SMS_waitForVBlank()
{
	SMS_waitForVBlank();
}

void devkit_SMS_crt0_RST08( unsigned int addr )
{
	SMS_crt0_RST08( addr );
}
void devkit_SMS_crt0_RST18( unsigned int tile )
{
	SMS_crt0_RST18( tile );
}

/* function for setting tiles/moving 'cursor' */
void devkit_SMS_setTile( const unsigned int tile )
{
	SMS_setTile( tile );
}
void devkit_SMS_setAddr( const unsigned int addr )
{
	SMS_setAddr( addr );
}

/* PNT define (has address and VDP flags) */
//#define SMS_PNTAddress            0x7800
void devkit_XYtoADDR( unsigned int x, unsigned char y )
{
	XYtoADDR( x, y );
}
void devkit_SMS_setNextTileatXY( unsigned char x, unsigned char y )
{
	SMS_setNextTileatXY( x, y );
}
void devkit_SMS_setNextTileatLoc( unsigned int loc )
{
	SMS_setNextTileatLoc( loc );
}
void devkit_SMS_setNextTileatAddr( const unsigned char a )
{
	SMS_setNextTileatAddr( a );
}
void devkit_SMS_setTileatXY( unsigned int x, unsigned char y, unsigned int tile )
{
	SMS_setTileatXY( x, y, tile );
}

//#define SMS_VDPVRAMWrite          0x4000
/* macro for turning tile numbers into VRAM addr for writing */
void devkit_TILEtoADDR( unsigned int tile )
{
	TILEtoADDR( tile );
}

/* handy defines for tilemaps entry */
unsigned int devkit_TILE_FLIPPED_X()
{
	return TILE_FLIPPED_X;
}
unsigned int devkit_TILE_FLIPPED_Y()
{
	return TILE_FLIPPED_Y;
}
unsigned int devkit_TILE_USE_SPRITE_PALETTE()
{
	return TILE_USE_SPRITE_PALETTE;
}
unsigned int devkit_TILE_PRIORITY()
{
	return TILE_PRIORITY;
}

/* functions to load tiles into VRAM */
void devkit_SMS_loadTiles( void *src, unsigned int tilefrom, unsigned int size )
{
	SMS_loadTiles( src, tilefrom, size );
}
void devkit_SMS_load1bppTiles( const void *src, unsigned int tilefrom, unsigned int size, unsigned char color0, unsigned char color1 )
{
	SMS_load1bppTiles( src, tilefrom, size, color0, color1 );
}

/* functions to load compressed tiles into VRAM */
void devkit_SMS_loadPSGaidencompressedTilesatAddr( const void *src, unsigned int dst )
{
	SMS_loadPSGaidencompressedTilesatAddr( src, dst );
}
void devkit_SMS_loadPSGaidencompressedTiles( const void *src, unsigned int tilefrom )
{
	SMS_loadPSGaidencompressedTiles( src, tilefrom );
}

/* UNSAFE functions to load compressed tiles into VRAM */
void devkit_UNSAFE_SMS_loadZX7compressedTilesatAddr( const void *src, unsigned int dst )
{
	UNSAFE_SMS_loadZX7compressedTilesatAddr( src, dst );
}
void devkit_UNSAFE_SMS_loadZX7compressedTiles( const void *src, unsigned int tilefrom )
{
	UNSAFE_SMS_loadZX7compressedTiles( src, tilefrom );
}
void devkit_UNSAFE_SMS_loadaPLibcompressedTilesatAddr( const void *src, unsigned int dst )
{
	UNSAFE_SMS_loadaPLibcompressedTilesatAddr( src, dst );
}
void devkit_UNSAFE_SMS_loadaPLibcompressedTiles( const void *src, unsigned int tilefrom )
{
	UNSAFE_SMS_loadaPLibcompressedTiles( src, tilefrom );
}

/* functions for the tilemap */
void devkit_SMS_loadTileMap( unsigned char x, unsigned char y, unsigned char *src, int size )
{
	SMS_loadTileMap( x, y, src, size );
}
void devkit_SMS_loadTileMapArea( unsigned char x, unsigned char y, void *src, unsigned char width, unsigned char height )
{
	SMS_loadTileMapArea( x, y, src, width, height );
}

void devkit_SMS_loadSTMcompressedTileMapatAddr( unsigned int dst, const void *src )
{
	SMS_loadSTMcompressedTileMapatAddr( dst, src );
}
void devkit_SMS_loadSTMcompressedTileMap( unsigned char x, unsigned char y, unsigned char *src )
{
	SMS_loadSTMcompressedTileMap( x, y, src );
}
void devkit_SMS_loadSTMcompressedTileMapArea( unsigned char x, unsigned char y, unsigned char *src /*, unsigned char w*/ )
{
	SMS_loadSTMcompressedTileMapArea( x, y, src, 0 /*, w*/ );
}

/* functions for sprites handling */
void devkit_SMS_initSprites()
{
	SMS_initSprites();
}
void devkit_SMS_addSprite( unsigned char x, unsigned char y, int tile )
{
	SMS_addSprite( x, y, tile );
}
void devkit_SMS_addTwoAdjoiningSprites( unsigned char x, unsigned char y, unsigned char tile )
{
	SMS_addTwoAdjoiningSprites( x, y, tile );
}
void devkit_SMS_addThreeAdjoiningSprites( unsigned char x, unsigned char y, unsigned char tile )
{
	SMS_addThreeAdjoiningSprites( x, y, tile );
}
signed char devkit_SMS_reserveSprite( void )
{
	return SMS_reserveSprite();
}
void devkit_SMS_updateSpritePosition( signed char sprite, unsigned char x, unsigned char y )
{
	SMS_updateSpritePosition( sprite, x, y );
}
void devkit_SMS_updateSpriteImage( signed char sprite, unsigned char tile )
{
	SMS_updateSpriteImage( sprite, tile );
}
void devkit_SMS_hideSprite( signed char sprite )
{
	SMS_hideSprite( sprite );
}
void devkit_SMS_setClippingWindow( unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1 )
{
	SMS_setClippingWindow( x0, y0, x1, y1 );
}
signed char devkit_SMS_addSpriteClipping( int x, int y, unsigned char tile )
{
	return SMS_addSpriteClipping( x, y, tile );
}
void devkit_SMS_finalizeSprites()
{
	SMS_finalizeSprites();
}
void devkit_SMS_copySpritestoSAT()
{
	SMS_copySpritestoSAT();
}

/* ***************************************************************** */
/* Colors / palettes handling                                        */
/* ***************************************************************** */

/* SMS_CRAMAddress define (has address and VDP flags) */
//#define SMS_CRAMAddress                    0xC000

/* SMS functions to set a color / load a palette */
void devkit_SMS_setBGPaletteColor( unsigned char entry, unsigned char color )
{
	SMS_setBGPaletteColor( entry, color );
}
void devkit_SMS_setSpritePaletteColor( unsigned char entry, unsigned char color )
{
	SMS_setSpritePaletteColor( entry, color );
}
void devkit_SMS_loadBGPalette( void *palette )
{
	SMS_loadBGPalette( palette );
}
void devkit_SMS_loadSpritePalette( void *palette )
{
	SMS_loadSpritePalette( palette );
}
void devkit_SMS_setNextBGColoratIndex( const unsigned char i )
{
	SMS_setNextBGColoratIndex( i );
}
void devkit_SMS_setNextSpriteColoratIndex( const unsigned char i )
{
	SMS_setNextSpriteColoratIndex( i );
}
void devkit_SMS_setColor( unsigned char color )
{
	SMS_setColor( color );
}

/* SMS macros for colors */
unsigned char devkit_RGB( const unsigned char r, const unsigned char g, const unsigned char b )
{
	return RGB( r, g, b );
}
unsigned char devkit_RGB8( const unsigned char r, const unsigned char g, const unsigned char b )
{
	return RGB8( r, g, b );
}
//_sms_manager.c:388: warning 116: right shifting more than size of object changed to zero
//unsigned char devkit_RGBHTML( const unsigned int RGB24bit )
//{
//	return RGBHTML( RGB24bit );
//}
void devkit_SMS_loadBGPaletteHalfBrightness( void *palette )
{
	SMS_loadBGPaletteHalfBrightness( palette );
}
void devkit_SMS_loadSpritePaletteHalfBrightness( void *palette )
{
	SMS_loadSpritePaletteHalfBrightness( palette );
}
void devkit_SMS_zeroBGPalette( void )
{
	SMS_zeroBGPalette();
}
void devkit_SMS_zeroSpritePalette( void )
{
	SMS_zeroSpritePalette();
}

/* text renderer */
void devkit_SMS_configureTextRenderer( signed int ascii_to_tile_offset )
{
	SMS_configureTextRenderer( ascii_to_tile_offset );
}
void devkit_SMS_autoSetUpTextRenderer( void )
{
	SMS_autoSetUpTextRenderer();
}

/* decompress ZX7-compressed data to RAM */
void devkit_SMS_decompressZX7( const void *src, void *dst )
{
	SMS_decompressZX7( src, dst );
}

/* functions to read joypad(s) */
unsigned int devkit_SMS_getKeysStatus()
{
	return SMS_getKeysStatus();
}
unsigned int devkit_SMS_getKeysPressed()
{
	return SMS_getKeysPressed();
}
unsigned int devkit_SMS_getKeysHeld()
{
	return SMS_getKeysHeld();
}
unsigned int devkit_SMS_getKeysReleased()
{
	return SMS_getKeysReleased();
}

/* handy defines for joypad(s) handling */
unsigned int devkit_PORT_A_KEY_UP()
{
	return PORT_A_KEY_UP;
}
unsigned int devkit_PORT_A_KEY_DOWN()
{
	return PORT_A_KEY_DOWN;
}
unsigned int devkit_PORT_A_KEY_LEFT()
{
	return PORT_A_KEY_LEFT;
}
unsigned int devkit_PORT_A_KEY_RIGHT()
{
	return PORT_A_KEY_RIGHT;
}
unsigned int devkit_PORT_A_KEY_1()
{
	return PORT_A_KEY_1;
}
unsigned int devkit_PORT_A_KEY_2()
{
	return PORT_A_KEY_2;
}
unsigned int devkit_PORT_A_KEY_START()
{
	return PORT_A_KEY_START;
}

unsigned int devkit_PORT_B_KEY_UP()
{
	return PORT_B_KEY_UP;
}
unsigned int devkit_PORT_B_KEY_DOWN()
{
	return PORT_B_KEY_DOWN;
}
unsigned int devkit_PORT_B_KEY_LEFT()
{
	return PORT_B_KEY_LEFT;
}
unsigned int devkit_PORT_B_KEY_RIGHT()
{
	return PORT_B_KEY_RIGHT;
}
unsigned int devkit_PORT_B_KEY_1()
{
	return PORT_B_KEY_1;
}
unsigned int devkit_PORT_B_KEY_2()
{
	return PORT_B_KEY_2;
}
unsigned int devkit_PORT_B_KEY_START()
{
	return PORT_B_KEY_START;
}

unsigned int devkit_RESET_KEY()
{
	return RESET_KEY; 
}
unsigned int devkit_CARTRIDGE_SLOT()
{
	return CARTRIDGE_SLOT; 
}
unsigned int devkit_PORT_A_TH()
{
	return PORT_A_TH; 
}
unsigned int devkit_PORT_B_TH()
{
	return PORT_B_TH; 
}

/* paddle controller handling (SMS only) */
unsigned char devkit_PORT_A()
{
	return PORT_A;
}
unsigned char devkit_PORT_B()
{
	return PORT_B;
}
unsigned char devkit_SMS_detectPaddle( unsigned char port )
{
	return SMS_detectPaddle( port );
}
unsigned char devkit_SMS_readPaddle( unsigned char port )
{
	return SMS_readPaddle( port );
}

/* pause handling (SMS only) */
unsigned char devkit_SMS_queryPauseRequested()
{
	return SMS_queryPauseRequested();
}
void devkit_SMS_resetPauseRequest()
{
	SMS_resetPauseRequest();
}

// SMS_VDPType
//unsigned char devkit_SMS_VDPType( void )
//{
//	return SMS_VDPType();
//}
///* WARNING: these constants may change value later, please use defines */
//unsigned char devkit_VDP_PAL()
//{
//	return VDP_PAL;
//}
//unsigned char devkit_VDP_NTSC()
//{
//	return VDP_NTSC;
//}

// SMS_VDPFlags
unsigned char devkit_SMS_VDPFlags( void )
{
	return SMS_VDPFlags;
}
unsigned char devkit_VDPFLAG_SPRITEOVERFLOW()
{
	return VDPFLAG_SPRITEOVERFLOW;
}
unsigned char devkit_VDPFLAG_SPRITECOLLISION()
{
	return VDPFLAG_SPRITECOLLISION;
}

/* line interrupt */
void devkit_SMS_setLineInterruptHandler( void( *theHandlerFunction )( void ) )
{
	SMS_setLineInterruptHandler( theHandlerFunction );
}
void devkit_SMS_setLineCounter( unsigned char count )
{
	SMS_setLineCounter( count );
}
void devkit_SMS_enableLineInterrupt()
{
	SMS_enableLineInterrupt();
}
void devkit_SMS_disableLineInterrupt()
{
	SMS_disableLineInterrupt();
}

/* Vcount */
unsigned char devkit_SMS_getVCount( void )
{
	return SMS_getVCount();
}
/* Hcount */
unsigned char devkit_SMS_getHCount( void )
{
	return SMS_getHCount();
}

/* low level functions */
void devkit_SMS_VRAMmemcpy( unsigned int dst, const void *src, unsigned int size )
{
	SMS_VRAMmemcpy( dst, src, size );
}
void devkit_SMS_VRAMmemcpy_brief( unsigned int dst, const void *src, unsigned char size )
{
	SMS_VRAMmemcpy_brief( dst, src, size );
}
void devkit_SMS_VRAMmemset( unsigned int dst, unsigned char value, unsigned int size )
{
	SMS_VRAMmemset( dst, value, size );
}
void devkit_SMS_VRAMmemsetW( unsigned int dst, unsigned int value, unsigned int size )
{
	SMS_VRAMmemsetW( dst, value, size );
}

/* VRAM unsafe functions. Fast, but dangerous! */
void devkit_UNSAFE_SMS_copySpritestoSAT( void )
{
	UNSAFE_SMS_copySpritestoSAT();
}
void devkit_UNSAFE_SMS_VRAMmemcpy32( unsigned int dst, void *src )
{
	UNSAFE_SMS_VRAMmemcpy32( dst, src );
}
void devkit_UNSAFE_SMS_VRAMmemcpy64( unsigned int dst, void *src )
{
	UNSAFE_SMS_VRAMmemcpy64( dst, src );
}
void devkit_UNSAFE_SMS_VRAMmemcpy128( unsigned int dst, void *src )
{
	UNSAFE_SMS_VRAMmemcpy128( dst, src );
}

/* handy macros for UNSAFE_SMS_VRAMmemcpy* */
void devkit_UNSAFE_SMS_load1Tile( void *src, unsigned int theTile )
{
	UNSAFE_SMS_VRAMmemcpy32( ( theTile ) * 32, ( src ) );
}
void devkit_UNSAFE_SMS_load2Tiles( void *src, unsigned int tilefrom )
{
	UNSAFE_SMS_VRAMmemcpy64( ( tilefrom ) * 32, ( src ) );
}
void devkit_UNSAFE_SMS_load4Tiles( void *src, unsigned int tilefrom )
{
	UNSAFE_SMS_VRAMmemcpy128( ( tilefrom ) * 32, ( src ) );
}


/* the Interrupt Service Routines (do not modify) */
void dekvit_SMS_isr( void )
{
	SMS_isr();
}
void dekvit_SMS_nmi_isr( void )
{
	SMS_nmi_isr();
}



// Helper functions.
void devkit_SMS_addSprite_bulk8( unsigned char x, unsigned char y, int tile )
{
	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );

	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );

	devkit_SMS_addSprite( x + 0, y + 16, tile + 4 );
	devkit_SMS_addSprite( x + 8, y + 16, tile + 5 );

	devkit_SMS_addSprite( x + 0, y + 24, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 24, tile + 7 );
}
void devkit_SMS_addSprite_bulk12( unsigned char x, unsigned char y, int tile )
{
	SMS_addSprite( x + 0, y + 0, tile + 0 );
	SMS_addSprite( x + 8, y + 0, tile + 1 );
	SMS_addSprite( x + 16, y + 0, tile + 2 );

	SMS_addSprite( x + 0, y + 8, tile + 3 );
	SMS_addSprite( x + 8, y + 8, tile + 4 );
	SMS_addSprite( x + 16, y + 8, tile + 5 );

	SMS_addSprite( x + 0, y + 16, tile + 6 );
	SMS_addSprite( x + 8, y + 16, tile + 7 );
	SMS_addSprite( x + 16, y + 16, tile + 8 );

	SMS_addSprite( x + 0, y + 24, tile + 9 );
	SMS_addSprite( x + 8, y + 24, tile + 10 );
	SMS_addSprite( x + 16, y + 24, tile + 11 );
}

void devkit_SMS_setTilePriority( const unsigned char tile )
{
	SMS_setTile( tile | TILE_PRIORITY | TILE_USE_SPRITE_PALETTE );
}
unsigned char devkit_isCollisionDetected()
{
	return ( SMS_VDPFlags & VDPFLAG_SPRITECOLLISION );
}


// Sega header.
#ifdef _CONSOLE
#else
SMS_EMBED_SEGA_ROM_HEADER( productCode, revision );
SMS_EMBED_SDSC_HEADER( verMaj, verMin, dateYear, dateMonth, dateDay, author, name, descr );
#endif