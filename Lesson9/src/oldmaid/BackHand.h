#ifndef BACKHAND_H
#define BACKHAND_H

namespace trump {

class Hand ;
class Card ;

} // trump

namespace oldmaid {

/**
 * �������猩����D��\���N���X�B
 * �ׂ̃v���C���[�ɃJ�[�h����������ہA�J�[�h�̗��������������邽�߂�
 * �g�p�ł��郁�\�b�h�𐧌����Ă���B
 */
class BackHand
{
private:
  /** ��D */
  trump::Hand* hand_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param hand ��D
   */
  BackHand( trump::Hand* hand ) ;

  /**
   * �����𐔂���B
   * 
   * @return ��D�ɂ���J�[�h�̖���
   */
  int getNumberOfCards() const ;

  /**
   * �J�[�h�������B
   * �������J�[�h�͎�D����폜�����B
   * 
   * @param position �J�[�h�̈ʒu�B
   * @return position �Ŏw�肳�ꂽ�ʒu�̃J�[�h�B�͈͊O�̏ꍇ��null��Ԃ��B
   */
  const trump::Card* pickCard( int position ) ;
} ;

} // oldmaid

#endif // BACKHAND_H
