#include "FantanMaster.h"
#include "FantanPlayer.h"

namespace fantan {

const int FantanMaster::PASS_LIMIT = 3 ;


void FantanMaster::pass( const FantanPlayer* player )
{
  // パスを表示
  std::cout << "  " << *player << "さんは " << player->getPass() << " 回目のパスしました！\n" ;

  if ( player->getPass() > PASS_LIMIT )
  {
    // パス回数が制限値を超えている場合は負け。
    std::cout << "  " << *player << "さんは負けです！\n" ;
    this->deregisterPlayer( player ) ;
  }
}

} // fantan
