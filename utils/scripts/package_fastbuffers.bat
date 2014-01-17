:: This script pack FastBuffers library for any platform in Windows.
::
:: This script needs the next environment variables to be run.
:: - SVN_BIN_DIR: Directory with the subversion binaries.
:: - LIBREOFFICE_BIN_DIR: Directory with the LibreOffice binaries.
:: - NSIS_BIN_DIR: Directory with the NSIS installer libraries.
:: - EPROSIMADIR: URL to the directory with common sources of eProsima.
:: - ANT_BIN_DIR: Directory with the ant binaries.
:: - DOXYGEN_BIN_DIR: Directory with the doxygen binaries.
:: - GRAPHVIZ_BIN_DIR: Directory with the graphviz binaries.
:: - TEXLIVE_BIN_DIR: Directory with the TexLive binaries.
:: Also this script needs the eProsima.documentation.changeVersion macro installed in the system.

setlocal EnableDelayedExpansion
setlocal EnableExpansion
@echo off

:: Initialize the returned value to 0 (all succesfully)
set errorstatus=0

if "%EPROSIMADIR%"=="" (
    echo "EPROSIMADIR environment variable has to be set"
    set errorstatus=-1
    goto :exit
)

:: Go to root directory
cd "..\.."

:: Update and compile CDR library.
cd "..\CDR"
:: Update CDR library.
svn update
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
:: Compile CDR library.
rmdir /S /Q lib\i86Win32VS2010
rmdir /S /Q lib\x64Win64VS2010
cd "utils\scripts"
call build_cdr.bat
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd "..\..\..\FastBuffers"

:: Get the current vesion of FastBuffers
call %EPROSIMADIR%\scripts\common_pack_functions.bat :getVersionFromCPP VERSION src\version.cpp
if not %errorstatus%==0 goto :exit

:: Update and compile FastBuffers application.
:: Update FastBuffers application.
svn update
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
:: Compile FastBuffers for target.
rmdir /S /Q build
call ant jar
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

:: Execute FastBuffers tests
set FAST_BUFFERS_OLD=%FAST_BUFFERS%
set FAST_BUFFERS=%CD%
cd utils/pcTests
call exec_tests.bat %package_targets%
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd ../..
set FAST_BUFFERS=%FAST_BUFFERS_OLD%

:: Create PDFS from documentation.
cd "doc"
:: Installation manual
soffice.exe --headless "macro:///eProsima.documentation.changeVersion(%CD%\Installation Manual.odt,%VERSION%)"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
:: User manual
soffice.exe --headless "macro:///eProsima.documentation.changeVersion(%CD%\User Manual.odt,%VERSION%)"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd ".."

:: Create README
soffice.exe --headless "macro:///eProsima.documentation.changeVersionToHTML(%CD%\README.odt,%VERSION%)"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit

:: Create doxygen information.
:: Generate the examples
:: CDR example
call scripts\fastbuffers.bat -replace -ser cdr -d utils\doxygen\examples\cdr utils\doxygen\examples\cdr\FooCdr.idl
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
:: Fast CDR example
call scripts\fastbuffers.bat -replace -ser fastcdr -d utils\doxygen\examples\fastcdr utils\doxygen\examples\fastcdr\FooFastCdr.idl
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
:: Export version
set VERSION_DOX=%VERSION%
mkdir output
mkdir output\doxygen
doxygen utils\doxygen\doxyfile
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd output\doxygen\latex
call make.bat
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd ..\..\..

:: Create installers.
cd "utils\installers\windows"
:: Win installer.
makensis.exe /DVERSION="%VERSION%" Setup.nsi
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :exit
cd "..\..\.."

rmdir /S /Q output

goto :exit

:: Function exit ::
:exit
if %errorstatus%==0 (echo "PACKAGING SUCCESSFULLY") else (echo "PACKAGING FAILED")
exit /b %errorstatus%
goto :EOF
