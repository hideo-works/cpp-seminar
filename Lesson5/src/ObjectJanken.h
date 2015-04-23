#ifndef OBJECTJANKEN_H
#define OBJECTJANKEN_H

#include "Executable.h"

/**
 * 戦略インターフェースに対応したジャンケンプログラム。
 */
class ObjectJanken : public Executable
{
public:
  // エントリポイント
  void main( int argc, char* argv[] ) ;
} ;

#endif // OBJECTJANKEN_H
