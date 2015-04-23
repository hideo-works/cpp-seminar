#ifndef FANTAN_H
#define FANTAN_H

#include "Executable.h"

class Hand ;

/**
 * 七並べプログラム。
 */
class Fantan : public Executable
{
public:
  // エントリポイント
  void main( int argc, char* argv[] ) ;

private:
  /**
   * 52枚のトランプを生成する。
   * 
   * @return トランプを格納したHand
   */
  static Hand* createTrump() ;
} ;

#endif // FANTAN_H
