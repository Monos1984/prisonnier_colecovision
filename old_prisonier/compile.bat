@echo off
set path=c:\PROGRAMMATION\COLECOVISION\sdcc\bin;%path%
cls
echo ----------------------------- DEBUT -----------------------------

echo -- COMPILATION --
sdcc -mz80 -c --std-c99 --opt-code-speed main.c


echo -- LINKAGE --
sdcc -mz80 --code-loc 0x8024 --data-loc 0x7000 --no-std-crt0 ./rel/crtcv.rel ./rel/cvlib.lib ./rel/getput.lib ./rel/comp.lib main.rel

echo -- CREATION DE LA ROM --
objcopy --input-target=ihex --output-target=binary crtcv.ihx ./out/prisonier.rom

echo -- NETTOYAGE --
del *.sym *.ihx *.lk *.noi *.rel *.lst *.asm *.map

echo ----------------------------- FINISH -----------------------------
