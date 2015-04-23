#include "OldMaid.h"
#include "Master.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"

void OldMaid::main( int argc, char* argv[] )
{
  // �i�s���̐���
  Master* master = new Master() ;
  
  // ��̐���
  Table* field = new Table() ;
  
  // �v���C���[�̐���
  Player* murata = new Player( "���c", master, field ) ;
  Player* yamada = new Player( "�R�c", master, field ) ;
  Player* saito  = new Player( "�֓�", master, field ) ;
  
  // �i�s���փv���C���[��o�^
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
  delete field ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* OldMaid::createTrump()
{
  static Hand trump ;
  
  // �e�X�[�g53���̃J�[�h�𐶐�����
  for ( int number = 1 ; number <= 13 ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }
  
  // �W���[�J�[�̍쐬
  trump.addCard( new Card( Card::JOKER, 0 ) ) ;
  
  return &trump ;
}


GENERATE_ENTRY_POINT( OldMaid )
