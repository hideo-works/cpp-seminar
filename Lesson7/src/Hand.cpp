#include "Hand.h"
#include "Card.h"
#include <sstream>

Hand::~Hand() {
  CardList_t::iterator it  = deal_.begin() ;
  CardList_t::iterator end = deal_.end() ;
  for ( ; it != end ; ++it ) delete *it ;
}


void Hand::addCard( const Card* card )
{
  // カードをリストの最後に追加する
  deal_.push_back( card ) ;
}


const Card* Hand::lookCard( int position ) const
{
  const Card* lookingCard = NULL ;

  // 引数で指定された位置が妥当であるかチェックする 
  if ( ( 0 <= position ) && ( position < deal_.size() ) )
  {
    CardList_t::const_iterator it = deal_.begin() ;
    std::advance( it, position ) ;
    lookingCard = *it ;
  }

  return lookingCard ;
}


const Card* Hand::pickCard( int position )
{
  const Card* pickedCard = NULL ;

  // 引数で指定された位置が妥当であるかチェックする 
  if ( ( 0 <= position ) && ( position < deal_.size() ) )
  {
    CardList_t::iterator it = deal_.begin() ;
    std::advance( it, position ) ;
    pickedCard = *it ;
    deal_.erase( it ) ;
  }

  return pickedCard ;
}


void Hand::shuffle()
{
  // 手札の枚数を取得
  int number = deal_.size() ;

  // カードを抜き出す位置
  int pos ;

  // カードをランダムに抜き取って最後に加える動作を繰り返す
  for ( int count = 0 ; count < number * 2 ; ++count )
  {
    // ランダムな位置からカードを一枚抜き取る
    pos = rand() % number ;
    CardList_t::iterator it = deal_.begin() ;
    std::advance( it, pos ) ;
    const Card* pickedCard = *it ;
    deal_.erase( it ) ;

    // 抜き取ったカードを最後に加える
    deal_.push_back( pickedCard ) ;
  }
}


int Hand::getNumberOfCards() const
{
  return deal_.size() ;
}


std::string Hand::toString() const
{
  std::ostringstream string ;

  int size = deal_.size() ;
  if ( size > 0 )
  {
    Hand::CardList_t::const_iterator it  = deal_.begin() ;
    Hand::CardList_t::const_iterator end = deal_.end() ;
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