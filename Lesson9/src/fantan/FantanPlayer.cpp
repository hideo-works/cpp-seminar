#include "FantanPlayer.h"
#include "FantanMaster.h"
#include <trump/Card.h>
#include <trump/Hand.h>
#include <trump/Rule.h>
#include <trump/Table.h>

using namespace trump ;

namespace fantan {

FantanPlayer::FantanPlayer( const std::string& name, Master* master, Table* table, Rule* rule )
  : Player( name, master, table, rule ), pass_( 0 )
{
}


void FantanPlayer::receiveCard( const Card* card )
{
  if ( card->getNumber() == 7 )
  {
    // カードが7の場合は、テーブルにカードを置く
    std::cout << name_ << "：" << *card << "を置きました。\n" ;
    Table::CardList_t cards ;
    cards.push_back( card ) ;
    table_->putCard( cards ) ;
  }
  else
  {
    // カードが7でない場合は、受け取ったカードを手札へ加える
    Player::receiveCard( card ) ;
  }
}


void FantanPlayer::play( Player* nextPlayer )
{
  // 現在の手札を表示する
  std::cout << "  " << *myHand_ << "\n" ;

  // 現在の手札からテーブルに出せるものを探す
  Rule::CardList_t candidate = rule_->findCandidate( myHand_, table_ ) ;

  // 候補がある場合はテーブルに出す
  if ( candidate.size() > 0 )
  {
    std::cout << "  " << *candidate.front() << "を置きました。\n\n" ;
    table_->putCard( candidate ) ;

    // テーブルの状態を表示する
    std::cout << *table_ << "\n" ;

    // 手札がなくなったら、上がりを宣言する
    if ( myHand_->getNumberOfCards() == 0 )
    {
      master_->declareWin( this ) ;
    }
  }
  else
  {
    // テーブルに出せるカードがなかった場合、パスする
    ++pass_ ;
    static_cast<FantanMaster*>(master_)->pass( this ) ;

    // パス回数が制限回数以上ならばカードを全てテーブルに置く
    if ( pass_ > FantanMaster::PASS_LIMIT )
    {
      int numberOfHand = myHand_->getNumberOfCards() ;
      // 手札を全てテーブルに置く
      for ( int count = 0 ; count < numberOfHand ; ++count )
      {
        Table::CardList_t cards ;
        cards.push_back( myHand_->pickCard( 0 ) ) ;
        table_->putCard( cards ) ;
      }
    }
  }
}


int FantanPlayer::getPass() const
{
  return pass_ ;
}

} // fantan
