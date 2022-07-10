@echo off

cd ..
cd banks
cd bank2

C:\SEGA\bmp2tile043\bmp2tile.exe raw/battle_enemies.png -savetiles "battle_enemies (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 160 -savetilemap "battle_enemies (tilemap).bin" -exit
C:\SEGA\bmp2tile043\bmp2tile.exe raw/battle_player.png  -savetiles "battle_player (tiles).psgcompr"    -removedupes -nomirror -planar -tileoffset 224 -savetilemap "battle_player (tilemap).bin"  -exit


C:\SEGA\bmp2tile043\bmp2tile.exe raw/koschey.png -savetiles "koschey (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 256  -savetilemap "koschey (tilemap).bin" -exit

C:\SEGA\bmp2tile043\bmp2tile.exe raw/logo_big.png   -savetiles "logo_big (tiles).psgcompr"   -noremovedupes -nomirror -planar -tileoffset 64  -savetilemap "logo_big (tilemap).bin"   -exit
C:\SEGA\bmp2tile043\bmp2tile.exe raw/logo_small.png -savetiles "logo_small (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 64  -savetilemap "logo_small (tilemap).bin" -exit

C:\SEGA\bmp2tile043\bmp2tile.exe raw/stats_inventory.png -savetiles "stats_inventory (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 160  -savetilemap "stats_inventory (tilemap).bin" -exit
C:\SEGA\bmp2tile043\bmp2tile.exe raw/stats_items.png     -savetiles "stats_items (tiles).psgcompr"     -noremovedupes -nomirror -planar -tileoffset 192  -savetilemap "stats_items (tilemap).bin"     -exit
C:\SEGA\bmp2tile043\bmp2tile.exe raw/stats_village.png   -savetiles "stats_village (tiles).psgcompr"   -noremovedupes -nomirror -planar -tileoffset 260  -savetilemap "stats_village (tilemap).bin"   -exit

cd ..
"C:\Program Files\SDCC\bin\folder2c" bank2 bank2 2

"C:\Program Files\SDCC\bin\sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
