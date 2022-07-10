@echo off

cd ..
cd banks
cd bank3

:: Tiles
bmp2tile.exe raw/font_overs.png -savetiles "font_overs (tiles).psgcompr" -noremovedupes           -planar -tileoffset   0  -savetilemap "font_overs (tilemap).bin" -savepalette "font_overs (palette).bin" -fullpalette -exit
bmp2tile.exe raw/splash.png     -savetiles "splash (tiles).psgcompr"       -removedupes -nomirror -planar -tileoffset   0  -savetilemap "splash (tilemap).bin"   -savepalette "splash (palette).bin"       -fullpalette -exit
bmp2tile.exe raw/logo_new.png   -savetiles "logo_new (tiles).psgcompr"   -noremovedupes           -planar -tileoffset 272  -savetilemap "logo_new (tilemap).bin" -savepalette "logo_new (palette).bin"     -fullpalette -exit

cd ..
folder2c bank3 bank3 3

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
