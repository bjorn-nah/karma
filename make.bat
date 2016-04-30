@echo off

REM put here your favorite emulator directory
set emu_dir= "C:\dev\pce\mednafen\mednafen.exe"


mml2pce mml\musette.mml
huc -s main.c
pceas main.s


pause

%emu_dir% main.pce