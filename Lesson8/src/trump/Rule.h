#ifndef RULE_H
#define RULE_H

#include <list>

namespace trump {

class Card ;
class Hand ;
class Table ;

/**
 * �g�����v���[���C���^�[�t�F�[�X�B
 * ���݂̎�D�ƃe�[�u������A�e�[�u���ɏo������J�[�h�̑g�ݍ��킹��������B
 */
class Rule
{
public:
  typedef std::list<const Card*> CardList_t ;

public:
  /** �f�X�g���N�^�B */
  virtual ~Rule() {}

  /**
   * �e�[�u���ɒu����J�[�h��T���B
   * ��D�ƃe�[�u������A�e�[�u���ɏo������J�[�h�̑g�ݍ��킹��T���B
   * 
   * @param hand ��D
   * @param table �e�[�u��
   * @return ���������J�[�h�̑g�ݍ��킹�B������Ȃ������ꍇ�̓T�C�Y��0�̃��X�g��Ԃ��B
   */
  virtual CardList_t findCandidate( Hand* hand, const Table* table ) = 0 ;
} ;

} // trump

#endif // RULE_H
