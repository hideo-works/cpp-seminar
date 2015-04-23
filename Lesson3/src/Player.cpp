#include "Player.h"

Player::Player( const std::string& name )
  : name_( name ), winCount_( 0 )
{
}


Player::HandType Player::showHand()
{
  // プレイヤーの手
  HandType hand = STONE ;

  // 0 以上 3 未満の整数として乱数を得る
  int randomNum = rand() % 3 ;
  if ( randomNum < 1 )
  {
    // randomNum が 0 以上 1 未満の場合、グー
    hand = STONE ;
  }
  else if ( randomNum < 2 )
  {
    // randomNum が 1 以上 2 未満の場合、チョキ
    hand = SCISSORS ;
  }
  else if ( randomNum < 3 )
  {
    // randomNum が 2 以上 3 未満の場合、パー
    hand = PAPER ;
  }

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
