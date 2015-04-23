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
  // �J�[�h�����X�g�̍Ō�ɒǉ�����
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


Hand::CardList_t Hand::findSameNumberCard()
{
  int numberOfCards = hand_.size() ;
  CardList_t sameCards ;

  // ��D�ɃJ�[�h��1�����Ȃ��ꍇ�͉������Ȃ�
  if ( numberOfCards > 0 )
  {
    // �Ō�ɒǉ����ꂽ�J�[�h���擾����
    CardList_t::iterator lastIt = --hand_.end() ;
    const Card* lastAddedCard = *lastIt ;

    // �Ō�ɒǉ����ꂽ�J�[�h�̐������擾����
    int lastAddedCardNum = lastAddedCard->getNumber() ;

    CardList_t::iterator it = hand_.begin() ;
    for ( ; it != lastIt ; ++it )
    {
      const Card* card = *it ;
      if ( card->getNumber() == lastAddedCardNum )
      {
        // �Ō�ɒǉ����ꂽ�J�[�h�Ɠ����J�[�h�����������ꍇ
        // ���������g�ݍ��킹��sameCards�Ɋi�[���A���[�v�𔲂���
        sameCards.push_back( lastAddedCard ) ;
        hand_.erase( lastIt ) ;
        sameCards.push_back( card ) ;
        hand_.erase( it ) ;

        break ;
      }

      // �������̑g�ݍ��킹��������Ȃ������ꍇ�A
      // sameCards�̓T�C�Y��0�̂܂܂ƂȂ�B
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