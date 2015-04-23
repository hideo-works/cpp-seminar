#ifndef TABLE_H
#define TABLE_H

#include <list>

class Card ;

/**
 * �e�[�u����\���N���X�B
 */
class Table
{
public:
  typedef std::list<const Card*> CardList_t ;

private:
  /** �̂Ă�ꂽ�J�[�h��ێ����Ă������߂̃��X�g */
  CardList_t disposedCards_ ;

public:
  /** �f�X�g���N�^�B */
  virtual ~Table() ;

  /**
   * �J�[�h���̂Ă�B
   * 
   * @param cards �̂Ă�J�[�h�̔z��
   */
  void disposeCard( const CardList_t& cards ) ;
} ;

#endif // TABLE_H
