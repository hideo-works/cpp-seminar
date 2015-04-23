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

FOR /L %%I IN (2,1,9) DO CD Lesson%%I & CALL Compile & CD ..

