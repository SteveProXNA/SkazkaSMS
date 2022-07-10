#ifndef _SMS_MANAGER_H_
#define _SMS_MANAGER_H_

/* library initialization. you don't need to call this if you use devkitSMS crt0.rel */
void devkit_SMS_init();

/* VDP operative mode handling functions */
void devkit_SMS_VDPturnOnFeature( unsigned int feature );
void devkit_SMS_VDPturnOffFeature( unsigned int feature );

/* group 0 */
unsigned int devkit_VDPFEATURE_EXTRAHEIGHT();
unsigned int devkit_VDPFEATURE_SHIFTSPRITES();
unsigned int devkit_VDPFEATURE_HIDEFIRSTCOL();
unsigned int devkit_VDPFEATURE_LEFTCOLBLANK();
unsigned int devkit_VDPFEATURE_LOCKHSCROLL();
unsigned int devkit_VDPFEATURE_LOCKVSCROLL();

/* group 1 */
unsigned int devkit_VDPFEATURE_ZOOMSPRITES();
unsigned int devkit_VDPFEATURE_USETALLSPRITES();
unsigned int devkit_VDPFEATURE_240LINES();
unsigned int devkit_VDPFEATURE_224LINES();
unsigned int devkit_VDPFEATURE_FRAMEIRQ();
unsigned int devkit_VDPFEATURE_SHOWDISPLAY();

/* handy macros :) */
void devkit_SMS_displayOn();
void devkit_SMS_displayOff();

void devkit_SMS_setBGScrollX( unsigned char scrollX );
void devkit_SMS_setBGScrollY( unsigned char scrollY );
void devkit_SMS_setBackdropColor( unsigned char entry );
void devkit_SMS_useFirstHalfTilesforSprites( unsigned char usefirsthalf );
void devkit_SMS_setSpriteMode( unsigned char mode );

/* modes for SMS_setSpriteMode */
unsigned char devkit_SPRITEMODE_NORMAL();
unsigned char devkit_SPRITEMODE_TALL();
unsigned char devkit_SPRITEMODE_ZOOMED();
unsigned char devkit_SPRITEMODE_TALL_ZOOMED();

/* macro for ROM bankswitching */
///*volatile __at (0xffff)*/ unsigned char ROM_bank_to_be_mapped_on_slot2;
void devkit_SMS_mapROMBank( unsigned char n );

/* macro for SRAM access */
///*volatile __at (0xfffc)*/ unsigned char SRAM_bank_to_be_mapped_on_slot2;
void devkit_SMS_enableSRAM();
void devkit_SMS_enableSRAMBank( unsigned char n );
void devkit_SMS_disableSRAM();

/* SRAM access is as easy as accessing an array of char */
unsigned char* devkit_SMS_SRAM();

/* wait until next VBlank starts */
void devkit_SMS_waitForVBlank();

void devkit_SMS_crt0_RST08( unsigned int addr );
void devkit_SMS_crt0_RST18( unsigned int tile );

/* function for setting tiles/moving 'cursor' */
void devkit_SMS_setTile( const unsigned int tile );
void devkit_SMS_setAddr( const unsigned int addr );

/* PNT define (has address and VDP flags) */
//#define SMS_PNTAddress            0x7800
void devkit_XYtoADDR( unsigned int x, unsigned char y );
void devkit_SMS_setNextTileatXY( unsigned char x, unsigned char y );
void devkit_SMS_setNextTileatLoc( unsigned int loc );
void devkit_SMS_setNextTileatAddr( const unsigned char a	);
void devkit_SMS_setTileatXY( unsigned int x, unsigned char y, unsigned int tile );

//#define SMS_VDPVRAMWrite          0x4000
/* macro for turning tile numbers into VRAM addr for writing */
void devkit_TILEtoADDR( unsigned int tile );

/* handy defines for tilemaps entry */
unsigned int devkit_TILE_FLIPPED_X();
unsigned int devkit_TILE_FLIPPED_Y();
unsigned int devkit_TILE_USE_SPRITE_PALETTE();
unsigned int devkit_TILE_PRIORITY();

/* functions to load tiles into VRAM */
void devkit_SMS_loadTiles( void *src, unsigned int tilefrom, unsigned int size );
void devkit_SMS_load1bppTiles( const void *src, unsigned int tilefrom, unsigned int size, unsigned char color0, unsigned char color1 );

/* functions to load compressed tiles into VRAM */
void devkit_SMS_loadPSGaidencompressedTilesatAddr( const void *src, unsigned int dst );
void devkit_SMS_loadPSGaidencompressedTiles( const void *src, unsigned int tilefrom );

