#include "Hand.h"
#include "Card.h"
#include <sstream>

namespace trump {

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


const Card* Hand::lookCard( int position ) const
{
  const Card* lookingCard = NULL ;

  // 引数で指定された位置が妥当であるかチェックする 
  if ( ( 0 <= position ) && ( position < hand_.size() ) )
  {
    CardList_t::const_iterator it = hand_.begin() ;
    std::advance( it, position ) ;
    lookingCard = *it ;
  }

  return lookingCard ;
}


const Card* Hand::pickCard( int position )
{
  const Card* pickedCard = NULL ;

  // 引数で指定された位置が妥当であるかチェックする 
  if ( ( 0 <= position ) && ( position < hand_.size() ) )
  {
    CardList_t::iterator it = hand_.begin() ;
    std::advance( it, position ) ;
    pickedCard = *it ;
    hand_.erase( it ) ;
  }

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

} // trump
