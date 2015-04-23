#include "ObjectJanken.h"
#include "Judge.h"
#include "Murata.h"
#include "Yamada.h"

void ObjectJanken::main( int argc, char* argv[] )
{
  // �R���̃C���X�^���X����
  Judge* judge = new Judge() ;

  // �v���C���[�P�i���c����j�̐���
  Player* murata = new Murata("���c����") ;

  // �v���C���[�Q�i�R�c����j�̐���
  Player* yamada = new Yamada("�R�c����") ;

  // ���c����ƎR�c������v���C���[�Ƃ��ăW�����P�����J�n����
  judge->startJanken( murata, yamada ) ;

  // �I������
  delete judge ;
  delete murata ;
  delete yamada ;
}


GENERATE_ENTRY_POINT( ObjectJanken )
