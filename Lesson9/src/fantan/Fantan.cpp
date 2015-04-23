#include "Fantan.h"
#include "FantanMaster.h"
#include "FantanTable.h"
#include "FantanRule.h"
#include "FantanPlayer.h"
#include <trump/Hand.h>
#include <trump/Card.h>

using namespace trump ;

namespace fantan {

void Fantan::main( int argc, char* argv[] )
{
  // �i�s���̐���
  Master* master = new FantanMaster() ;
  
  // �e�[�u���̐���
  Table* table = new FantanTable() ;
  
  // ���[���̐���
  Rule* rule = new FantanRule() ;
  
  // �v���C���[�̐���
  Player* murata = new FantanPlayer( "���c", master, table, rule ) ;
  Player* yamada = new FantanPlayer( "�R�c", master, table, rule ) ;
  Player* saito  = new FantanPlayer( "�֓�", master, table, rule ) ;
  
  // �v���C���[��o�^
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito  ) ;
  
  // �g�����v�𐶐�����
  Hand* trump = Fantan::createTrump() ;
  
  // �Q�[���̏���������
  master->prepareGame( trump ) ;
  
  // �Q�[�����J�n����
  master->startGame() ;

  // �I������
  delete master ;
  delete table ;
  delete rule ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* Fantan::createTrump()
{
  static Hand trump ;
  
  // �e�X�[�g52���̃J�[�h�𐶐�����
  for ( int number = 1 ; number <= Card::CARD_NUM ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }
  
  return &trump ;
}

} // fantan

// �΂Δ����v���O������L���ɂ���ꍇ�ɂ͈ȉ��̃}�N�����R�����g�A�E�g��
// OldMaid.cpp �̎w��ӏ���L�������邱��
GENERATE_ENTRY_POINT( fantan::Fantan )
