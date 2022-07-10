@echo off

cd ..
cd banks
cd bank3

:: Command

cd ..
::folder2c bank3 bank3 3

::sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c
sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 fixedbank.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
