#include "Judge.h"
#include <iostream>

void Judge::startJanken( Player* player1, Player* player2 ) const
{
  // �W�����P���̊J�n��錾����
  std::cout << "�y�W�����P���J�n�z\n\n" ;

  // �W�����P����3��s��
  for ( int cnt = 0 ; cnt < 3 ; ++cnt )
  {
    // �����ڂ��\������
    std::cout << "�y" << cnt + 1 << "���ځz\n" ;

    // �v���C���[�̎�����āA�ǂ��炪�������𔻒肷��B
    Player* winner = this->judgeJanken( player1, player2 ) ;

    if ( winner != NULL )
    {
      // ���҂�\������
      std::cout << "\n" << winner->getName() << "�������܂���!\n\n" ;

      // �������v���C���[�֌��ʂ�`����
      winner->notifyResult( true ) ;
    }
    else
    {
      // ���������̏ꍇ
      std::cout << "\n���������ł��I\n\n" ;
    }
  }

  // �W�����P���̏I����錾����
  std::cout << "�y�W�����P���I���z\n\n" ;

  // �ŏI�I�ȏ��҂𔻒肷��
  Player* finalWinner = this->judgeFinalWinner( player1, player2 ) ;

  // ���ʂ̕\��
  std::cout << player1->getWinCount() << " �� " << player2->getWinCount() << "��" ;

  if ( finalWinner != NULL )
  {
    std::cout << finalWinner->getName() << "�̏����ł��I\n\n" ;
  }
  else
  {
    std::cout << "���������ł��I\n\n" ;
  }
}


Player* Judge::judgeJanken( Player* player1, Player* player2 ) const
{
  Player* winner = NULL ;

  // �v���C���[�P�̎���o��
  Player::HandType player1hand = player1->showHand() ;

  // �v���C���[�Q�̎���o��
  Player::HandType player2hand = player2->showHand() ;

  // ���ꂼ��̎��\������
  this->printHand( player1hand ) ;
  std::cout << " vs. " ;
  this->printHand( player2hand ) ;

  // �v���C���[�P�����ꍇ
  if ( ( player1hand == Player::STONE    && player2hand == Player::SCISSORS )
    || ( player1hand == Player::SCISSORS && player2hand == Player::PAPER    )
    || ( player1hand == Player::PAPER    && player2hand == Player::STONE    ) )
  {
    winner = player1 ;
  }
  // �v���C���[�Q�����ꍇ
  else if ( ( player1hand == Player::STONE    && player2hand == Player::PAPER    )
         || ( player1hand == Player::SCISSORS && player2hand == Player::STONE    )
         || ( player1hand == Player::PAPER    && player2hand == Player::SCISSORS ) )
  {
    winner = player2 ;
  }

  // �ǂ���ł��Ȃ��ꍇ�͈�������(null��Ԃ�)

  return winner ;
}


Player* Judge::judgeFinalWinner( Player* player1, Player* player2 ) const
{
  Player* winner = NULL ;

  // Player1���珟�����𕷂�
  int player1WinCount = player1->getWinCount() ;

  // Player2���珟�����𕷂�
  int player2WinCount = player2->getWinCount() ;

  if ( player1WinCount > player2WinCount )
  {
    // �v���C���[1�̏���
    winner = player1 ;
  }
  else if ( player1WinCount < player2WinCount )
  {
    // �v���C���[2�̏���
    winner = player2 ;
  }

  // �ǂ���ł��Ȃ��ꍇ�͈�������(null��Ԃ�)

  return winner ;
}


void Judge::printHand( Player::HandType hand ) const
{
  switch ( hand )
  {
    case Player::STONE :
      std::cout << "�O�[" ;
      break ;

    case Player::SCISSORS :
      std::cout << "�`���L" ;
      break ;

    case Player::PAPER :
      std::cout << "�p�[" ;
      break ;

    default :
      break ;
  }
}
