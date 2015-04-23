#include "OldMaidTable.h"
#include <trump/Card.h>

using namespace trump ;

namespace oldmaid {

OldMaidTable::~OldMaidTable()
{
  CardList_t::iterator it  = disposedCards_.begin() ;
  CardList_t::iterator end = disposedCards_.end() ;
  for ( ; it != end ; ++it ) delete *it ;
}


void OldMaidTable::putCard( const CardList_t& cards )
{
  CardList_t::const_iterator it  = cards.begin() ;
  CardList_t::const_iterator end = cards.end() ;
  for ( ; it != end ; ++it )
  {
    // 捨てられたカードを表示する
    const Card* card = *it ;
    std::cout << *card  << " " ;

    // 捨てられたカードはリストに追加して保持しておく。
    disposedCards_.push_back( card ) ;
  }

  std::cout << "を捨てました\n" ;
}


OldMaidTable::CardMultiArray_t OldMaidTable::getCards() const
{
  // ばば抜きではカードを見る必要はないため、サイズが0のリストを返す
  return CardMultiArray_t() ;
}

} // oldmaid
