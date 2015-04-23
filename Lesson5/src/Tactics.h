#ifndef TACTICS_H
#define TACTICS_H

#include "Player.h"

/**
 * ジャンケン戦略インターフェース。
 */
class Tactics
{
public:
  /** デストラクタ。 */
  virtual ~Tactics() {}

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
  virtual Player::HandType readTactics() = 0 ;
} ;

#endif // TACTICS_H
