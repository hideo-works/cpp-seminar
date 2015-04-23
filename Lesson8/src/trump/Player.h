#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

namespace trump {

class Table ;
class Hand ;
class Master ;
class Rule ;
class Card ;

/**
 * プレイヤーを表すクラス。
 */
class Player
{
protected:
  /** 名前 */
  std::string name_ ;

  /** テーブル */
  Table* table_ ;

  /** 手札 */
  Hand* myHand_ ;

  /** 進行役 */
  Master* master_ ;
  
  /** ルール */
  Rule* rule_ ;

public:
  /**
   * コンストラクタ。
   * 
   * @param name 名前
   * @param master 進行役
   * @param table テーブル
   * @param rule ルール
   */
  Player( const std::string& name, Master* master, Table* table, Rule* rule ) ;

  /** デストラクタ。 */
  virtual ~Player() ;

  /**
   * 順番を指名する。
   * 実際の処理はサブクラスで記述すること。
   * 
   * @param nextPlayer 次のプレイヤー
   */
  virtual void play( Player* nextPlayer ) = 0 ;

  /**
   * カードを配る。
   * カードを受け取った時の処理を拡張したい場合は、
   * 本メソッドをサブクラスでオーバーライドすること。
   *
   * @param card 受け取ったカード
   */
  virtual void receiveCard( const Card* card ) ;

  /**
   * プレイヤーの名前を返す。
   * 
   * @return プレイヤーの名前
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

} // trump

#endif // PLAYER_H
