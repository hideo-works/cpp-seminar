#ifndef MURATA_H
#define MURATA_H

#include "Player.h"

/**
 * �v���C���[���p���������c����N���X�B
 */
class Murata : public Player
{
public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name ���O
   */
  Murata( const std::string& name ) ;

  /**
   * �W�����P���̎���o���B
   * �X�[�p�[�N���X�̓������\�b�h���I�[�o�[���C�h���Ă���B
   * 
   * @return �W�����P���̎�
   */
  HandType showHand() ;
} ;

#endif // MURATA_H
