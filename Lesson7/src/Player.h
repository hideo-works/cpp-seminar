#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Table ;
class Hand ;
class Master ;
class Card ;

/**
 * プレイヤーを表すクラス。
 */
class Player
{
private:
  /** 名前 */
  std::string name_ ;

  /** テーブル */
  Table* table_ ;

  /** 手札 */
  Hand* myHand_ ;

  /** 進行役 */
  Master* master_ ;

  /** パスした回数 */
  int pass_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param name 名前
   * @param master 進行役
   * @param table テーブル
   */
  Player( const std::string& name, Master* master, Table* table ) ;

  /** デストラクタ。 */
  virtual ~Player() ;

  /**
   * 順番を指名する。
   */
  void play() ;

  /**
   * カードを受け取る。
   * 
   * @param card 受け取ったカード
   */
  void receiveCard( const Card* card ) ;

  /**
   * パス回数を聞く。
   * 
   * @return パス回数
   */
  int getPass() const ;

  /**
   * プレイヤーの名前を返す。
   * 
   * @return プレイヤーの名前
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

#endif // PLAYER_H
