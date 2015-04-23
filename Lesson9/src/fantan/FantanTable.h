#ifndef FANTANTABLE_H
#define FANTANTABLE_H

#include <trump/Table.h>

namespace fantan {

/**
 * �����ׂ̃e�[�u����\���N���X�B
 */
class FantanTable : public trump::Table
{
private:
  /** �J�[�h����ׂ�e�[�u����\���Q�����z�� */
  CardMultiArray_t table_ ;

public:
  /** �R���X�g���N�^�B */
  FantanTable() ;

  /** �f�X�g���N�^�B */
  virtual ~FantanTable() ;

  /**
   * �J�[�h��u���B
   * 
   * @param card �J�[�h
   */
  void putCard( const CardList_t& cards ) ;

  /**
   * �J�[�h������B
   * 
   * @return �e�[�u���ɒu���ꂽ�J�[�h��\���z��
   */
  CardMultiArray_t getCards() const ;

  /**
   * �e�[�u���𕶎���ŕ\������B
   * 
   * @return ��̕�����\��
   */
  std::string toString() const ;
} ;

} // fantan

#endif // FANTANTABLE_H
