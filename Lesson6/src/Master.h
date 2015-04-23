#ifndef MASTER_H
#define MASTER_H

#include <vector>

class Player ;
class Hand ;

/**
 * �΂Δ����̐i�s����\���N���X�B
 */
class Master
{
private:
  typedef std::vector<Player*> PlayerArray_t ;

  /** �v���C���[�̃��X�g */
  PlayerArray_t players_ ;

public:
  /**
   * �Q�[���̏���������B
   * 
   * @param cards �g�����v��i�s���̎�D�Ƃ��ēn��
   */
  void prepareGame( Hand* cards ) const ;

  /**
   * �Q�[�����J�n����B
   */
  void startGame() ;

  /**
   * �オ���錾����B
   * 
   * @param winner �オ�����v���C���[
   */
  void declareWin( const Player* winner ) ;

  /**
   * �Q�[���ɎQ������v���C���[��o�^����B
   * 
   * @param player �Q������v���C���[
   */
  void registerPlayer( Player* player ) ;
} ;

#endif // MASTER_H
