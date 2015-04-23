#include "Fantan.h"
#include "Master.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"

void Fantan::main( int argc, char* argv[] )
{
  // 進行役の生成
  Master* master = new Master() ;
  
  // テーブルの生成
  Table* table = new Table() ;
  
  // プレイヤーの生成
  Player* murata = new Player( "村田", master, table ) ;
  Player* yamada = new Player( "山田", master, table ) ;
  Player* saito  = new Player( "斎藤", master, table ) ;
  
  // 進行役へプレイヤーを登録
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito ) ;
  
  // トランプを生成する
  Hand* trump = Fantan::createTrump() ;
  
  // ゲームの準備をする
  master->prepareGame( trump ) ;
  
  // ゲームを開始する
  master->startGame() ;

  // 終了処理
  delete master ;
  delete table ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* Fantan::createTrump()
{
  static Hand trump ;

  // 各スート52枚のカードを生成する
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
