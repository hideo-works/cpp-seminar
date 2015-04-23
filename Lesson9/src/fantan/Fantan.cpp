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
  // 進行役の生成
  Master* master = new FantanMaster() ;
  
  // テーブルの生成
  Table* table = new FantanTable() ;
  
  // ルールの生成
  Rule* rule = new FantanRule() ;
  
  // プレイヤーの生成
  Player* murata = new FantanPlayer( "村田", master, table, rule ) ;
  Player* yamada = new FantanPlayer( "山田", master, table, rule ) ;
  Player* saito  = new FantanPlayer( "斎藤", master, table, rule ) ;
  
  // プレイヤーを登録
  master->registerPlayer( murata ) ;
  master->registerPlayer( yamada ) ;
  master->registerPlayer( saito  ) ;
  
  // トランプを生成する
  Hand* trump = Fantan::createTrump() ;
  
  // ゲームの準備をする
  master->prepareGame( trump ) ;
  
  // ゲームを開始する
  master->startGame() ;

  // 終了処理
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
  
  // 各スート52枚のカードを生成する
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

// ばば抜きプログラムを有効にする場合には以下のマクロをコメントアウトし
// OldMaid.cpp の指定箇所を有効化すること
GENERATE_ENTRY_POINT( fantan::Fantan )