/* UNSAFE functions to load compressed tiles into VRAM */
void devkit_UNSAFE_SMS_loadZX7compressedTilesatAddr( const void *src, unsigned int dst );
void devkit_UNSAFE_SMS_loadZX7compressedTiles( const void *src, unsigned int tilefrom );
void devkit_UNSAFE_SMS_loadaPLibcompressedTilesatAddr( const void *src, unsigned int dst );
void devkit_UNSAFE_SMS_loadaPLibcompressedTiles( const void *src, unsigned int tilefrom );

/* functions for the tilemap */
void devkit_SMS_loadTileMap( unsigned char x, unsigned char y, unsigned char *src, int size );
void devkit_SMS_loadTileMapArea( unsigned char x, unsigned char y, void *src, unsigned char width, unsigned char height );

void devkit_SMS_loadSTMcompressedTileMapatAddr( unsigned int dst, const void *src );
void devkit_SMS_loadSTMcompressedTileMap( unsigned char x, unsigned char y, unsigned char *src );
void devkit_SMS_loadSTMcompressedTileMapArea( unsigned char x, unsigned char y, unsigned char *src /*, unsigned char w*/ );
// SMS_loadSTMcompressedTileMapArea *DEPRECATED* - will be dropped at some point in 201818

/* functions for sprites handling */
void devkit_SMS_initSprites();
void devkit_SMS_addSprite( unsigned char x, unsigned char y, int tile );
void devkit_SMS_addTwoAdjoiningSprites( unsigned char x, unsigned char y, unsigned char tile ); /*__naked __preserves_regs( iyh, iyl )*/     /* doesn't return anything */
void devkit_SMS_addThreeAdjoiningSprites( unsigned char x, unsigned char y, unsigned char tile );  /*__naked __preserves_regs( iyh, iyl )*/   /* doesn't return anything */
signed char devkit_SMS_reserveSprite( void );
void devkit_SMS_updateSpritePosition( signed char sprite, unsigned char x, unsigned char y );
void devkit_SMS_updateSpriteImage( signed char sprite, unsigned char tile );
void devkit_SMS_hideSprite( signed char sprite );
void devkit_SMS_setClippingWindow( unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1 );
signed char devkit_SMS_addSpriteClipping( int x, int y, unsigned char tile );   /* returns -1 if no more sprites are available or sprite clipped */
void devkit_SMS_finalizeSprites();     // *DEPRECATED* - will be dropped at some point in 2018
void devkit_SMS_copySpritestoSAT();

/* ***************************************************************** */
/* Colors / palettes handling                                        */
/* ***************************************************************** */

/* SMS_CRAMAddress define (has address and VDP flags) */
//#define SMS_CRAMAddress                    0xC000

/* SMS functions to set a color / load a palette */
void devkit_SMS_setBGPaletteColor( unsigned char entry, unsigned char color );
void devkit_SMS_setSpritePaletteColor( unsigned char entry, unsigned char color );
void devkit_SMS_loadBGPalette( void *palette );
void devkit_SMS_loadSpritePalette( void *palette );
void devkit_SMS_setNextBGColoratIndex( const unsigned char i );
void devkit_SMS_setNextSpriteColoratIndex( const unsigned char i );
void devkit_SMS_setColor( unsigned char color ); /*__z88dk_fastcall __preserves_regs( b, c, d, e, h, l, iyh, iyl )*/

/* SMS macros for colors */
unsigned char devkit_RGB( const unsigned char r, const unsigned char g, const unsigned char b );
unsigned char devkit_RGB8( const unsigned char r, const unsigned char g, const unsigned char b );
//unsigned char devkit_RGBHTML( const unsigned int RGB24bit );
void devkit_SMS_loadBGPaletteHalfBrightness( void *palette );
void devkit_SMS_loadSpritePaletteHalfBrightness( void *palette );
void devkit_SMS_zeroBGPalette( void );
void devkit_SMS_zeroSpritePalette( void );

/* text renderer */
void devkit_SMS_configureTextRenderer( signed int ascii_to_tile_offset );
void devkit_SMS_autoSetUpTextRenderer( void );

/* decompress ZX7-compressed data to RAM */
void devkit_SMS_decompressZX7( const void *src, void *dst );

/* functions to read joypad(s) */
unsigned int devkit_SMS_getKeysStatus();
unsigned int devkit_SMS_getKeysPressed();
unsigned int devkit_SMS_getKeysHeld();
unsigned int devkit_SMS_getKeysReleased();

