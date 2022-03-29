@echo off

cd ..
cd banks
cd bank12

:: Command

cd ..
folder2c bank12 bank12 12

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK12 bank12.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
