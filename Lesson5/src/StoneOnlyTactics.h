#ifndef STONEONLYTACTICS_H
#define STONEONLYTACTICS_H

#include "Tactics.h"

/**
 * �u�O�[����D���I�v�헪�N���X�B
 */
class StoneOnlyTactics : public Tactics
{
public:
  /**
   * �헪��ǂ݁A�W�����P���̎�𓾂�B
   * �O�[�E�`���L�E�p�[�̂����ꂩ��Player�N���X�ɒ�`���ꂽ
   * �ȉ��̒萔�ŕԂ��B
   * Player::STONE    �E�E�E �O�[
   * Player::SCISSORS �E�E�E �`���L
   * Player::PAPER    �E�E�E �p�[
   * 
   * @return �W�����P���̎�
   */
  Player::HandType readTactics() ;
} ;

#endif // STONEONLYTACTICS_H
