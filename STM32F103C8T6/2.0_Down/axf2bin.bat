@echo off
setlocal

set INPUT=%~1

if "%INPUT%"=="" (
    echo Drag a .axf file here.
    pause
    exit /b
)

set OUTDIR=%~dp0

for %%f in ("%INPUT%") do (
    set NAME=%%~nf
)

echo Converting...
echo.

"D:\Keil\ARM\ARMCC\bin\fromelf.exe" --bin "%INPUT%" --output "%OUTDIR%%NAME%.bin"

echo Done:
echo %OUTDIR%%NAME%.bin

pause
endlocal