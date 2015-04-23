#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>

class Card ;

/**
 * �΂Δ����̎�D��\���N���X�B
 */
class Hand
{
public:
  typedef std::list<const Card*> CardList_t ;

private:
  /** ��D�ɂ���J�[�h��ێ����邽�߂̃��X�g */
  CardList_t hand_ ;

public:
  /** �f�X�g���N�^�B */
  virtual ~Hand() ;

  /**
   * �J�[�h��������B
   * 
   * @param card ������J�[�h
   */
  void addCard( const Card* card ) ;

  /**
   * �J�[�h�������B
   * 
   * @return �������J�[�h
   */
  const Card* pickCard() ;

  /**
   * �V���b�t������B
   */
  void shuffle() ;

  /**
   * �����𐔂���B
   * 
   * @return ��D�ɂ���J�[�h�̖���
   */
  int getNumberOfCards() const ;

  /**
   * �������̃J�[�h��T���B
   * �������̃J�[�h���Ȃ��ꍇ�̓T�C�Y��0�̃��X�g��Ԃ��܂��B
   * 
   * @return �������̃J�[�h
   */
  CardList_t findSameNumberCard() ;

  /**
   * ��D�ɂ���J�[�h�𕶎���ŕ\������B
   * 
   * @return ��D�ɂ���J�[�h�̕�����\��
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Hand& hand ) ;

#endif // HAND_H
