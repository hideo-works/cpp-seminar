#ifndef FANTAN_H
#define FANTAN_H

#include <Executable.h>

namespace trump {

class Hand ;

} // trump

namespace fantan {

/**
 * �����׃v���O�����B
 */
class Fantan : public Executable
{
public:
  // �G���g���|�C���g
  void main( int argc, char* argv[] ) ;

private:
  /**
   * 52���̃g�����v�𐶐�����B
   * 
   * @return �g�����v���i�[����Hand
   */
  static trump::Hand* createTrump() ;
} ;

} // fantan

#endif // FANTAN_H
