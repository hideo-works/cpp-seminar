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

FOR /L %%I IN (2,1,9) DO CD Lesson%%I & CALL Compile & CD ..

