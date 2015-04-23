#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>

class Card ;

/**
 * ばば抜きの手札を表すクラス。
 */
class Hand
{
public:
  typedef std::list<const Card*> CardList_t ;

private:
  /** 手札にあるカードを保持するためのリスト */
  CardList_t hand_ ;

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
   * カードを引く。
   * 
   * @return 引いたカード
   */
  const Card* pickCard() ;

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
   * 同じ数のカードを探す。
   * 同じ数のカードがない場合はサイズが0のリストを返します。
   * 
   * @return 同じ数のカード
   */
  CardList_t findSameNumberCard() ;

  /**
   * 手札にあるカードを文字列で表現する。
   * 
   * @return 手札にあるカードの文字列表現
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Hand& hand ) ;

#endif // HAND_H
