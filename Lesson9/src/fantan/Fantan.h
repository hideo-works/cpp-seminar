#ifndef FANTAN_H
#define FANTAN_H

#include <Executable.h>

namespace trump {

class Hand ;

} // trump

namespace fantan {

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
  static trump::Hand* createTrump() ;
} ;

} // fantan

#endif // FANTAN_H
