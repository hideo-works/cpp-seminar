#include "FantanRule.h"
#include <trump/Hand.h>
#include <trump/Table.h>

using namespace trump ;

namespace fantan {

FantanRule::CardList_t FantanRule::findCandidate( Hand* hand, const Table* table )
{
  // �e�[�u���ɒu����J�[�h�̌��
  CardList_t candidate ;

  // ��D�ɂ���J�[�h��1�����`�F�b�N���āA�e�[�u���ɒu���邩���ׂ�
  int numberOfHand = hand->getNumberOfCards() ;
  for ( int position = 0 ; position < numberOfHand ; ++position )
  {
    // ��D�ɂ���J�[�h������
    const Card* lookingCard = hand->lookCard( position ) ;
    int number = lookingCard->getNumber() ;
    Card::SuitType suit = lookingCard->getSuit() ;

    // �����ڂ��Ă����D�̍����E�ɃJ�[�h������΁A�J�[�h��u����
    int leftNumber = (number != 1) ? number - 1 : Card::CARD_NUM ;
    int rightNumber = (number != Card::CARD_NUM) ? number + 1 : 1 ;

    if ( ( true == this->isThereCard( table, suit, leftNumber ) )
      || ( true == this->isThereCard( table, suit, rightNumber ) ) )
    {
      // ��D����J�[�h�������Č��Ƃ���
      candidate.push_back( hand->pickCard( position ) ) ;
      break ;
    }
  }

  return candidate ;
}


bool FantanRule::isThereCard( const Table* table, Card::SuitType suit, int number ) const
{
  // �e�[�u���ɂ���J�[�h�𒲂ׁA�J�[�h���u����Ă��邩���ׂ�
  Table::CardMultiArray_t cards = table->getCards() ;
  if ( cards[suit - 1][number - 1] != NULL )
  {
    return true ;
  }
  else
  {
    return false ;
  }
}

} // fantan
