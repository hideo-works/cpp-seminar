#ifndef FANTANMASTER_H
#define FANTANMASTER_H

#include <trump/Master.h>

namespace fantan {

class FantanPlayer ;

/**
 * �����חp�i�s���N���X�B
 */
class FantanMaster : public trump::Master
{
public:
  /** �p�X�ł��鐧���� */
  static const int PASS_LIMIT ;

public:
  /**
   * �p�X��錾����B
   * 
   * @param player �p�X����v���C���[
   */
  void pass( const FantanPlayer* player ) ;
} ;

} // fantan

#endif // FANTANMASTER_H
