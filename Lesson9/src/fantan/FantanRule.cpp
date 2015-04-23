#include "FantanRule.h"
#include <trump/Hand.h>
#include <trump/Table.h>

using namespace trump ;

namespace fantan {

FantanRule::CardList_t FantanRule::findCandidate( Hand* hand, const Table* table )
{
  // テーブルに置けるカードの候補
  CardList_t candidate ;

  // 手札にあるカードを1枚ずつチェックして、テーブルに置けるか調べる
  int numberOfHand = hand->getNumberOfCards() ;
  for ( int position = 0 ; position < numberOfHand ; ++position )
  {
    // 手札にあるカードを見る
    const Card* lookingCard = hand->lookCard( position ) ;
    int number = lookingCard->getNumber() ;
    Card::SuitType suit = lookingCard->getSuit() ;

    // 今注目している手札の左か右にカードがあれば、カードを置ける
    int leftNumber = (number != 1) ? number - 1 : Card::CARD_NUM ;
    int rightNumber = (number != Card::CARD_NUM) ? number + 1 : 1 ;

    if ( ( true == this->isThereCard( table, suit, leftNumber ) )
      || ( true == this->isThereCard( table, suit, rightNumber ) ) )
    {
      // 手札からカードを引いて候補とする
      candidate.push_back( hand->pickCard( position ) ) ;
      break ;
    }
  }

  return candidate ;
}


bool FantanRule::isThereCard( const Table* table, Card::SuitType suit, int number ) const
{
  // テーブルにあるカードを調べ、カードが置かれているか調べる
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
