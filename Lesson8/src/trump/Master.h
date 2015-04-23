#ifndef MASTER_H
#define MASTER_H

#include <vector>

namespace trump {

class Player ;
class Hand ;

/**
 * �i�s����\���N���X�B
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

  /**
   * �Q�[���ɎQ������v���C���[��o�^����폜����B
   * �������v���C���[���Q�[�����甲���Ƃ��Ɏg�p����B
   * 
   * @param player �폜����v���C���[
   */
  void deregisterPlayer( const Player* player ) ;
} ;

} // trump

#endif // MASTER_H
