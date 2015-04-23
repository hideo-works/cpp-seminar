#include "Joker.h"

namespace trump {

Joker::Joker()
  : Card( static_cast<Card::SuitType>( 0 ), 0 )
{
}


void Joker::setNumber( int number )
{
  number_ = number ;
}


void Joker::setSuit( Card::SuitType suit )
{
  suit_ = suit ;
}


std::string Joker::toString() const
{
  return "JK" ;
}

} // trump