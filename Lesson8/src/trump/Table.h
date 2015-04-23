#ifndef TABLE_H
#define TABLE_H

#if _MSC_VER > 1000
#pragma warning(disable:4786)
#pragma warning(disable:4661)
#endif

#include <list>
#include <vector>
#include <iostream>

namespace trump {

class Card ;

/**
 * �e�[�u����\���C���^�[�t�F�[�X�B
 */
class Table
{
public:
  typedef std::list<const Card*>   CardList_t ;
  typedef std::vector<const Card*> CardArray_t ;
  typedef std::vector<CardArray_t> CardMultiArray_t ;

public:
  /** �f�X�g���N�^�B */
  virtual ~Table() {}

  /**
   * �J�[�h��u���B
   * �e�[�u���ɒu���ꂽ�J�[�h���ǂ̂悤�Ɉ������́A�T�u�N���X�Ŏ�������B
   * 
   * @param cards �J�[�h
   */
  virtual void putCard( const CardList_t& cards ) = 0 ;

  /**
   * �J�[�h������B
   * 
   * @return �e�[�u���ɒu���ꂽ�J�[�h��\���z��
   */
  virtual CardMultiArray_t getCards() const = 0 ;

  /**
   * �e�[�u���𕶎���ŕ\������B
   * 
   * @return ��̕�����\��
   */
  virtual std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Table& table ) ;

} // trump

#endif // TABLE_H
