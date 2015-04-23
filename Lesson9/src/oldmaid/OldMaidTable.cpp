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
    // �̂Ă�ꂽ�J�[�h��\������
    const Card* card = *it ;
    std::cout << *card  << " " ;

    // �̂Ă�ꂽ�J�[�h�̓��X�g�ɒǉ����ĕێ����Ă����B
    disposedCards_.push_back( card ) ;
  }

  std::cout << "���̂Ă܂���\n" ;
}


OldMaidTable::CardMultiArray_t OldMaidTable::getCards() const
{
  // �΂Δ����ł̓J�[�h������K�v�͂Ȃ����߁A�T�C�Y��0�̃��X�g��Ԃ�
  return CardMultiArray_t() ;
}

} // oldmaid
