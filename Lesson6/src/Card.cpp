#include "Card.h"
#include <sstream>

Card::Card( SuitType suit, int number )
  : suit_( suit ), number_( number )
{
}


int Card::getNumber() const
{
  return number_ ;
}


std::string Card::toString() const
{
  std::ostringstream string ;

  if ( number_ > 0 )
  {
    // スートの表示
    switch ( suit_ )
    {
      case Card::SUIT_SPADE :
        string << "S" ;
        break ;
    
      case Card::SUIT_DIAMOND :
        string << "D" ;
        break ;
    
      case Card::SUIT_CLUB :
        string << "C" ;
        break ;
      
      case Card::SUIT_HEART :
        string << "H" ;
        break ;
    
      default :
        break ;
    }
    
    // 数の表示
    switch ( number_ )
    {
      case 1 :
        string << "A" ;
        break ;

      case 10 :
        string << "T" ;
        break ;
      
      case 11 :
        string << "J" ;
        break ;
      
      case 12 :
        string << "Q" ;
        break ;
        
      case 13 :
        string << "K" ;
        break ;
      
      default :
        string << number_ ;
        break ;
    }
  }
  else
  {
    // ジョーカーを表す
    string << "JK" ;
  }

  return string.str() ;
}


std::ostream& operator << ( std::ostream& output, const Card& card )
{
  output << card.toString() ;
  return output ;
}
