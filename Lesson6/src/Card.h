#ifndef CARD_H
#define CARD_H

#include <iostream>

/**
 * �g�����v�̃J�[�h��\���N���X�B
 */
class Card
{
public:
  // �J�[�h�̎����X�[�g������킷�萔
  enum SuitType {
    JOKER        = 0, // �W���[�J�[
    SUIT_SPADE   = 1, // �X�y�[�h
    SUIT_DIAMOND = 2, // �_�C��
    SUIT_CLUB    = 3, // �N���u
    SUIT_HEART   = 4  // �n�[�g
  } ;

private:
  /** �J�[�h�̎����X�[�g */
  SuitType suit_ ;
  
  /** �J�[�h�̎����� */
  int number_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param suit �X�[�g
   * @param number �� (0�̏ꍇ�̓W���[�J�[�Ƃ��Ĉ���)
   */
  Card( SuitType suit, int number ) ;

  /** �f�X�g���N�^�B */
  virtual ~Card() {}

  /**
   * ����������B
   * 
   * @return �� 
   */
  int getNumber() const ;

  /**
   * �J�[�h�𕶎���ŕ\������B
   * 
   * @return �J�[�h�̕����\��
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Card& card ) ;

#endif // CARD_H
