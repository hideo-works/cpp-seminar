#ifndef OLDMAID_H
#define OLDMAID_H

#include "Executable.h"

class Hand ;

/**
 * �΂Δ����v���O�����B
 */
class OldMaid : public Executable
{
public:
  // �G���g���|�C���g
  void main( int argc, char* argv[] ) ;

private:
  /**
   * 53���̃g�����v�𐶐�����B
   * 
   * @return �g�����v���i�[����Hand
   */
  static Hand* createTrump() ;
} ;

#endif // OLDMAID_H
