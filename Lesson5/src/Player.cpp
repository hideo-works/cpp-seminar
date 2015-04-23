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
  // �^����ꂽ�헪��ǂ�ŃW�����P���̎�����߂�
  HandType hand = tactics_->readTactics() ;

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
