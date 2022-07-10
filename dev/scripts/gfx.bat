@echo off
::gfx		Commonly used gfx	not banked

cd ..
cd content
cd gfx

:: Tiles
bmp2tile.exe raw/font.png -savetiles "font (tiles).psgcompr" -noremovedupes -planar -tileoffset 0  -savetilemap "font (tilemap).bin" -savepalette "background (palette).bin" -fullpalette -exit
bmp2tile.exe raw/border.png -savetiles "border (tiles).psgcompr" -noremovedupes -planar -tileoffset 48  -savetilemap "border (tilemap).bin" -exit

bmp2tile.exe raw/battle_enemies_leshy.png -savetiles "battle_enemies_leshy (tiles).psgcompr" -noremovedupes -planar -tileoffset 260  -savetilemap "battle_enemies_leshy (tilemap).bin" -savepalette "sprite (palette).bin" -fullpalette -exit

cd ..
folder2c gfx gfx

sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 gfx.c

if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul


cd ..
cd scripts