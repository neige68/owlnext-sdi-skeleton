@rem <exec.bat> -*- coding: cp932-dos -*-
@echo off
rem
rem Project owlnext-sdi-skeleton
rem Copyright (C) 2023 neige68
rem
rem Note: exec
rem
rem Windows:   XP and lator
rem

setlocal
pushd %~dp0
set @config=debug
set @bdir=build
set @arch=
set @toolset=
set @u=
set @name=sample
:loop
if "%1"=="--" goto optbreak
if "%1"=="64" goto build64
if "%1"=="143" goto build143
if "%1"=="r" goto rel
if "%1"=="rel" goto rel
if "%1"=="d" goto deb
if "%1"=="deb" goto deb
if "%1"=="u" goto unicode
if "%1"=="" goto optbreak
goto optend
:rel
set @config=release
shift
goto loop
:deb
set @config=debug
shift
goto loop
:unicode
set @u=u
shift
goto loop
:build143
set @toolset=.143
shift
goto loop
:build64
set @arch=64
shift
goto loop
:optbreak
shift
:optend
set @bdir=%@bdir%%@arch%%@u%%@toolset%
if not "%1"=="" set @name=%1
set @exe=%@bdir%\%@config%\%@name%.exe
if not exist %@bdir%\%@config%\%@name%.exe set @exe=%@bidr%\%@name%\%@config%\%@name%.exe
echo exec.bat: %@exe%
%@exe% %2 %3 %4 %5 %6 %7 %8 %9
goto :EOF
:help
echo usage: exec [143] [64] [u] [deb/rel] [--] name

@rem end of <exec.bat>
