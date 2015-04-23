#include "RandomTactics.h"

Player::HandType RandomTactics::readTactics()
{
  // プレイヤーの手
  Player::HandType hand = Player::STONE ;

  // 0 以上 3 未満の整数として乱数を得る
  int randomNum = rand() % 3 ;
  if ( randomNum < 1 )
  {
    // randomNum が 0 以上 1 未満の場合、グー
    hand = Player::STONE ;
  }
  else if ( randomNum < 2 )
  {
    // randomNum が 1 以上 2 未満の場合、チョキ
    hand = Player::SCISSORS ;
  }
  else if ( randomNum < 3 )
  {
    // randomNum が 2 以上 3 未満の場合、パー
    hand = Player::PAPER ;
  }

  // 決定した手を戻り値として返す
  return hand ;
}
