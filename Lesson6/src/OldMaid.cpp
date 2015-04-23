#include "OldMaid.h"
#include "Master.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"

void OldMaid::main( int argc, char* argv[] )
{
  // 進行役の生成
  Master* master = new Master() ;
  
  // 場の生成
  Table* field = new Table() ;
  
  // プレイヤーの生成
  Player* murata = new Player( "村田", master, field ) ;
  Player* yamada = new Player( "山田", master, field ) ;
  Player* saito  = new Player( "斎藤", master, field ) ;
  
  // 進行役へプレイヤーを登録
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito  ) ;
  
  // トランプを生成する
  Hand* trump = OldMaid::createTrump() ;
  
  // ゲームの準備をする
  master->prepareGame( trump ) ;
 
  // ゲームを開始する
  master->startGame() ;

  // 終了処理
  delete master ;
  delete field ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* OldMaid::createTrump()
{
  static Hand trump ;
  
  // 各スート53枚のカードを生成する
  for ( int number = 1 ; number <= 13 ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }
  
  // ジョーカーの作成
  trump.addCard( new Card( Card::JOKER, 0 ) ) ;
  
  return &trump ;
}


GENERATE_ENTRY_POINT( OldMaid )
