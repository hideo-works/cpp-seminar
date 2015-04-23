#ifndef CARD_H
#define CARD_H

#include <iostream>

namespace trump {

/**
 * トランプのカードを表すクラス。
 */
class Card
{
public:
  // カードの示すスートをあらわす定数
  enum SuitType {
    SUIT_SPADE   = 1, // スペード
    SUIT_DIAMOND = 2, // ダイヤ
    SUIT_CLUB    = 3, // クラブ
    SUIT_HEART   = 4  // ハート
  } ;

  /** スートの数 */
  static const int SUIT_NUM ;

  /** 値の数 */
  static const int CARD_NUM ;

protected:
  /** カードの示すスート */
  SuitType suit_ ;

  /** カードの示す数 */
  int number_ ;

public:
  /**
   * コンストラクタ。
   * スートと数を指定して新しいカードのインスタンスを生成する。
   * スートはSUIT_SPADE、SUIT_DIAMOND、SUIT_CLUB、SUIT_HEARTの
   * いずれかを指定する。
   * 
   * @param suit スート
   * @param number 数
   */
  Card( SuitType suit, int number ) ;

  /** デストラクタ。 */
  virtual ~Card() {}

  /**
   * 数を見る。
   * 
   * @return 数 
   */
  int getNumber() const ;

  /**
   * スートを見る。
   * 
   * @return スート 
   */
  SuitType getSuit() const ;

  /**
   * カードを文字列で表現する。
   * 
   * @return カードの文字表現
   */
  virtual std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Card& card ) ;

} // trump

#endif // CARD_H
