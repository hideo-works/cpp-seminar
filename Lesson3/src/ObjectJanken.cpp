#include "ObjectJanken.h"
#include "Judge.h"
#include "Player.h"

void ObjectJanken::main( int argc, char* argv[] )
{
  // �R���i�֓�����j�̃C���X�^���X����
  Judge* saito = new Judge() ;

  // �v���C���[�P�i���c����j�̐���
  Player* murata = new Player("���c����") ;

  // �v���C���[�Q�i�R�c����j�̐���
  Player* yamada = new Player("�R�c����") ;

  // ���c����ƎR�c������v���C���[�Ƃ��ăW�����P�����J�n����
  saito->startJanken( murata, yamada ) ;

  // �I������
  delete saito ;
  delete murata ;
  delete yamada ;
}


GENERATE_ENTRY_POINT( ObjectJanken )
