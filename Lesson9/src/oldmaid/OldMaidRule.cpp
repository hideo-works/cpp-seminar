#include "OldMaidRule.h"
#include <trump/Hand.h>
#include <trump/Card.h>

using namespace trump ;

namespace oldmaid {

OldMaidRule::CardList_t OldMaidRule::findCandidate( Hand* hand, const Table* table )
{
  // 手札にあるカードを順番に見て同じ値の組み合わせを探す
  // 手札の逆側から調べているのは最後に追加されたカードから
  // 優先的にチェックして比較回数を減らすため
  int numberOfHand = hand->getNumberOfCards() ;
  for ( int position = numberOfHand - 1 ; position >= 0 ; --position )
  {
    const Card* firstCard = hand->lookCard( position ) ;
    for ( int comparePos = position - 1 ; comparePos >= 0 ; --comparePos )
    {
      const Card* secondCard = hand->lookCard( comparePos ) ;

      // 同じ値の組み合わせが見つかったらカードを引いて戻る
      if ( firstCard->getNumber() == secondCard->getNumber() )
      {
        CardList_t candidate ;
        candidate.push_back( hand->pickCard( position ) ) ;
        candidate.push_back( hand->pickCard( comparePos ) ) ;
        return candidate ;
      }
    }
  }

  // 同じ値が見つからなかった場合、サイズが0のリストを返す
  return CardList_t() ;
}

} // oldmaid
