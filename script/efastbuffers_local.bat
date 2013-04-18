@echo off
setlocal

set dir=%~dp0

set args=%1

:getarg
shift
if "%~1"=="" goto continue
set args=%args% %1
goto getarg

:continue
if "%JAVA_HOME%"=="" (
   echo "JAVA_HOME environment variable was not set"
   exit /B 65
)
"%JAVA_HOME%\bin\java" -Djava.ext.dirs="%dir%\..\lib" com.eprosima.ebuffers.eBuffers %args%
