#ifndef YAMADA_H
#define YAMADA_H

#include "Player.h"

/**
 * �v���C���[���p�������R�c����N���X�B
 */
class Yamada : public Player
{
public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name ���O
   */
  Yamada( const std::string& name ) ;

  /**
   * �W�����P���̎���o���B
   * �X�[�p�[�N���X�̓������\�b�h���I�[�o�[���C�h���Ă���B
   * 
   * @return �W�����P���̎�
   */
  HandType showHand() ;
} ;

#endif // YAMADA_H
