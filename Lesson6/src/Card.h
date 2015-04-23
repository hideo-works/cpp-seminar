#ifndef CARD_H
#define CARD_H

#include <iostream>

/**
 * トランプのカードを表すクラス。
 */
class Card
{
public:
  // カードの示すスートをあらわす定数
  enum SuitType {
    JOKER        = 0, // ジョーカー
    SUIT_SPADE   = 1, // スペード
    SUIT_DIAMOND = 2, // ダイヤ
    SUIT_CLUB    = 3, // クラブ
    SUIT_HEART   = 4  // ハート
  } ;

private:
  /** カードの示すスート */
  SuitType suit_ ;
  
  /** カードの示す数 */
  int number_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param suit スート
   * @param number 数 (0の場合はジョーカーとして扱う)
   */
  Card( SuitType suit, int number ) ;

  /** デストラクタ。 */
  virtual ~Card() {}

  /**
   * 数字を見る。
   * 
   * @return 数 
   */
  int getNumber() const ;

  /**
   * カードを文字列で表現する。
   * 
   * @return カードの文字表現
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Card& card ) ;

#endif // CARD_H
