#ifndef STONEONLYTACTICS_H
#define STONEONLYTACTICS_H

#include "Tactics.h"

/**
 * 「グーが大好き！」戦略クラス。
 */
class StoneOnlyTactics : public Tactics
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

#endif // STONEONLYTACTICS_H
