@echo off
rem ===================
rem ** Configuration **
rem =================== 
rem - Nom du jeu -
set nom=prisonnier
rem - Nom du repertoir de sortie
set sortie=bin
rem - Nom du repertoir du code source
SET dsource=source

SET adrsdk=../../pvcollib

rem ===============================================================
rem ** Test si le repertoir de sortie existe sinon il est genere **
rem ===============================================================
:suite
if not exist %sortie% goto :newrep

echo ----------------------------------------------
echo -- compilation du projet %nom%
echo ----------------------------------------------
rem ===========================
rem ** Effacement du fichier **
rem ===========================
if exist "%sortie%\%nom%.rom" del %sortie%\%nom%.rom

echo -------------------------------------------
echo -- Creation de la ROM pour colecovision  --
echo -------------------------------------------

rem ================================
rem ** Compilation des fichiers C **
rem ================================ 
echo -----------------
echo -- compilation --
echo -----------------
for %%i in (%dsource%\*.c) do ( 
echo %%~nxi

rem 

sdcc -c -mz80  -I%adrsdk%/include --std-c99 --opt-code-size  %dsource%/%%~nxi
 )


pause


rem =================================
rem ** linkage des fichiers objets **
rem =================================
echo -------------
echo -- linkage --
echo -------------
rem C:\msys\msys\bin:
..\..\devkitcol\bin\sdcc -o coleco.ihx -mz80 --vc --no-std-crt0  --code-loc 0x8048 --data-loc 0x7000 %adrsdk%/lib/crtcol.rel %adrsdk%/lib/collib.lib *.rel 

echo -----------------------------
echo -- Creation du fichier rom --
echo -----------------------------
..\..\devkitcol\bin\sdobjcopy -R .sec5 -I ihex -O binary --pad-to 0xffff --gap-fill 0xff coleco.ihx %sortie%/%nom%.rom 

echo.
if exist "%sortie%/%nom%.rom" echo --- Le fichier %nom%.rom vient d'etre genere dans le repertoir %sortie% ---
echo.

rem ==============
rem ** Netoyage **
rem ==============
echo ----------------------------------------------------------------
echo - Debut effacement des fichiers sym,ihx,lk,noi,rel,lst,asm,map -
echo ----------------------------------------------------------------
pause


if exist "*.sym" del *.sym
if exist "*.ihx" del *.ihx
if exist "*.lk"  del *.lk
if exist "*.noi" del *.noi
if exist "*.rel" del *.rel
if exist "*.lst" del *.lst
if exist "*.asm" del *.asm
if exist "*.map" del *.map
pause


rem 
if exist "%sortie%/%nom%.rom" ..\..\emultwo\emultwo.exe %sortie%/%nom%.rom


exit



rem ===================================
rem ** Creation du dossier de sortie **
rem ===================================
:newrep
mkdir %sortie%
goto :suite