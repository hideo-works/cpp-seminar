#ifndef SIMPLEJANKEN_H
#define SIMPLEJANKEN_H

#include "Executable.h"

/**
 * オブジェクト指向を使用しないジャンケンプログラム
 */
class SimpleJanken : public Executable
{
public:
  // ジャンケンの手を表す定数
  enum HandType {
    STONE    = 0, // グー
    SCISSORS = 1, // チョキ
    PAPER    = 2  // パー
  } ;

public:
  // エントリポイント
  void main( int argc, char* argv[] ) ;
} ;

#endif // SIMPLEJANKEN_H