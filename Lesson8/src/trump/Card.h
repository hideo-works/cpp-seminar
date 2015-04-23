#ifndef CARD_H
#define CARD_H

#include <iostream>

namespace trump {

/**
 * �g�����v�̃J�[�h��\���N���X�B
 */
class Card
{
public:
  // �J�[�h�̎����X�[�g������킷�萔
  enum SuitType {
    SUIT_SPADE   = 1, // �X�y�[�h
    SUIT_DIAMOND = 2, // �_�C��
    SUIT_CLUB    = 3, // �N���u
    SUIT_HEART   = 4  // �n�[�g
  } ;

  /** �X�[�g�̐� */
  static const int SUIT_NUM ;

  /** �l�̐� */
  static const int CARD_NUM ;

protected:
  /** �J�[�h�̎����X�[�g */
  SuitType suit_ ;

  /** �J�[�h�̎����� */
  int number_ ;

public:
  /**
   * �R���X�g���N�^�B
   * �X�[�g�Ɛ����w�肵�ĐV�����J�[�h�̃C���X�^���X�𐶐�����B
   * �X�[�g��SUIT_SPADE�ASUIT_DIAMOND�ASUIT_CLUB�ASUIT_HEART��
   * �����ꂩ���w�肷��B
   * 
   * @param suit �X�[�g
   * @param number ��
   */
  Card( SuitType suit, int number ) ;

  /** �f�X�g���N�^�B */
  virtual ~Card() {}

  /**
   * ��������B
   * 
   * @return �� 
   */
  int getNumber() const ;

  /**
   * �X�[�g������B
   * 
   * @return �X�[�g 
   */
  SuitType getSuit() const ;

  /**
   * �J�[�h�𕶎���ŕ\������B
   * 
   * @return �J�[�h�̕����\��
   */
  virtual std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Card& card ) ;

} // trump

#endif // CARD_H
