#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

namespace trump {

class Table ;
class Hand ;
class Master ;
class Rule ;
class Card ;

/**
 * �v���C���[��\���N���X�B
 */
class Player
{
protected:
  /** ���O */
  std::string name_ ;

  /** �e�[�u�� */
  Table* table_ ;

  /** ��D */
  Hand* myHand_ ;

  /** �i�s�� */
  Master* master_ ;
  
  /** ���[�� */
  Rule* rule_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name ���O
   * @param master �i�s��
   * @param table �e�[�u��
   * @param rule ���[��
   */
  Player( const std::string& name, Master* master, Table* table, Rule* rule ) ;

  /** �f�X�g���N�^�B */
  virtual ~Player() ;

  /**
   * ���Ԃ��w������B
   * ���ۂ̏����̓T�u�N���X�ŋL�q���邱�ƁB
   * 
   * @param nextPlayer ���̃v���C���[
   */
  virtual void play( Player* nextPlayer ) = 0 ;

  /**
   * �J�[�h��z��B
   * �J�[�h���󂯎�������̏������g���������ꍇ�́A
   * �{���\�b�h���T�u�N���X�ŃI�[�o�[���C�h���邱�ƁB
   *
   * @param card �󂯎�����J�[�h
   */
  virtual void receiveCard( const Card* card ) ;

  /**
   * �v���C���[�̖��O��Ԃ��B
   * 
   * @return �v���C���[�̖��O
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

} // trump

#endif // PLAYER_H
