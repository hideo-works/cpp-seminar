#include "Murata.h"

Murata::Murata( const std::string& name )
  // �X�[�p�[�N���X�̃R���X�g���N�^���Ăяo��
  : Player( name )
{
}


Player::HandType Murata::showHand()
{
  // �K���O�[���o��
  return STONE ;
}
