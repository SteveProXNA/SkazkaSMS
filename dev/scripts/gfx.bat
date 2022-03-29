@echo off

cd ..
cd ..
cd gfx

:: Tiles
bmp2tile.exe raw/font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 0 -savetilemap "font_tiles (tilemap).stmcompr"  -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette -exit

cd ../dev
folder2c ../gfx gfx
mv gfx.h content
mv gfx.c content
cd content

sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 gfx.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ../scripts