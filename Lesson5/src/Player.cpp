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
  // —^‚¦‚ç‚ê‚½í—ª‚ğ“Ç‚ñ‚ÅƒWƒƒƒ“ƒPƒ“‚Ìè‚ğŒˆ‚ß‚é
  HandType hand = tactics_->readTactics() ;

  // Œˆ’è‚µ‚½è‚ğ–ß‚è’l‚Æ‚µ‚Ä•Ô‚·
  return hand ;
}


void Player::notifyResult( bool result )
{
  if ( true == result )
  {
    // Ÿ‚Á‚½ê‡‚ÍŸ‚¿”‚ğ‰ÁZ‚·‚é
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
