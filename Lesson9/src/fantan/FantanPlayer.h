#ifndef FANTANPLAYER_H
#define FANTANPLAYER_H

#include <trump/Player.h>

namespace fantan {

/**
 * �����חp�v���C���[�N���X�B
 */
class FantanPlayer : public trump::Player
{
private:
  /** �p�X������ */
  int pass_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name    �v���C���[�̖��O
   * @param master �i�s��
   * @param table  �e�[�u��
   * @param rule    ���[��
   */
  FantanPlayer( const std::string& name, trump::Master* master, trump::Table* table, trump::Rule* rule ) ;

  /**
   * �J�[�h��z��B
   * 
   * @param card �󂯎�����J�[�h
   */
  void receiveCard( const trump::Card* card ) ;

  /**
   * ���Ԃ��w������B
   * 
   * @param nextPlayer ���̃v���C���[
   */
  void play( trump::Player* nextPlayer ) ;

  /**
   * �p�X�񐔂𕷂��B
   * 
   * @return �p�X��
   */
  int getPass() const ;
} ;

} // fantan

#endif // FANTANPLAYER_H
