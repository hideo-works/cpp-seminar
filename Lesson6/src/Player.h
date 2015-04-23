#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Master ;
class Table ;
class Hand ;
class Card ;

/**
 * ばば抜きのプレイヤークラス。
 */
class Player
{
private:
  /** 進行役 */
  Master* master_ ;

  /** テーブル */
  Table* table_ ;

  /** 自分の手札 */
  Hand* myHand_ ;

  /** 名前 */
  std::string name_ ;

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
   * 
   * @param nextPlayer 次のプレイヤー
   */
  void play( Player* nextPlayer ) ;

  /**
   * 手札を見せる。
   * 
   * @return 自分の手札
   */
  Hand* showHand() ;

  /**
   * カードを受け取る。
   * 
   * @param card 受け取ったカード
   */
  void receiveCard( const Card* card ) ;

  /**
   * プレイヤーの名前を返す。
   * 
   * @return プレイヤーの名前
   */
  std::string toString() const ;

private:
  /**
   * カードを自分の手札に加え、同じ数のカードがあったら捨てる。
   * 
   * @param card
   */
  void dealCard( const Card* card ) ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

#endif // PLAYER_H
