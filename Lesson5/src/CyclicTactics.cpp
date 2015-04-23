#include "CyclicTactics.h"

CyclicTactics::CyclicTactics()
  : lastHand( static_cast<Player::HandType>( 0 ) )
{
}


Player::HandType CyclicTactics::readTactics()
{
  // 最後に出した手により、次の手を決める。
  // 最後に出した手は記憶しておく。
  // +-----------------+
  // | 最後   | 次の手 |
  // +-----------------+
  // | グー   | チョキ |
  // | チョキ | パー   |
  // | パー   | グー   |
  // +-----------------+
  lastHand = static_cast<Player::HandType>( ( lastHand % 3 ) + 1 ) ;

  // 次の手を出す
  return lastHand ;
}
