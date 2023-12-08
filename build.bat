@rem <build.bat> -*- coding: cp932-dos -*-
@echo off
rem
rem Project owlnext-sdi-skeleton
rem Copyright (C) 2023 neige68
rem
rem Note: build
rem
rem Windows:   XP and lator
rem

setlocal
pushd %~dp0

set @IONICE=
if not "%1"=="fg" set @IONICE=ionicev

setlocal
set @BDIR=build
set @VC=%VC142%
set @ARCH=x86
set @CMAKEG=-G "Visual Studio 16 2019" -A Win32
set @CHARCODE=MBCS
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=buildu
set @VC=%VC142%
set @ARCH=x86
set @CMAKEG=-G "Visual Studio 16 2019" -A Win32
set @CHARCODE=UNICODE
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=build64
set @VC=%VC142%
set @ARCH=x64
set @CMAKEG=-G "Visual Studio 16 2019" -A x64
set @CHARCODE=MBCS
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=build64u
set @VC=%VC142%
set @ARCH=x64
set @CMAKEG=-G "Visual Studio 16 2019" -A x64
set @CHARCODE=UNICODE
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=build.143
set @VC=%VC143%
set @ARCH=x86
set @CMAKEG=-G "Visual Studio 17 2022" -A Win32
set @CHARCODE=MBCS
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=buildu.143
set @VC=%VC143%
set @ARCH=x86
set @CMAKEG=-G "Visual Studio 17 2022" -A Win32
set @CHARCODE=UNICODE
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=build64.143
set @VC=%VC143%
set @ARCH=x64
set @CMAKEG=-G "Visual Studio 17 2022" -A x64
set @CHARCODE=MBCS
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

setlocal
set @BDIR=build64u.143
set @VC=%VC143%
set @ARCH=x64
set @CMAKEG=-G "Visual Studio 17 2022" -A x64
set @CHARCODE=UNICODE
echo INFO: build.bat: %@BDIR% %@ARCH% %@CMAKEG% %@CHARCODE%
call buildv.bat 
endlocal
if errorlevel 1 goto err

goto end

:err
echo ERROR: build.bat: ÉGÉâÅ[Ç™Ç†ÇËÇ‹Ç∑.
:end
popd

rem end of <build.bat>
