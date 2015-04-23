#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Table ;
class Hand ;
class Master ;
class Card ;

/**
 * �v���C���[��\���N���X�B
 */
class Player
{
private:
  /** ���O */
  std::string name_ ;

  /** �e�[�u�� */
  Table* table_ ;

  /** ��D */
  Hand* myHand_ ;

  /** �i�s�� */
  Master* master_ ;

  /** �p�X������ */
  int pass_ ;

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
   */
  void play() ;

  /**
   * �J�[�h���󂯎��B
   * 
   * @param card �󂯎�����J�[�h
   */
  void receiveCard( const Card* card ) ;

  /**
   * �p�X�񐔂𕷂��B
   * 
   * @return �p�X��
   */
  int getPass() const ;

  /**
   * �v���C���[�̖��O��Ԃ��B
   * 
   * @return �v���C���[�̖��O
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Player& player ) ;

#endif // PLAYER_H
