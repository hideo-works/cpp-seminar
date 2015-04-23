#include "Fantan.h"
#include "Master.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"

void Fantan::main( int argc, char* argv[] )
{
  // �i�s���̐���
  Master* master = new Master() ;
  
  // �e�[�u���̐���
  Table* table = new Table() ;
  
  // �v���C���[�̐���
  Player* murata = new Player( "���c", master, table ) ;
  Player* yamada = new Player( "�R�c", master, table ) ;
  Player* saito  = new Player( "�֓�", master, table ) ;
  
  // �i�s���փv���C���[��o�^
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito ) ;
  
  // �g�����v�𐶐�����
  Hand* trump = Fantan::createTrump() ;
  
  // �Q�[���̏���������
  master->prepareGame( trump ) ;
  
  // �Q�[�����J�n����
  master->startGame() ;

  // �I������
  delete master ;
  delete table ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* Fantan::createTrump()
{
  static Hand trump ;

  // �e�X�[�g52���̃J�[�h�𐶐�����
  for ( int number = 1 ; number <= 13 ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }

  return &trump ;
}


GENERATE_ENTRY_POINT( Fantan )
