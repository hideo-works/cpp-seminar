#ifndef ASKTACTICS_H
#define ASKTACTICS_H

#include "Tactics.h"

/**
 * 標準入力によりジャンケンの手をユーザに聞く戦略クラス。
 */
class AskTactics : public Tactics
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

#endif // ASKTACTICS_H
