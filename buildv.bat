@rem <buildv.bat> -*- coding: cp932-dos -*-
@echo off
rem
rem Project owlnext-sdi-skeleton
rem Copyright (C) 2023 neige68
rem
rem Note: build variation
rem
rem Windows:   XP and lator
rem

setlocal
call "%@VC%\vcvarsall.bat" %@ARCH%
if not exist %@BDIR% mkdir %@BDIR%
pushd %@BDIR%
set @CMAKEOPT=
if "%@CHARCODE%"=="UNICODE" set @CMAKEOPT=-D UNICODE=1
echo cmake...
cmake %@CMAKEG% .. %@CMAKEOPT%
echo ...cmake end
%@IONICE% msbuild ALL_BUILD.vcxproj /m
if errorlevel 1 goto err
%@IONICE% msbuild ALL_BUILD.vcxproj /m /p:Configuration=Release
if errorlevel 1 goto err
goto end

:err
echo ERROR: buildv.bat: ÉGÉâÅ[Ç™Ç†ÇËÇ‹Ç∑.
popd
exit /b 1
:end
endlocal
popd

rem end of <buildv.bat>
