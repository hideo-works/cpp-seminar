#include "Table.h"
#include <sstream>

Table::Table()
{
  memset( table_, 0x00, sizeof(table_) ) ;
}


Table::~Table()
{
  for ( int suit = 0 ; suit < 4 ; ++suit )
  {
    for ( int number = 0; number < 13 ; ++number )
    {
      if ( table_[suit][number] != NULL ) delete table_[suit][number] ;
    }
  }
}


void Table::putCard( const Card* card )
{
  int number = card->getNumber() ;
  Card::SuitType suit = card->getSuit() ;
  
  // ��ɃJ�[�h��u��
  table_[suit - 1][number - 1] = card ;
  
  // �u���ꂽ�J�[�h��\������
  std::cout << "  " << *card << "��u���܂����B\n\n" ;
  
  // ���݂̏�̏�Ԃ�\������
  std::cout << *this ;
}


bool Table::isThereCard( Card::SuitType suit, int number ) const
{
  if ( table_[suit - 1][number - 1] != NULL )
  {
    return true ;
  }
  else
  {
    return false ;
  }
}


std::string Table::toString() const
{
  std::ostringstream string ;

  for ( int suit = 0 ; suit < 4 ; ++suit )
  {
    for ( int number = 0; number < 13 ; ++number )
    {
      if ( table_[suit][number] != NULL )
      {
        string << *table_[suit][number] ;
      }
      else
      {
        string << ".." ;
      }

      string << " " ;
    }

    string << "\n" ;
  }

  return string.str() ;
}


std::ostream& operator << ( std::ostream& output, const Table& table )
{
  output << table.toString() ;
  return output ;
}
