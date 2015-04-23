#ifndef MASTER_H
#define MASTER_H

#include <vector>

class Player ;
class Hand ;

/**
 * ばば抜きの進行役を表すクラス。
 */
class Master
{
private:
  typedef std::vector<Player*> PlayerArray_t ;

  /** プレイヤーのリスト */
  PlayerArray_t players_ ;

public:
  /**
   * ゲームの準備をする。
   * 
   * @param cards トランプを進行役の手札として渡す
   */
  void prepareGame( Hand* cards ) const ;

  /**
   * ゲームを開始する。
   */
  void startGame() ;

  /**
   * 上がりを宣言する。
   * 
   * @param winner 上がったプレイヤー
   */
  void declareWin( const Player* winner ) ;

  /**
   * ゲームに参加するプレイヤーを登録する。
   * 
   * @param player 参加するプレイヤー
   */
  void registerPlayer( Player* player ) ;
} ;

#endif // MASTER_H
