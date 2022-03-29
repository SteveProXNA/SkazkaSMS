#!/bin/sh

# Time build START
# Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
#set _time=%time: =0%
#set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
#set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


# Compile
cd banks
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK15 fixedbank.c
cd ..

cd devkit
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 _sms_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 _snd_manager.c
cd ..

cd engine
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 asm_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 audio_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 content_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enemy_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enum_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fight_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 font_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 game_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 global_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 hack_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 input_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 locale_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 player_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 random_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 sample_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 screen_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 select_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 text_manager.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 timer_manager.c
cd ..

cd object
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 audio_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enemy_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 game_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 hack_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 player_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 select_object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 timer_object.c
cd ..

cd screen
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 none_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 splash_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 title_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 diff_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 load_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 start_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stats_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 forest_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 victory_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 shop_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 talk_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 prep_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 boss_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 complete_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 menu_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 relive_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 over_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 test_screen.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 func_screen.c
cd ..

sdcc --debug -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


# Time build -END-
#set _time=%time: =0%
#set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
#set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
#set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
#echo.
#echo Time taken: %_sec:~-2%.%_cs:~-2% secs
#echo.


# Link
sdcc --debug -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 \
../crt0/crt0_sms.rel main.rel \
-Wl-b_BANK2=0x8000  -Wl-b_BANK3=0x8000  -Wl-b_BANK4=0x8000  -Wl-b_BANK5=0x8000 \
-Wl-b_BANK6=0x8000  -Wl-b_BANK7=0x8000  -Wl-b_BANK8=0x8000  -Wl-b_BANK9=0x8000 \
-Wl-b_BANK10=0x8000 -Wl-b_BANK11=0x8000 -Wl-b_BANK12=0x8000 -Wl-b_BANK13=0x8000 \
-Wl-b_BANK14=0x8000 -Wl-b_BANK15=0x8000 \
../lib/SMSlib.lib \
../lib/PSGlib.rel \
banks/bank2.rel  banks/bank3.rel  banks/bank4.rel  banks/bank5.rel \
banks/bank6.rel  banks/bank7.rel  banks/bank8.rel  banks/bank9.rel \
banks/bank10.rel banks/bank11.rel banks/bank12.rel banks/bank13.rel \
banks/bank14.rel banks/fixedbank.rel \
devkit/_sms_manager.rel devkit/_snd_manager.rel \
engine/asm_manager.rel engine/audio_manager.rel engine/content_manager.rel engine/enum_manager.rel \
engine/enemy_manager.rel engine/fight_manager.rel engine/font_manager.rel engine/game_manager.rel \
engine/global_manager.rel engine/hack_manager.rel engine/input_manager.rel engine/player_manager.rel \
engine/random_manager.rel engine/sample_manager.rel engine/screen_manager.rel engine/select_manager.rel \
engine/text_manager.rel engine/timer_manager.rel \
object/audio_object.rel object/enemy_object.rel object/game_object.rel object/hack_object.rel \
object/player_object.rel object/select_object.rel object/timer_object.rel \
screen/none_screen.rel screen/splash_screen.rel screen/title_screen.rel screen/diff_screen.rel \
screen/intro_screen.rel screen/load_screen.rel screen/start_screen.rel screen/stats_screen.rel \
screen/forest_screen.rel screen/victory_screen.rel screen/shop_screen.rel  screen/talk_screen.rel \
screen/prep_screen.rel screen/boss_screen.rel screen/complete_screen.rel screen/menu_screen.rel \
screen/relive_screen.rel screen/over_screen.rel screen/test_screen.rel screen/func_screen.rel \
content/gfx.rel

# Execute
ihx2sms output.ihx output.sms


# Delete
cd banks
rm -f *.asm 2> /dev/null && rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null
cd ..

cd devkit
rm -f *.asm 2> /dev/null && rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null
cd ..

cd engine
rm -f *.asm 2> /dev/null && rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null
cd ..

cd object
rm -f *.asm 2> /dev/null && rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null
cd ..

cd screen
rm -f *.asm 2> /dev/null && rm -f *.lst 2> /dev/null && rm -f *.sym 2> /dev/null
cd ..

rm -f *.asm 2> /dev/null && rm -f *.ihx 2> /dev/null
rm -f *.lk  2> /dev/null && rm -f *.lst 2> /dev/null
#rm -f *.noi 2> /dev/null
rm -f *.sym 2> /dev/null

# Run
java -jar ~/Sega/Emulicious/Emulicious.jar output.sms
#output.sms