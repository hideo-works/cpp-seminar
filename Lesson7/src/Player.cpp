#include "Player.h"
#include "Table.h"
#include "Hand.h"
#include "Card.h"
#include "Master.h"

Player::Player( const std::string& name, Master* master, Table* table )
  : name_( name ), master_( master ), table_( table ), pass_( 0 )
{
  myHand_ = new Hand() ;
}


Player::~Player()
{
  delete myHand_ ;
}


void Player::play()
{
  // 現在の手札を表示する
  std::cout << "  " << *myHand_ << "\n" ;
  
  // 手札にあるカードを1枚ずつチェックして、場に置けるか調べる
  int handSize = myHand_->getNumberOfCards() ;
  for ( int position = 0 ; position < handSize ; ++position )
  {
    // 手札にあるカードを見る
    const Card* lookingCard = myHand_->lookCard( position ) ;

    int number = lookingCard->getNumber() ;
    Card::SuitType suit = lookingCard->getSuit() ;

    // 今注目している手札の左か右にカードがあれば、カードを置ける
    int leftNumber = (number != 1) ? number - 1 : 13 ;
    int rightNumber = (number != 13) ? number + 1 : 1 ;

    if ( ( true == table_->isThereCard( suit, leftNumber ) )
      || ( true == table_->isThereCard(suit, rightNumber ) ) )
    {
      // 手札からカードを引いてテーブルに置く
      table_->putCard( myHand_->pickCard( position ) ) ;

      // 手札がなくなったら、上がりを宣言する
      if ( myHand_->getNumberOfCards() == 0 )
      {
        master_->declareWin( this ) ;
      }

      return ;
    }
  }

  // テーブルに置けるカードがなかった場合、パスする
  ++pass_ ;
  master_->pass( this ) ;

  // パス回数が4回以上ならばカードを全てテーブルに置く
  if ( pass_ > 3 )
  {
    // 手札を全てテーブルに置く
    for ( int count = 0 ; count < handSize ; ++count )
    {
      table_->putCard( myHand_->pickCard( 0 ) ) ;
    }
  }
}


void Player::receiveCard( const Card* card )
{
  if ( card->getNumber() == 7 )
  {
    // カードが7の場合は、テーブルにカードを置く
    table_->putCard( card ) ;
  }
  else
  {
    // カードが7でない場合は、受け取ったカードを手札へ加える
    myHand_->addCard( card ) ;
  }
}


int Player::getPass() const
{
  return pass_ ;
}


std::string Player::toString() const
{
  return name_ ;
}


std::ostream& operator << ( std::ostream& output, const Player& player )
{
  output << player.toString() ;
  return output ;
}
