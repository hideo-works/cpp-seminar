#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
 * �W�����P���̃v���C���[��\���N���X�B
 */
class Player
{
public:
  // �W�����P���̎��\���萔
  enum HandType {
    STONE    = 0, // �O�[
    SCISSORS = 1, // �`���L
    PAPER    = 2  // �p�[
  } ;

  //------------------------
  // �v���C���[�N���X�̑���
  //------------------------
private:
  /** �v���C���[�̖��O */
  std::string name_ ;

  /** �v���C���[�̏������� */
  int winCount_ ;

  //------------------------
  // �v���C���[�N���X�̑���
  //------------------------
public:
  /**
   * �v���C���[�N���X�̃R���X�g���N�^�B
   * 
   * @param name ���O
   */
  Player( const std::string& name ) ;

  /** �v���C���[�N���X�̃f�X�g���N�^�B */
  virtual ~Player() {}

  /**
   * �W�����P���̎���o���B
   *
   * @return �W�����P���̎�
   */
  virtual HandType showHand() ;

  /**
   * �R�����珟�s�𕷂��B
   *
   * @param result true:����,false:����
   */
  void notifyResult( bool result ) ;

  /**
   * �����̏������񐔂𓚂���B
   *
   * @return ��������
   */
  int getWinCount() const ;

  /**
   * �����̖��O�𓚂���B
   * 
   * @return ���O
   */
  std::string getName() const ;
} ;

#endif // PLAYER_H
