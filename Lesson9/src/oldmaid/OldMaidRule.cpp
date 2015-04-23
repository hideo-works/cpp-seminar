#include "OldMaidRule.h"
#include <trump/Hand.h>
#include <trump/Card.h>

using namespace trump ;

namespace oldmaid {

OldMaidRule::CardList_t OldMaidRule::findCandidate( Hand* hand, const Table* table )
{
  // ��D�ɂ���J�[�h�����ԂɌ��ē����l�̑g�ݍ��킹��T��
  // ��D�̋t�����璲�ׂĂ���͍̂Ō�ɒǉ����ꂽ�J�[�h����
  // �D��I�Ƀ`�F�b�N���Ĕ�r�񐔂����炷����
  int numberOfHand = hand->getNumberOfCards() ;
  for ( int position = numberOfHand - 1 ; position >= 0 ; --position )
  {
    const Card* firstCard = hand->lookCard( position ) ;
    for ( int comparePos = position - 1 ; comparePos >= 0 ; --comparePos )
    {
      const Card* secondCard = hand->lookCard( comparePos ) ;

      // �����l�̑g�ݍ��킹������������J�[�h�������Ė߂�
      if ( firstCard->getNumber() == secondCard->getNumber() )
      {
        CardList_t candidate ;
        candidate.push_back( hand->pickCard( position ) ) ;
        candidate.push_back( hand->pickCard( comparePos ) ) ;
        return candidate ;
      }
    }
  }

  // �����l��������Ȃ������ꍇ�A�T�C�Y��0�̃��X�g��Ԃ�
  return CardList_t() ;
}

} // oldmaid
