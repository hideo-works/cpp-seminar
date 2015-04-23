#include "OldMaidPlayer.h"
#include "BackHand.h"
#include <trump/Rule.h>
#include <trump/Table.h>
#include <trump/Hand.h>
#include <trump/Master.h>
#include <trump/Card.h>

using namespace trump ;

namespace oldmaid {

OldMaidPlayer::OldMaidPlayer( const std::string& name, Master* master, Table* table, Rule* rule )
  : Player( name, master, table, rule )
{
  backHand_ = new BackHand( myHand_ ) ;
}


OldMaidPlayer::~OldMaidPlayer()
{
  delete backHand_ ;
}


void OldMaidPlayer::receiveCard( const Card* card )
{
  // 受け取ったカードを手札へ加える
  Player::receiveCard( card ) ;

  // ルールを使用してテーブルに出せるカードがあるか探す
  Rule::CardList_t candidate = rule_->findCandidate( myHand_, table_ ) ;

  // テーブルに出せるカードがある場合は場に出す
  if ( candidate.size() > 0 )
  {
    std::cout << *this << "：" ;
    table_->putCard( candidate ) ;
  }
}


void OldMaidPlayer::play( Player* nextPlayer )
{
  // 次のプレイヤーに手札を提示してもらう
  BackHand* nextPlayersHand = static_cast<OldMaidPlayer*>( nextPlayer )->showHand() ;

  // 相手の手札からカードを一枚引く
  int numberOfHands = nextPlayersHand->getNumberOfCards() ;
  const Card* pickedCard = nextPlayersHand->pickCard( rand() % numberOfHands ) ;

  // 引いた結果を表示
  std::cout << *this << "："
            << *nextPlayer << "さんから " << *pickedCard << " を引きました\n" ;

  // 引いたカードを自分の手札に加える
  myHand_->addCard( pickedCard ) ;

  // テーブルに出せるカードの組み合わせがあるか探す
  Rule::CardList_t sameCards = rule_->findCandidate( myHand_, table_ ) ;

  // 同じカードの組み合わせが存在した場合
  if ( sameCards.size() > 0 )
  {
    std::cout << *this << "：" ;
    table_->putCard( sameCards ) ;

    // 手札がゼロになったかどうか調べる
    if ( myHand_->getNumberOfCards() == 0 )
    {
      // 進行役に上がりを宣言する
      master_->declareWin( this ) ;
    }
  }

  // 現在の手札を表示
  std::cout << *this << "：残りの手札は " << *myHand_ << "です\n" ;
}


BackHand* OldMaidPlayer::showHand()
{
  // もしこの時点で手札が残り1枚ならば上がりとなるので宣言する
  if ( myHand_->getNumberOfCards() == 1 )
  {
    master_->declareWin( this ) ;
  }

  // 見せる前にシャッフルする
  myHand_->shuffle() ;

  // 相手に手札を裏から見せるため、BackHandを返す
  return backHand_ ;
}

} // oldmaid
