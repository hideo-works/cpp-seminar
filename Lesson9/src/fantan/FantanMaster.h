#ifndef FANTANMASTER_H
#define FANTANMASTER_H

#include <trump/Master.h>

namespace fantan {

class FantanPlayer ;

/**
 * 七並べ用進行役クラス。
 */
class FantanMaster : public trump::Master
{
public:
  /** パスできる制限回数 */
  static const int PASS_LIMIT ;

public:
  /**
   * パスを宣言する。
   * 
   * @param player パスするプレイヤー
   */
  void pass( const FantanPlayer* player ) ;
} ;

} // fantan

#endif // FANTANMASTER_H
