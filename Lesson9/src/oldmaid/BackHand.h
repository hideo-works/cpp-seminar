#ifndef BACKHAND_H
#define BACKHAND_H

namespace trump {

class Hand ;
class Card ;

} // trump

namespace oldmaid {

/**
 * 裏側から見た手札を表すクラス。
 * 隣のプレイヤーにカードを引かせる際、カードの裏側だけを見せるために
 * 使用できるメソッドを制限している。
 */
class BackHand
{
private:
  /** 手札 */
  trump::Hand* hand_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param hand 手札
   */
  BackHand( trump::Hand* hand ) ;

  /**
   * 枚数を数える。
   * 
   * @return 手札にあるカードの枚数
   */
  int getNumberOfCards() const ;

  /**
   * カードを引く。
   * 引いたカードは手札から削除される。
   * 
   * @param position カードの位置。
   * @return position で指定された位置のカード。範囲外の場合はnullを返す。
   */
  const trump::Card* pickCard( int position ) ;
} ;

} // oldmaid

#endif // BACKHAND_H
