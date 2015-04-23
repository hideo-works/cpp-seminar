#include "RandomTactics.h"

Player::HandType RandomTactics::readTactics()
{
  // �v���C���[�̎�
  Player::HandType hand = Player::STONE ;

  // 0 �ȏ� 3 �����̐����Ƃ��ė����𓾂�
  int randomNum = rand() % 3 ;
  if ( randomNum < 1 )
  {
    // randomNum �� 0 �ȏ� 1 �����̏ꍇ�A�O�[
    hand = Player::STONE ;
  }
  else if ( randomNum < 2 )
  {
    // randomNum �� 1 �ȏ� 2 �����̏ꍇ�A�`���L
    hand = Player::SCISSORS ;
  }
  else if ( randomNum < 3 )
  {
    // randomNum �� 2 �ȏ� 3 �����̏ꍇ�A�p�[
    hand = Player::PAPER ;
  }

  // ���肵�����߂�l�Ƃ��ĕԂ�
  return hand ;
}
