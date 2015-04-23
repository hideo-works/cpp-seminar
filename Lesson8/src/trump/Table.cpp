#include "Table.h"
#include <sstream>

namespace trump {

std::string Table::toString() const
{
  std::ostringstream string ;

  string << this ;

  return string.str() ;
}


std::ostream& operator << ( std::ostream& output, const Table& table )
{
  output << table.toString() ;
  return output ;
}

} // trump
