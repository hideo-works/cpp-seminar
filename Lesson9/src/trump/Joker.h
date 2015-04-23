#ifndef JOKER_H
#define JOKER_H

#include "Card.h"
#include <iostream>

namespace trump {

/**
 * ジョーカーを表すクラス。
 * Cardクラスを継承している。
 * setNumber()、setSuit()メソッドを利用することで、どのようなカードとしても
 * 扱うことができる。
 */
class Joker : public Card
{
public:
  /**
   * コンストラクタ。
   * デフォルトでは、ジョーカーは何の値・スートも表さない。 
   * getNumber()、getSuit()は0を返す。
   */
  Joker() ;

  /**
   * 数を変更する。
   * 
   * @param number 数
   */
  void setNumber( int number ) ;

  /**
   * スートを変更する。
   * @param suit
   */
  void setSuit( Card::SuitType suit ) ;

  /**
   * カードを文字列で表現する。
   * 
   * @return カードの文字表現
   */
  std::string toString() const ;
} ;

} // trump

#endif // JOKER_H
