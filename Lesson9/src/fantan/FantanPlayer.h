#ifndef FANTANPLAYER_H
#define FANTANPLAYER_H

#include <trump/Player.h>

namespace fantan {

/**
 * 七並べ用プレイヤークラス。
 */
class FantanPlayer : public trump::Player
{
private:
  /** パスした回数 */
  int pass_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param name    プレイヤーの名前
   * @param master 進行役
   * @param table  テーブル
   * @param rule    ルール
   */
  FantanPlayer( const std::string& name, trump::Master* master, trump::Table* table, trump::Rule* rule ) ;

  /**
   * カードを配る。
   * 
   * @param card 受け取ったカード
   */
  void receiveCard( const trump::Card* card ) ;

  /**
   * 順番を指名する。
   * 
   * @param nextPlayer 次のプレイヤー
   */
  void play( trump::Player* nextPlayer ) ;

  /**
   * パス回数を聞く。
   * 
   * @return パス回数
   */
  int getPass() const ;
} ;

} // fantan

#endif // FANTANPLAYER_H
