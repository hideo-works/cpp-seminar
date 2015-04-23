#ifndef OLDMAIDPLAYER_H
#define OLDMAIDPLAYER_H

#include <trump/Player.h>

namespace oldmaid {

class BackHand ;

/**
 * �΂Δ����̃v���C���[�N���X�B
 */
class OldMaidPlayer : public trump::Player
{
private:
  /** �����猩����D��\���N���X */
  BackHand* backHand_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name   ���O
   * @param master �i�s��
   * @param table  �e�[�u��
   * @param rule   ���[��
   */
  OldMaidPlayer( const std::string& name, trump::Master* master, trump::Table* table, trump::Rule* rule ) ;

  /** �f�X�g���N�^�B */
  virtual ~OldMaidPlayer() ;

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
   * ��D���o���B
   * ����ɃJ�[�h�������Ă��炤���߂ɁA��D��������B
   * 
   * @return �����̎�D
   */
  BackHand* showHand() ;
} ;

} // oldmaid

#endif // OLDMAIDPLAYER_H
