#ifndef CYCLICTACTICS_H
#define CYCLICTACTICS_H

#include "Tactics.h"

/**
 * �O�[�E�`���L�E�p�[�̏��Ԃŏo���헪�N���X�B
 */
class CyclicTactics : public Tactics
{
private:
  /** �Ō�ɏo������(���J�n:0) */
  Player::HandType lastHand ;

public:
  /**
   * �O�[�E�`���L�E�p�[�̏��Ԃŏo��
   * �헪�N���X�̃R���X�g���N�^�B
   */
  CyclicTactics() ;

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

#endif // CYCLICTACTICS_H
