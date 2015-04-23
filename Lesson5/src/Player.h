#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Tactics ;

/**
 * ジャンケンのプレイヤーを表すクラス。
 */
class Player
{
public:
  // ジャンケンの手を表す定数
  enum HandType {
    STONE    = 1, // グー
    SCISSORS = 2, // チョキ
    PAPER    = 3  // パー
  } ;

  //------------------------
  // プレイヤークラスの属性
  //------------------------
private:
  /** プレイヤーの名前 */
  std::string name_ ;

  /** プレイヤーの勝った回数 */
  int winCount_ ;

  /** 与えられた戦略 */
  Tactics* tactics_ ;

  //------------------------
  // プレイヤークラスの操作
  //------------------------
public:
  /**
   * プレイヤークラスのコンストラクタ。
   * 
   * @param name 名前
   */
  Player( const std::string& name ) ;

  /** プレイヤークラスのデストラクタ。 */
  virtual ~Player() ;

  /**
   * プレイヤーに戦略を渡す。
   * 
   * @param tactics 戦略
   */
  void setTactics( Tactics* tactics ) ;

  /**
   * ジャンケンの手を出す。
   *
   * @return ジャンケンの手
   */
  HandType showHand() ;

  /**
   * 審判から勝敗を聞く。
   *
   * @param result true:勝ち,false:負け
   */
  void notifyResult( bool result ) ;

  /**
   * 自分の勝った回数を答える。
   *
   * @return 勝った回数
   */
  int getWinCount() const ;

  /**
   * 自分の名前を答える。
   * 
   * @return 名前
   */
  std::string getName() const ;
} ;

#endif // PLAYER_H
