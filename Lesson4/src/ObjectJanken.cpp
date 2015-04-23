#include "ObjectJanken.h"
#include "Judge.h"
#include "Murata.h"
#include "Yamada.h"

void ObjectJanken::main( int argc, char* argv[] )
{
  // 審判のインスタンス生成
  Judge* judge = new Judge() ;

  // プレイヤー１（村田さん）の生成
  Player* murata = new Murata("村田さん") ;

  // プレイヤー２（山田さん）の生成
  Player* yamada = new Yamada("山田さん") ;

  // 村田さんと山田さんをプレイヤーとしてジャンケンを開始する
  judge->startJanken( murata, yamada ) ;

  // 終了処理
  delete judge ;
  delete murata ;
  delete yamada ;
}


GENERATE_ENTRY_POINT( ObjectJanken )
