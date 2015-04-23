#ifndef TABLE_H
#define TABLE_H

#include "Card.h"
#include <iostream>

/**
 * �e�[�u����\���N���X�B
 */
class Table
{
  /** �J�[�h����ׂ���\���Q�����z�� */
  const Card* table_[4][13] ;

public:
  /** �R���X�g���N�^�B */
  Table() ;

  /** �f�X�g���N�^�B */
  virtual ~Table() ;

  /**
   * �e�[�u���ɃJ�[�h��u���B
   * 
   * @param card �J�[�h
   */
  void putCard( const Card* card ) ;

  /**
   * �e�[�u���ɃJ�[�h���u����Ă��邩���ׂ�B
   * 
   * @return �J�[�h���u����Ă���ꍇ��true
   */
  bool isThereCard( Card::SuitType suit, int number ) const ;

  /**
   * �e�[�u���𕶎���ŕ\������B
   * 
   * @return ��̕�����\��
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Table& table ) ;

#endif // TABLE_H
