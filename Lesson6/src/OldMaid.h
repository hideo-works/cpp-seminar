#ifndef OLDMAID_H
#define OLDMAID_H

#include "Executable.h"

class Hand ;

/**
 * ばば抜きプログラム。
 */
class OldMaid : public Executable
{
public:
  // エントリポイント
  void main( int argc, char* argv[] ) ;

private:
  /**
   * 53枚のトランプを生成する。
   * 
   * @return トランプを格納したHand
   */
  static Hand* createTrump() ;
} ;

#endif // OLDMAID_H
