#ifndef OLDMAIDTABLE_H
#define OLDMAIDTABLE_H

#include <trump/Table.h>

namespace oldmaid {

/**
 * �΂Δ����̃e�[�u����\���N���X�B
 */
class OldMaidTable : public trump::Table
{
private:
  /** �̂Ă�ꂽ�J�[�h��ێ����Ă������߂̃��X�g */
  CardList_t disposedCards_ ;

public:
  /** �f�X�g���N�^�B */
  virtual ~OldMaidTable() ;

  /**
   * �J�[�h���̂Ă�B
   * 
   * @param cards �̂Ă�J�[�h
   */
  void putCard( const CardList_t& cards ) ;

  /**
   * �J�[�h������B
   * 
   * @return �e�[�u���ɒu���ꂽ�J�[�h��\���z��
   */
  CardMultiArray_t getCards() const ;
} ;

} // oldmaid

#endif // OLDMAIDTABLE_H
