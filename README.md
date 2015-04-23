## 概要
このプログラムは、書籍「[なぜ、あなたはJavaでオブジェクト指向開発ができないのか](http://www.amazon.co.jp/exec/obidos/ASIN/477412222X/dotnetfan-22)」のサンプルプログラムをJavaからC++へ移植したものです。プログラムの詳細については、上記書籍をご参照ください。

## 環境
開発はMicrosoft VisualC++ 6.0 SP6で行いました。ビルド、実行の際には各Lessonフォルダ内のLesson*.dsw、もしくはAllProjects.dswを開いてください。

※ 追記  
Borland C++ Compiler 5.5でのコンパイル、実行に対応しました。コンパイルの際にはInitialize.bat内にBorland C++ Compilerのインストールディレクトリを設定した後、各Lessonフォルダの中にあるCompile.bat、もしくはAllCompile.batを実行してください。

## 備考
JavaからC++への移植において、できる限り元のサンプルの形をとどめることを優先して作業を行いました。C++向けに最適化されたものではありませんので、その点はご留意ください。

## 更新履歴
### 2005/02/08
ヘルプドキュメントを作成
- Lesson9のヘッダファイルを元にDoxygenを用いて自動作成
- Lesson9内のdocフォルダへ配置

### 2005/02/05
Borland C++ Compiler 5.5に対応
- コンパイルエラーの発生するソースを修正
- コンパイル用バッチファイルを作成

### 2005/02/01
初版リリース
