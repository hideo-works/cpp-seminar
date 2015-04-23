#include "CyclicTactics.h"

CyclicTactics::CyclicTactics()
  : lastHand( static_cast<Player::HandType>( 0 ) )
{
}


Player::HandType CyclicTactics::readTactics()
{
  // �Ō�ɏo������ɂ��A���̎�����߂�B
  // �Ō�ɏo������͋L�����Ă����B
  // +-----------------+
  // | �Ō�   | ���̎� |
  // +-----------------+
  // | �O�[   | �`���L |
  // | �`���L | �p�[   |
  // | �p�[   | �O�[   |
  // +-----------------+
  lastHand = static_cast<Player::HandType>( ( lastHand % 3 ) + 1 ) ;

  // ���̎���o��
  return lastHand ;
}
