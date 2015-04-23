#ifndef JUDGE_H
#define JUDGE_H

#include "Player.h"

/**
 * ジャンケンの審判を表すクラス。
 */
class Judge
{
public:
  /**
   * ジャンケンを開始する。
   * 
   * @param player1 判定対象プレイヤー1
   * @param player2 判定対象プレイヤー2
   */
  void startJanken( Player* player1, Player* player2 ) const ;


private:
  /**
   * 「ジャンケン、ポン！」と声をかけ、
   * プレイヤーの手を見て、どちらが勝ちかを判定する。
   * 
   * @param player1 判定対象プレイヤー1
   * @param player2 判定対象プレイヤー2
   * @return 勝ったプレイヤー。引き分けの場合は null を返す。
   */
  Player* judgeJanken( Player* player1, Player* player2 ) const ;

  /**
   * 最終的な勝者を判定する。
   * 
   * @param player1 判定対象プレイヤー1
   * @param player2 判定対象プレイヤー2
   * @return 勝ったプレイヤー。引き分けの場合は null を返す。
   */
  Player* judgeFinalWinner( Player* player1, Player* player2 ) const ;

  /**
   * ジャンケンの手を表示する。
   * 
   * @param hand ジャンケンの手
   */
  void printHand( Player::HandType hand ) const ;
} ;

#endif // JUDGE_H
