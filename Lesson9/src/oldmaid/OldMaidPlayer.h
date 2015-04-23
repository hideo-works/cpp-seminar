#ifndef OLDMAIDPLAYER_H
#define OLDMAIDPLAYER_H

#include <trump/Player.h>

namespace oldmaid {

class BackHand ;

/**
 * ばば抜きのプレイヤークラス。
 */
class OldMaidPlayer : public trump::Player
{
private:
  /** 裏から見た手札を表すクラス */
  BackHand* backHand_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param name   名前
   * @param master 進行役
   * @param table  テーブル
   * @param rule   ルール
   */
  OldMaidPlayer( const std::string& name, trump::Master* master, trump::Table* table, trump::Rule* rule ) ;

  /** デストラクタ。 */
  virtual ~OldMaidPlayer() ;

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
   * 手札を出す。
   * 相手にカードを引いてもらうために、手札を見せる。
   * 
   * @return 自分の手札
   */
  BackHand* showHand() ;
} ;

} // oldmaid

#endif // OLDMAIDPLAYER_H
