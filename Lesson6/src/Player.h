#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Master ;
class Table ;
class Hand ;
class Card ;

/**
 * �΂Δ����̃v���C���[�N���X�B
 */
class Player
{
private:
  /** �i�s�� */
  Master* master_ ;

  /** �e�[�u�� */
  Table* table_ ;

  /** �����̎�D */
  Hand* myHand_ ;

  /** ���O */
  std::string name_ ;

public:
  /**
   * �R���X�g���N�^�B
   * 
   * @param name ���O
   * @param master �i�s��
   * @param table �e�[�u��
   */
  Player( const std::string& name, Master* master, Table* table ) ;

  /** �f�X�g���N�^�B */
  virtual ~Player() ;

  /**
   * ���Ԃ��w������B
   * 
   * @param nextPlayer ���̃v���C���[
   */
  void play( Player* nextPlayer ) ;

  /**
   * ��D��������B
   * 
   * @return �����̎�D
   */
  Hand* showHand() ;

  /**
   * �J�[�h���󂯎��B
   * 
   * @param card �󂯎�����J�[�h
   */
  void receiveCard( const Card* card ) ;

  /**
   * �v���C���[�̖��O��Ԃ��B
   * 
   * @return �v���C���[�̖��O
   */
  std::string toString() const ;

private:
  /**
   * �J�[�h�������̎�D�ɉ����A�������̃J�[�h����������̂Ă�B
   * 
   * @param card
   */
  void dealCard( const Card* card ) ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

#endif // PLAYER_H
