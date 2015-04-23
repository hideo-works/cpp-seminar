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
    // �̂Ă�ꂽ�J�[�h��\������
    const Card* card = *it ;
    std::cout << *card << " " ;

    // �̂Ă�ꂽ�J�[�h�̓��X�g�ɒǉ����ĕێ����Ă����B
    disposedCards_.push_back( card ) ;
  }

  std::cout << "���̂Ă܂���\n" ;
}
