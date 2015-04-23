#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>

class Card ;

/**
 * ��D��\���N���X�B
 */
class Hand
{
private:
  typedef std::list<const Card*> CardList_t ;

  /** ��D�ɂ���J�[�h��ێ����邽�߂̃��X�g */
  CardList_t deal_ ;

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
   * ��D�ɂ���J�[�h������B
   * position�� 0 ���� getNumberOfCards() �͈̔͂Ŏw�肷�邷�邱�ƁB
   * 
   * @param position �J�[�h�̈ʒu�B
   * @return position �Ŏw�肳�ꂽ�ʒu�̃J�[�h�B�͈͊O�̏ꍇ��null��Ԃ��B
   */
  const Card* lookCard( int position ) const ;

  /**
   * ��D����J�[�h�������B
   * �������J�[�h�͎�D����폜�����B
   * 
   * @param position �J�[�h�̈ʒu�B
   * @return position �Ŏw�肳�ꂽ�ʒu�̃J�[�h�B�͈͊O�̏ꍇ��null��Ԃ��B
   */
  const Card* pickCard( int position ) ;

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
   * ��D�ɂ���J�[�h�𕶎���ŕ\������B
   * 
   * @return ��D�ɂ���J�[�h�̕�����\��
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Hand& hand ) ;

#endif // HAND_H
