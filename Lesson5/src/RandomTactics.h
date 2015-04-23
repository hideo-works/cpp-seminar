#ifndef RANDOMTACTICS_H
#define RANDOMTACTICS_H

#include "Tactics.h"

/**
 * ランダムに手を決める戦略クラス。
 */
class RandomTactics : public Tactics
{
public:
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

#endif // RANDOMTACTICS_H
