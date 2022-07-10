@echo off
::psg		Commonly used psg	not banked

cd ..
cd content
::cd psg

::cd ..
folder2c psg psg

sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 psg.c

if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul


cd ..
cd scripts