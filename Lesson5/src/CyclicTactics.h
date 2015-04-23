#ifndef CYCLICTACTICS_H
#define CYCLICTACTICS_H

#include "Tactics.h"

/**
 * グー・チョキ・パーの順番で出す戦略クラス。
 */
class CyclicTactics : public Tactics
{
private:
  /** 最後に出した手(未開始:0) */
  Player::HandType lastHand ;

public:
  /**
   * グー・チョキ・パーの順番で出す
   * 戦略クラスのコンストラクタ。
   */
  CyclicTactics() ;

  /**
   * 戦略を読み、ジャンケンの手を得る。
   * グー・チョキ・パーのいずれかをPlayerクラスに定義された
   * 以下の定数で返す。
   * Player::STONE    ・・・ グー
   * Player::SCISSORS ・・・ チョキ
   * Player::PAPER    ・・・ パー
   * 
   * @return ジャンケンの手
   */
  Player::HandType readTactics() ;
} ;

#endif // CYCLICTACTICS_H
