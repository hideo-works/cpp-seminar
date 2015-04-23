#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include <iostream>
#include <sstream>
#include <exception>
#include <time.h>

class Executable
{
public:
  virtual void main( int argc, char* argv[] ) = 0 ;
} ;


struct Random
{
  Random() {
    srand( static_cast<unsigned>( time( NULL ) ) ) ;
  }
} ;


#define GENERATE_ENTRY_POINT( executable )                         \
  int main( int argc, char* argv[] )                               \
  {                                                                \
    Random random ;                                                \
    try {                                                          \
      executable instance ;                                        \
      instance.main( argc, argv ) ;                                \
    }                                                              \
    catch ( const std::exception& e ) {                            \
      std::ostringstream msg ;                                     \
      msg << "Error [" << typeid(e).name() << "] : " << e.what() ; \
      std::cout << msg.str() << std::endl ;                        \
      return 1 ;                                                   \
    }                                                              \
    catch ( ... ) {                                                \
      std::cout << "Error : Unknown exception" << std::endl ;      \
      return 2 ;                                                   \
    }                                                              \
    return 0 ;                                                     \
  }

#endif // EXECUTABLE_H
