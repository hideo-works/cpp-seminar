#ifndef JUDGE_H
#define JUDGE_H

#include "Player.h"

/**
 * �W�����P���̐R����\���N���X�B
 */
class Judge
{
public:
  /**
   * �W�����P�����J�n����B
   * 
   * @param player1 ����Ώۃv���C���[1
   * @param player2 ����Ώۃv���C���[2
   */
  void startJanken( Player* player1, Player* player2 ) const ;


private:
  /**
   * �u�W�����P���A�|���I�v�Ɛ��������A
   * �v���C���[�̎�����āA�ǂ��炪�������𔻒肷��B
   * 
   * @param player1 ����Ώۃv���C���[1
   * @param player2 ����Ώۃv���C���[2
   * @return �������v���C���[�B���������̏ꍇ�� null ��Ԃ��B
   */
  Player* judgeJanken( Player* player1, Player* player2 ) const ;

  /**
   * �ŏI�I�ȏ��҂𔻒肷��B
   * 
   * @param player1 ����Ώۃv���C���[1
   * @param player2 ����Ώۃv���C���[2
   * @return �������v���C���[�B���������̏ꍇ�� null ��Ԃ��B
   */
  Player* judgeFinalWinner( Player* player1, Player* player2 ) const ;

  /**
   * �W�����P���̎��\������B
   * 
   * @param hand �W�����P���̎�
   */
  void printHand( Player::HandType hand ) const ;
} ;

#endif // JUDGE_H
