@ECHO OFF

REM ---------------------------------------------------------------------------
REM                        モジュール作成用バッチ
REM                ※実行には Borland C++ Compiler が必要
REM ---------------------------------------------------------------------------

REM [必要な設定]
REM 環境変数 BORLAND_HOME へ
REM Borland C++ Compiler のインストールディレクトリを設定する
REM   ex.) SET BORLAND_HOME=C:\Borland\BCC55
REM なお、上記内容は Initialize.bat 内で設定しても良い

REM [前処理]
SET OLD_PATH=%PATH%

REM [初期化]
IF EXIST ..\Initialize.bat CALL ..\Initialize.bat

SET INC_PATH=%BORLAND_HOME%\include
SET LIB_PATH=%BORLAND_HOME%\lib
SET BIN_PATH=%BORLAND_HOME%\bin

PATH=%BIN_PATH%;%PATH%

SET SRC_DIR=src
SET DST_DIR=Release
SET DST_EXE=Lesson4

IF NOT EXIST %DST_DIR% MKDIR %DST_DIR%
ERASE /F /Q %DST_DIR%\*.*

REM [コンパイル]
@ECHO ON
bcc32 -I"%INC_PATH%" -L"%LIB_PATH%" -n%DST_DIR% -e%DST_EXE% %SRC_DIR%\*.cpp
@ECHO OFF

REM [後処理]
SET PATH=%OLD_PATH%
