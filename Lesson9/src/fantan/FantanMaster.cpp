#include "FantanMaster.h"
#include "FantanPlayer.h"

namespace fantan {

const int FantanMaster::PASS_LIMIT = 3 ;


void FantanMaster::pass( const FantanPlayer* player )
{
  // �p�X��\��
  std::cout << "  " << *player << "����� " << player->getPass() << " ��ڂ̃p�X���܂����I\n" ;

  if ( player->getPass() > PASS_LIMIT )
  {
    // �p�X�񐔂������l�𒴂��Ă���ꍇ�͕����B
    std::cout << "  " << *player << "����͕����ł��I\n" ;
    this->deregisterPlayer( player ) ;
  }
}

} // fantan
