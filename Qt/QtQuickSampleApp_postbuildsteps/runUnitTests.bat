@title Run QtQuick Sample Application Unit Tests
@echo off
set QTDIR=C:\Qt\Qt5.2.1\5.2.1\msvc2012_64_opengl\bin
set OUTDIR=%1
set ISDEBUG=%2

@echo =================================
@echo Setting up and Running Unit Tests
@echo =================================

if EXIST %OUTDIR%\test.log ( del /Q %OUTDIR%\test.log )

xcopy /Y /D %QTDIR%\icudt51.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

xcopy /Y /D %QTDIR%\icuin51.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

xcopy /Y /D %QTDIR%\icuuc51.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

if [%ISDEBUG%] == [YES] (
xcopy /Y /D %QTDIR%\Qt5Cored.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

xcopy /Y /D %QTDIR%\Qt5Testd.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

) else (
xcopy /Y /D %QTDIR%\Qt5Core.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)

xcopy /Y /D %QTDIR%\Qt5Test.dll %OUTDIR%
if NOT [%errorlevel%] == [0] (goto ERROR)
)

REM In Linux QtQuickSampleTest.exe outputs messages
REM to the STDOUT and they get shown in the Compile
REM Output window in QtCreator however under Windows
REM no messages are shown (just the below command to 
REM execute the test). To work around this I'm outputting
REM to a file and displaying the file contents after the
REM test run.
%OUTDIR%\QtQuickSampleTest.exe -o %OUTDIR%\test.log
type %OUTDIR%\test.log
del /Q %OUTDIR%\test.log

goto :EOL

:ERROR
@echo Something went wrong in trying to run the test
goto EOL

:EOL
@echo =================================
@echo Finished Running Unit Tests
@echo =================================