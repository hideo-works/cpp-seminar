#ifndef TACTICS_H
#define TACTICS_H

#include "Player.h"

/**
 * �W�����P���헪�C���^�[�t�F�[�X�B
 */
class Tactics
{
public:
  /** �f�X�g���N�^�B */
  virtual ~Tactics() {}

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
  virtual Player::HandType readTactics() = 0 ;
} ;

#endif // TACTICS_H
