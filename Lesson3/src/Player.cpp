#include "Player.h"

Player::Player( const std::string& name )
  : name_( name ), winCount_( 0 )
{
}


Player::HandType Player::showHand()
{
  // �v���C���[�̎�
  HandType hand = STONE ;

  // 0 �ȏ� 3 �����̐����Ƃ��ė����𓾂�
  int randomNum = rand() % 3 ;
  if ( randomNum < 1 )
  {
    // randomNum �� 0 �ȏ� 1 �����̏ꍇ�A�O�[
    hand = STONE ;
  }
  else if ( randomNum < 2 )
  {
    // randomNum �� 1 �ȏ� 2 �����̏ꍇ�A�`���L
    hand = SCISSORS ;
  }
  else if ( randomNum < 3 )
  {
    // randomNum �� 2 �ȏ� 3 �����̏ꍇ�A�p�[
    hand = PAPER ;
  }

  // ���肵�����߂�l�Ƃ��ĕԂ�
  return hand ;
}


void Player::notifyResult( bool result )
{
  if ( true == result )
  {
    // �������ꍇ�͏����������Z����
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
