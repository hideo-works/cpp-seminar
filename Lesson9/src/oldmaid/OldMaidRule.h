#ifndef OLDMAIDRULE_H
#define OLDMAIDRULE_H

#include <trump/Rule.h>

namespace oldmaid {

/**
 * �΂Δ����p���[���N���X�B
 */
class OldMaidRule : public trump::Rule
{
public:
  /**
   * ��D�ƃe�[�u������A�e�[�u���ɏo������J�[�h�̑g�ݍ��킹��T���B
   * 
   * @param hand  ��D
   * @param table �e�[�u��
   * @return ���������J�[�h�̑g�ݍ��킹�B������Ȃ������ꍇ�̓T�C�Y��0�̃��X�g��Ԃ��B
   */
  CardList_t findCandidate( trump::Hand* hand, const trump::Table* table ) ;
} ;

} // oldmaid

#endif // OLDMAIDRULE_H
