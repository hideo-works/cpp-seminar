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
  // �J�[�h�����X�g�̍Ō�ɒǉ�����
  hand_.push_back( card ) ;
}


const Card* Hand::lookCard( int position ) const
{
  const Card* lookingCard = NULL ;

  // �����Ŏw�肳�ꂽ�ʒu���Ó��ł��邩�`�F�b�N���� 
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

  // �����Ŏw�肳�ꂽ�ʒu���Ó��ł��邩�`�F�b�N���� 
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
  // ��D�̖������擾
  int number = hand_.size() ;

  // �J�[�h�𔲂��o���ʒu
  int pos ;

  // �J�[�h�������_���ɔ�������čŌ�ɉ����铮����J��Ԃ�
  for ( int count = 0 ; count < number * 2 ; ++count )
  {
    // �����_���Ȉʒu����J�[�h���ꖇ�������
    pos = rand() % number ;
    CardList_t::iterator it = hand_.begin() ;
    std::advance( it, pos ) ;
    const Card* pickedCard = *it ;
    hand_.erase( it ) ;

    // ����������J�[�h���Ō�ɉ�����
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
