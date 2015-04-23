#include "Player.h"
#include "Master.h"
#include "Table.h"
#include "Hand.h"
#include "Card.h"

Player::Player( const std::string& name, Master* master, Table* table )
  : name_( name ), master_( master ), table_( table )
{
  myHand_ = new Hand() ;
}


Player::~Player()
{
  delete myHand_ ;
}


void Player::play( Player* nextPlayer )
{
  // 次のプレイヤーに手札を出してもらう
  Hand* nextHand = nextPlayer->showHand() ;

  // 相手の手札からカードを一枚引く
  const Card* pickedCard = nextHand->pickCard() ;

  // 引いた結果を表示
  std::cout << *this << "："
            << *nextPlayer << "さんから " << *pickedCard << " を引きました\n" ;

  // 引いたカードを自分の手札に加え、同じ数のカードがあったら捨てる
  this->dealCard( pickedCard ) ;

  // 手札がゼロになったかどうか調べる
  if ( myHand_->getNumberOfCards() == 0 )
  {
    // 進行役に上がりを宣言する
    master_->declareWin( this ) ;
  }
  else
  {
    // 現在の手札を表示する
    std::cout << *this << "：残りの手札は " << *myHand_ << "です\n" ;
  }
}


Hand* Player::showHand()
{
  // もしこの時点で手札が残り1枚ならば上がりとなるので宣言する
  if ( myHand_->getNumberOfCards() == 1 )
  {
    master_->declareWin( this ) ;
  }

  // 見せる前にシャッフルする
  myHand_->shuffle() ;

  return myHand_ ;
}


void Player::receiveCard( const Card* card )
{
  // 引いたカードを自分の手札に加え、同じ数のカードがあったら捨てる
  this->dealCard( card ) ;
}


void Player::dealCard( const Card* card )
{
  // カードを自分の手札に加える
  myHand_->addCard( card ) ;

  // 今加えたカードと同じカードを探す
  Hand::CardList_t sameCards = myHand_->findSameNumberCard() ;

  // 同じカードの組み合わせが存在した場合
  if ( sameCards.size() > 0 )
  {
      // テーブルへカードを捨てる
    std::cout << *this << "：" ;
    table_->disposeCard( sameCards ) ;
  }
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
