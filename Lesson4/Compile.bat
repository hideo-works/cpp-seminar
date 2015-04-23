@ECHO OFF

REM ---------------------------------------------------------------------------
REM                        ���W���[���쐬�p�o�b�`
REM                �����s�ɂ� Borland C++ Compiler ���K�v
REM ---------------------------------------------------------------------------

REM [�K�v�Ȑݒ�]
REM ���ϐ� BORLAND_HOME ��
REM Borland C++ Compiler �̃C���X�g�[���f�B���N�g����ݒ肷��
REM   ex.) SET BORLAND_HOME=C:\Borland\BCC55
REM �Ȃ��A��L���e�� Initialize.bat ���Őݒ肵�Ă��ǂ�

REM [�O����]
SET OLD_PATH=%PATH%

REM [������]
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

REM [�R���p�C��]
@ECHO ON
bcc32 -I"%INC_PATH%" -L"%LIB_PATH%" -n%DST_DIR% -e%DST_EXE% %SRC_DIR%\*.cpp
@ECHO OFF

REM [�㏈��]
SET PATH=%OLD_PATH%