/* handy defines for joypad(s) handling */
unsigned int devkit_PORT_A_KEY_UP();
unsigned int devkit_PORT_A_KEY_DOWN();
unsigned int devkit_PORT_A_KEY_LEFT();
unsigned int devkit_PORT_A_KEY_RIGHT();
unsigned int devkit_PORT_A_KEY_1();
unsigned int devkit_PORT_A_KEY_2();
unsigned int devkit_PORT_A_KEY_START();

unsigned int devkit_PORT_B_KEY_UP();
unsigned int devkit_PORT_B_KEY_DOWN();
unsigned int devkit_PORT_B_KEY_LEFT();
unsigned int devkit_PORT_B_KEY_RIGHT();
unsigned int devkit_PORT_B_KEY_1();
unsigned int devkit_PORT_B_KEY_2();
unsigned int devkit_PORT_B_KEY_START();

unsigned int devkit_RESET_KEY();
unsigned int devkit_CARTRIDGE_SLOT();
unsigned int devkit_PORT_A_TH();
unsigned int devkit_PORT_B_TH();

/* paddle controller handling (SMS only) */
unsigned char devkit_PORT_A();
unsigned char devkit_PORT_B();
unsigned char devkit_SMS_detectPaddle( unsigned char port ); //__z88dk_fastcall __naked;
unsigned char devkit_SMS_readPaddle( unsigned char port ); //__z88dk_fastcall __naked;

/* pause handling (SMS only) */
unsigned char devkit_SMS_queryPauseRequested();
void devkit_SMS_resetPauseRequest();

// SMS_VDPType
//unsigned char devkit_SMS_VDPType( void );
///* WARNING: these constants may change value later, please use defines */
//unsigned char devkit_VDP_PAL();
//unsigned char devkit_VDP_NTSC();

// SMS_VDPFlags
unsigned char devkit_SMS_VDPFlags( void );
unsigned char devkit_VDPFLAG_SPRITEOVERFLOW();
unsigned char devkit_VDPFLAG_SPRITECOLLISION();

/* line interrupt */
void devkit_SMS_setLineInterruptHandler( void( *theHandlerFunction )( void ) ); // __z88dk_fastcall;
void devkit_SMS_setLineCounter( unsigned char count );
void devkit_SMS_enableLineInterrupt(); /* turns on line IRQ */
void devkit_SMS_disableLineInterrupt(); /* turns off line IRQ */

/* Vcount */
unsigned char devkit_SMS_getVCount( void );
/* Hcount */
unsigned char devkit_SMS_getHCount( void );

/* low level functions */
void devkit_SMS_VRAMmemcpy( unsigned int dst, const void *src, unsigned int size ); // __naked __z88dk_callee __preserves_regs( iyh, iyl );
void devkit_SMS_VRAMmemcpy_brief( unsigned int dst, const void *src, unsigned char size ); // __naked __z88dk_callee __preserves_regs( iyh, iyl );
void devkit_SMS_VRAMmemset( unsigned int dst, unsigned char value, unsigned int size );
void devkit_SMS_VRAMmemsetW( unsigned int dst, unsigned int value, unsigned int size );

/* VRAM unsafe functions. Fast, but dangerous! */
void devkit_UNSAFE_SMS_copySpritestoSAT( void );
void devkit_UNSAFE_SMS_VRAMmemcpy32( unsigned int dst, void *src );
void devkit_UNSAFE_SMS_VRAMmemcpy64( unsigned int dst, void *src );
void devkit_UNSAFE_SMS_VRAMmemcpy128( unsigned int dst, void *src );

/* handy macros for UNSAFE_SMS_VRAMmemcpy* */
void devkit_UNSAFE_SMS_load1Tile( void *src, unsigned int theTile );
void devkit_UNSAFE_SMS_load2Tiles( void *src, unsigned int tilefrom );
void devkit_UNSAFE_SMS_load4Tiles( void *src, unsigned int tilefrom );

/* the Interrupt Service Routines (do not modify) */
void dekvit_SMS_isr( void ); // __naked;
void dekvit_SMS_nmi_isr( void ); // __naked;


// Helper functions.
void devkit_SMS_addSprite_bulk8( unsigned char x, unsigned char y, int tile );
void devkit_SMS_addSprite_bulk12( unsigned char x, unsigned char y, int tile );
void devkit_SMS_setTilePriority( const unsigned char tile );
unsigned char devkit_isCollisionDetected();

#endif//_SMS_MANAGER_H_