#ifndef RANDOMTACTICS_H
#define RANDOMTACTICS_H

#include "Tactics.h"

/**
 * �����_���Ɏ�����߂�헪�N���X�B
 */
class RandomTactics : public Tactics
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

#endif // RANDOMTACTICS_H
