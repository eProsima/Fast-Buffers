:: This script runs all tests in this directory and checks their results. Supports two optional parameters.
:: @param The unit test to be run. If it isn't set, then all unit tests are run.
:: @param Second parameter is the used architecture. Supported i86 and x64. If it isn't set all architectures are used.

setlocal EnableDelayedExpansion
@echo off

:: Initialize the returned value to 0 (all succesfully)
set errorstatus=0
set test_selected=
:: @default, all targets are used (i86 and x64)
set test_targets=

:: Get number of arguments
set argC=0
for %%x in (%*) do set /A argC+=1

:: Get the optional parameter
if %argC% geq 1 (
    if "%1"=="i86" set test_targets=%1
    if "%1"=="x64" set test_targets=%1
    if "!test_targets!"=="" (
        set test_selected=%1

        if %argC% geq 2 (
            if "%2"=="i86" set test_targets=%2
            if "%2"=="x64" set test_targets=%2
            if "!test_targets!"=="" (
                echo Error: Bad argument in second parameter. Valid values: i86, x64
                exit /b -1
            )
        )
    )
)

:: Find all directories.
for /D %%D in ("*") do (
   set exec_test_bool=0
   set exec_target_bool=0
   if "%test_selected%"=="" set exec_test_bool=1
   if "%test_selected%"=="%%D" set exec_test_bool=1
   if !exec_test_bool!==1 (
      :: Exec internal batch file
      if exist "%%D\exec_test.bat" (
	 :: i86 target
         if %errorstatus%==0 (
            if "%test_targets%"=="" set exec_target_bool=1
            if "%test_targets%"=="i86" set exec_target_bool=1
            if !exec_target_bool!==1 (
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTarget i86Win32VS2010
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTargetPath ..\..\..\lib\%EPROSIMA_TARGET%
                call "%%D\exec_test.bat"
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTargetPath
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTarget
            )
         )
	 ::x64 target
         if %errorstatus%==0 (
            if "%test_targets%"=="" set exec_target_bool=2
            if "%test_targets%"=="x64" set exec_target_bool=2
            if !exec_target_bool!==2 (
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTarget x64Win64VS2010
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTargetPath ..\..\..\lib\%EPROSIMA_TARGET%
                call "%%D\exec_test.bat"
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTargetPath
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTarget
            )
         )
      ) else (
	 :: i86 target
         if %errorstatus%==0 (
            if "%test_targets%"=="" set exec_target_bool=3
            if "%test_targets%"=="i86" set exec_target_bool=3
            if !exec_target_bool!==3 (
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTarget i86Win32VS2010
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTargetPath ..\..\..\lib\%EPROSIMA_TARGET%
                call :execTest %%D Win32
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTargetPath
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTarget
            )
         )
	 ::x64 target
         if %errorstatus%==0 (
            if "%test_targets%"=="" set exec_target_bool=4
            if "%test_targets%"=="x64" set exec_target_bool=4
            if !exec_target_bool!==4 (
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTarget x64Win64VS2010
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat setTargetPath ..\..\..\lib\%EPROSIMA_TARGET%
                call :execTest %%D x64
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTargetPath
                call %EPROSIMADIR%\scripts\common_exectest_functions.bat restoreTarget
            )
         )
      )
   )

   :: Detect error in call.
   if not !errorstatus!==0 goto :exit
)
goto :exit

:: This function execute a test in a directory.
:: @param Name/Directory of the test
:: @param Plaform for Visual Studio.
:execTest
:: CDR unit test
:: Clean output directory
if exist output rd /S /Q output
mkdir output
::Info about test
echo "EXECUTING %1 for %EPROSIMA_TARGET% using CDR"
:: Generates the file with RPCDDS script
call ..\..\scripts\fastbuffers.bat -d output -ser cdr -local -example %EPROSIMA_TARGET% "%1\%1.idl"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Compile the generated library in each configuration.
:: Release DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Release DLL" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Debug DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Debug DLL" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Release Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Release" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Debug Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Debug" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Copy static test files into output directory
copy %1\* output\
if not %errorstatus%==0 goto :EOF
:: Compile the application test in RELEASE.
:: Release DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1Test.sln" /t:Build /p:Configuration="Release" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Execute the test application
output\bin\%EPROSIMA_TARGET%\%1Test
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF

:: FastCDR unit test
:: Clean output directory
if exist output rd /S /Q output
mkdir output
::Info about test
echo "EXECUTING %1 for %EPROSIMA_TARGET% using CDR"
:: Generates the file with RPCDDS script
call ..\..\scripts\fastbuffers.bat -d output -ser fastcdr -local -example %EPROSIMA_TARGET% "%1\%1.idl"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Compile the generated library in each configuration.
:: Release DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Release DLL" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Debug DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Debug DLL" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Release Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Release" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Debug Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Build /p:Configuration="Debug" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Copy static test files into output directory
copy %1\* output\
if not %errorstatus%==0 goto :EOF
:: Compile the application test in RELEASE.
:: Release DLL Configuration
:: Clean the visual solution
msbuild "output\%1-%EPROSIMA_TARGET%.sln" /t:Clean /p:Platform="%2"
:: Build the visual solution
msbuild "output\%1Test.sln" /t:Build /p:Configuration="Release" /p:Platform="%2"
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF
:: Execute the test application
output\bin\%EPROSIMA_TARGET%\%1Test
set errorstatus=%ERRORLEVEL%
if not %errorstatus%==0 goto :EOF

goto :EOF

:: Function exit ::
:exit
:: Remove output directory
rd /S /Q output

if %errorstatus%==0 (echo "TEST SUCCESFULLY") else (echo "TEST FAILED")
exit /b %errorstatus%
goto :EOF
