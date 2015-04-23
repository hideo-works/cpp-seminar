#ifndef JOKER_H
#define JOKER_H

#include "Card.h"
#include <iostream>

namespace trump {

/**
 * �W���[�J�[��\���N���X�B
 * Card�N���X���p�����Ă���B
 * setNumber()�AsetSuit()���\�b�h�𗘗p���邱�ƂŁA�ǂ̂悤�ȃJ�[�h�Ƃ��Ă�
 * �������Ƃ��ł���B
 */
class Joker : public Card
{
public:
  /**
   * �R���X�g���N�^�B
   * �f�t�H���g�ł́A�W���[�J�[�͉��̒l�E�X�[�g���\���Ȃ��B 
   * getNumber()�AgetSuit()��0��Ԃ��B
   */
  Joker() ;

  /**
   * ����ύX����B
   * 
   * @param number ��
   */
  void setNumber( int number ) ;

  /**
   * �X�[�g��ύX����B
   * @param suit
   */
  void setSuit( Card::SuitType suit ) ;

  /**
   * �J�[�h�𕶎���ŕ\������B
   * 
   * @return �J�[�h�̕����\��
   */
  std::string toString() const ;
} ;

} // trump

#endif // JOKER_H
