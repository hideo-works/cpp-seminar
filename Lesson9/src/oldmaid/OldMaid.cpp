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
  // 進行役の生成
  Master* master = new Master() ;

  // テーブルの生成
  Table* table = new OldMaidTable() ;
  
  // ルールの生成
  Rule* rule = new OldMaidRule() ;
  
  // プレイヤーの生成
  Player* murata = new OldMaidPlayer( "村田", master, table, rule ) ;
  Player* yamada = new OldMaidPlayer( "山田", master, table, rule ) ;
  Player* saito  = new OldMaidPlayer( "斎藤", master, table, rule ) ;

  // プレイヤーを登録
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
  delete table ;
  delete rule ;
  delete murata ;
  delete yamada ;
  delete saito ;
}


Hand* OldMaid::createTrump()
{
  static Hand trump ;
  
  // 各スート53枚のカードを生成する
  for ( int number = 1 ; number <= Card::CARD_NUM ; ++number )
  {
    trump.addCard( new Card( Card::SUIT_CLUB,    number ) ) ;
    trump.addCard( new Card( Card::SUIT_DIAMOND, number ) ) ;
    trump.addCard( new Card( Card::SUIT_HEART,   number ) ) ;
    trump.addCard( new Card( Card::SUIT_SPADE,   number ) ) ;
  }
  
  // ジョーカーの作成
  trump.addCard( new Joker() ) ;
  
  return &trump ;
}

} // oldmaid


// ばば抜きプログラムを有効にする場合には以下のマクロを有効化し
// Fantan.cpp の指定箇所をコメントアウトすること
//GENERATE_ENTRY_POINT( oldmaid::OldMaid )
