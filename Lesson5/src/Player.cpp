#include "Player.h"
#include "Tactics.h"

Player::Player( const std::string& name )
  : name_( name ), winCount_( 0 ), tactics_( NULL )
{
}


Player::~Player()
{
  if ( tactics_ != NULL ) delete tactics_ ;
}


void Player::setTactics( Tactics* tactics )
{
  if ( tactics_ != NULL ) delete tactics_ ;
  tactics_ = tactics ;
}


Player::HandType Player::showHand()
{
  // 与えられた戦略を読んでジャンケンの手を決める
  HandType hand = tactics_->readTactics() ;

  // 決定した手を戻り値として返す
  return hand ;
}


void Player::notifyResult( bool result )
{
  if ( true == result )
  {
    // 勝った場合は勝ち数を加算する
    winCount_ += 1 ;
  }
}


int Player::getWinCount() const
{
  return winCount_ ;
}


std::string Player::getName() const
{
  return name_ ;
}
