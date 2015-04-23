#include "BackHand.h"
#include <trump/Hand.h>

using namespace trump ;

namespace oldmaid {

BackHand::BackHand( Hand* hand )
  : hand_( hand )
{
}


int BackHand::getNumberOfCards() const
{
  return hand_->getNumberOfCards() ;
}


const Card* BackHand::pickCard( int position )
{
  return hand_->pickCard( position ) ;
}

} // oldmaid
