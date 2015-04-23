#include "Hand.h"
#include "Card.h"
#include <sstream>

Hand::~Hand() {
  CardList_t::iterator it  = hand_.begin() ;
  CardList_t::iterator end = hand_.end() ;
  for ( ; it != end ; ++it ) delete *it ;
}


void Hand::addCard( const Card* card )
{
  // カードをリストの最後に追加する
  hand_.push_back( card ) ;
}


const Card* Hand::pickCard()
{
  const Card* pickedCard = hand_.front() ;
  hand_.pop_front() ;

  return pickedCard ;
}


void Hand::shuffle()
{
  // 手札の枚数を取得
  int number = hand_.size() ;

  // カードを抜き出す位置
  int pos ;

  // カードをランダムに抜き取って最後に加える動作を繰り返す
  for ( int count = 0 ; count < number * 2 ; ++count )
  {
    // ランダムな位置からカードを一枚抜き取る
    pos = rand() % number ;
    CardList_t::iterator it = hand_.begin() ;
    std::advance( it, pos ) ;
    const Card* pickedCard = *it ;
    hand_.erase( it ) ;

    // 抜き取ったカードを最後に加える
    hand_.push_back( pickedCard ) ;
  }
}


int Hand::getNumberOfCards() const
{
  return hand_.size() ;
}


Hand::CardList_t Hand::findSameNumberCard()
{
  int numberOfCards = hand_.size() ;
  CardList_t sameCards ;

  // 手札にカードが1枚もない場合は何もしない
  if ( numberOfCards > 0 )
  {
    // 最後に追加されたカードを取得する
    CardList_t::iterator lastIt = --hand_.end() ;
    const Card* lastAddedCard = *lastIt ;

    // 最後に追加されたカードの数字を取得する
    int lastAddedCardNum = lastAddedCard->getNumber() ;

    CardList_t::iterator it = hand_.begin() ;
    for ( ; it != lastIt ; ++it )
    {
      const Card* card = *it ;
      if ( card->getNumber() == lastAddedCardNum )
      {
        // 最後に追加されたカードと同じカードが見つかった場合
        // 見つかった組み合わせをsameCardsに格納し、ループを抜ける
        sameCards.push_back( lastAddedCard ) ;
        hand_.erase( lastIt ) ;
        sameCards.push_back( card ) ;
        hand_.erase( it ) ;

        break ;
      }

      // 同じ数の組み合わせが見つからなかった場合、
      // sameCardsはサイズが0のままとなる。
    }
  }

  return sameCards ;
}


std::string Hand::toString() const
{
  std::ostringstream string ;

  int size = hand_.size() ;
  if ( size > 0 )
  {
    Hand::CardList_t::const_iterator it  = hand_.begin() ;
    Hand::CardList_t::const_iterator end = hand_.end() ;
    for ( ; it != end ; ++it )
    {
      const Card* card = *it ;
      string << *card << " " ;
    }
  }

  return string.str() ;
}


std::ostream& operator << ( std::ostream& output, const Hand& hand )
{
  output << hand.toString() ;
  return output ;
}