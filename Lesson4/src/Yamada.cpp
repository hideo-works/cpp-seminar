#include "Yamada.h"

Yamada::Yamada( const std::string& name )
  // �X�[�p�[�N���X�̃R���X�g���N�^���Ăяo��
  : Player( name )
{
}


Player::HandType Yamada::showHand()
{
  // �K���p�[���o��
  return PAPER ;
}
