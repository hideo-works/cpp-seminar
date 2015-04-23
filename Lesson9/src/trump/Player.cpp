#include "Player.h"
#include "Hand.h"

namespace trump {

Player::Player( const std::string& name, Master* master, Table* table, Rule* rule )
  : name_( name ), master_( master ), table_( table ), rule_( rule )
{
  myHand_ = new Hand() ;
}


Player::~Player()
{
  delete myHand_ ;
}


void Player::receiveCard( const Card* card )
{
  // Žó‚¯Žæ‚Á‚½ƒJ[ƒh‚ðŽèŽD‚É‰Á‚¦‚é
  myHand_->addCard( card ) ;
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

} // trump
