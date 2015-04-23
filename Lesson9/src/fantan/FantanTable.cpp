#include "FantanTable.h"
#include <trump/Card.h>
#include <sstream>

using namespace trump ;

namespace fantan {

FantanTable::FantanTable()
{
  for ( int suit = 0 ; suit < Card::SUIT_NUM ; ++suit )
  {
    // Borland C++ Compiler で Error が出るため修正
//    CardArray_t array( Card::CARD_NUM, NULL ) ;
    const Card* card = NULL ;
    CardArray_t array( Card::CARD_NUM, card ) ;
    table_.push_back( array ) ;
  }
}


FantanTable::~FantanTable()
{
  for ( int suit = 0 ; suit < Card::SUIT_NUM ; ++suit )
  {
    for ( int number = 0; number < Card::CARD_NUM ; ++number )
    {
      if ( table_[suit][number] != NULL ) delete table_[suit][number] ;
    }
  }
}


void FantanTable::putCard( const CardList_t& cards )
{
  const Card* card = cards.front() ;

  int number = card->getNumber() ;
  Card::SuitType suit = card->getSuit() ;
  
  // テーブルにカードを置く
  table_[suit - 1][number - 1] = card ;
}


FantanTable::CardMultiArray_t FantanTable::getCards() const
{
  return table_ ;
}


std::string FantanTable::toString() const
{
  std::ostringstream string ;

  for ( int suit = 0 ; suit < Card::SUIT_NUM ; ++suit )
  {
    for ( int number = 0 ; number < Card::CARD_NUM ; ++number )
    {
      if ( table_[suit][number] != NULL )
      {
        string << *table_[suit][number] ;
      }
      else
      {
        string << ".." ;
      }

      string << " " ;
    }
    
    string << "\n" ;
  }
  
  return string.str() ;
}

} // fantan
