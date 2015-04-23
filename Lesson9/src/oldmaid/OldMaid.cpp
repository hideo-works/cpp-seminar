#include "OldMaid.h"
#include "OldMaidTable.h"
#include "OldMaidRule.h"
#include "OldMaidPlayer.h"
#include <trump/Hand.h>
#include <trump/Card.h>
#include <trump/Joker.h>
#include <trump/Master.h>

using namespace trump ;

namespace oldmaid {

void OldMaid::main( int argc, char* argv[] )
{
  // �i�s���̐���
  Master* master = new Master() ;

  // �e�[�u���̐���
  Table* table = new OldMaidTable() ;
  
  // ���[���̐���
  Rule* rule = new OldMaidRule() ;
  
  // �v���C���[�̐���
  Player* murata = new OldMaidPlayer( "���c", master, table, rule ) ;
  Player* yamada = new OldMaidPlayer( "�R�c", master, table, rule ) ;
  Player* saito  = new OldMaidPlayer( "�֓�", master, table, rule ) ;

  // �v���C���[��o�^
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito  ) ;

  // �g�����v�𐶐�����
  Hand* trump = OldMaid::createTrump() ;

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


Hand* OldMaid::createTrump()
{
  static Hand trump ;
  
  // �e�X�[�g53���̃J�[�h�𐶐�����
  for ( int number = 1 ; number <= Card::CARD_NUM ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }
  
  // �W���[�J�[�̍쐬
  trump.addCard( new Joker() ) ;
  
  return &trump ;
}

} // oldmaid


// �΂Δ����v���O������L���ɂ���ꍇ�ɂ͈ȉ��̃}�N����L������
// Fantan.cpp �̎w��ӏ����R�����g�A�E�g���邱��
//GENERATE_ENTRY_POINT( oldmaid::OldMaid )
