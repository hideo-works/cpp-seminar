#include "Table.h"
#include "Card.h"
#include <iostream>

Table::~Table()
{
  CardList_t::iterator it  = disposedCards_.begin() ;
  CardList_t::iterator end = disposedCards_.end() ;
  for ( ; it != end ; ++it ) delete *it ;
}


void Table::disposeCard( const CardList_t& cards )
{
  CardList_t::const_iterator it  = cards.begin() ;
  CardList_t::const_iterator end = cards.end() ;
  for ( ; it != end ; ++it )
  {
    // 捨てられたカードを表示する
    const Card* card = *it ;
    std::cout << *card << " " ;

    // 捨てられたカードはリストに追加して保持しておく。
    disposedCards_.push_back( card ) ;
  }

  std::cout << "を捨てました\n" ;
}
