#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>

class Card ;

/**
 * 手札を表すクラス。
 */
class Hand
{
private:
  typedef std::list<const Card*> CardList_t ;

  /** 手札にあるカードを保持するためのリスト */
  CardList_t deal_ ;

public:
  /** デストラクタ。 */
  virtual ~Hand() ;

  /**
   * カードを加える。
   * 
   * @param card 加えるカード
   */
  void addCard( const Card* card ) ;

  /**
   * 手札にあるカードを見る。
   * positionは 0 から getNumberOfCards() の範囲で指定するすること。
   * 
   * @param position カードの位置。
   * @return position で指定された位置のカード。範囲外の場合はnullを返す。
   */
  const Card* lookCard( int position ) const ;

  /**
   * 手札からカードを引く。
   * 引いたカードは手札から削除される。
   * 
   * @param position カードの位置。
   * @return position で指定された位置のカード。範囲外の場合はnullを返す。
   */
  const Card* pickCard( int position ) ;

  /**
   * シャッフルする。
   */
  void shuffle() ;

  /**
   * 枚数を数える。
   * 
   * @return 手札にあるカードの枚数
   */
  int getNumberOfCards() const ;

  /**
   * 手札にあるカードを文字列で表現する。
   * 
   * @return 手札にあるカードの文字列表現
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Hand& hand ) ;

#endif // HAND_H
