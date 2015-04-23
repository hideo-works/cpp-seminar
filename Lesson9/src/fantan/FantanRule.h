#ifndef FANTANRULE_H
#define FANTANRULE_H

#include <trump/Rule.h>
#include <trump/Card.h>

namespace fantan {

/**
 * �����חp���[���N���X�B
 */
class FantanRule : public trump::Rule
{
public:
  /**
   * �e�[�u���ɒu����J�[�h��T���B
   * 
   * @param hand ��D
   * @param table �e�[�u��
   * @return ���������J�[�h�̑g�ݍ��킹�B������Ȃ������ꍇ�̓T�C�Y��0�̃��X�g��Ԃ��B
   */
  CardList_t findCandidate( trump::Hand* hand, const trump::Table* table ) ;

private:
  /**
   * �e�[�u���ɃJ�[�h���u����Ă��邩���ׂ�B
   * 
   * @param table �e�[�u��
   * @param suit �X�[�g
   * @param number ��
   * @return �J�[�h���u����Ă���ꍇ��true
   */
  bool isThereCard( const trump::Table* table, trump::Card::SuitType suit, int number ) const ;
} ;

} // fantan

#endif // FANTANRULE_H
