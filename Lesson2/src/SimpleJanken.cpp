#include "SimpleJanken.h"
#include <iostream>

// ������������������������������������������������������������
// �@�v���O�����̃X�^�[�g�͂�������
// ������������������������������������������������������������
void SimpleJanken::main( int argc, char* argv[] )
{
  // �v���C���[�P�̏�����
  int player1WinCount = 0 ;

  // �v���C���[�Q�̏�����
  int player2WinCount = 0 ;

  // �v���C���[�P���o����
  HandType player1Hand = STONE ;

  // �v���C���[�Q���o����
  HandType player2Hand = STONE ;

  // �W�����P���̎�����߂�̂Ɏg�p���闐��
  int randomNum ;

  // ��������������������������������������������������������
  // �@�@ �v���O�������J�n�������Ƃ�\������
  // ��������������������������������������������������������
  // �v���O�����J�n���b�Z�[�W��\������
  std::cout << "�y�W�����P���J�n�z\n\n" ;

  // �W�����P�����R����{����
  // ��������������������������������������������������������
  // �@�E ���������񐔂����Z����
  // �@�F �R�񏟕����I��������H
  // ��������������������������������������������������������
  for ( int cnt = 0 ; cnt < 3 ; ++cnt )
  {
    // �����ڂ���\������
    std::cout << "�y" << cnt + 1 << "���ځz\n" ;

    // ����������������������������������������������������
    // �@�A �v���C���[�P�������o�������߂�
    // ����������������������������������������������������
    // 0 �ȏ� 3 �����̐����Ƃ��ė����𓾂�
    randomNum = rand() % 3 ;

    if ( randomNum < 1 )
    {
      // randomNum �� 0 �ȏ� 1 ���� �̏ꍇ�A�O�[
      player1Hand = STONE ;

      // �v���C���[�P�̎��\������
      std::cout << "�O�[" ;
    }
    else if ( randomNum < 2 )
    {
      // randomNum �� 1 �ȏ� 2 ���� �̏ꍇ�A�`���L
      player1Hand = SCISSORS ;

      // �v���C���[�P�̎��\������
      std::cout << "�`���L" ;
    }
    else if ( randomNum < 3 )
    {
      // randomNum �� 2 �ȏ� 3 ���� �̏ꍇ�A�p�[
      player1Hand = PAPER ;

      // �v���C���[�P�̎��\������
      std::cout << "�p�[" ;
    }

    std::cout << " vs. " ;

    // ����������������������������������������������������
    // �@�B �v���C���[�Q�������o�������߂�
    // ����������������������������������������������������

    // 0 �ȏ� 3 �����̐����Ƃ��ė����𓾂�
    randomNum = rand() % 3 ;

    if ( randomNum < 1 )
    {
      // randomNum �� 0 �ȏ� 1 ���� �̏ꍇ�A�O�[
      player2Hand = STONE ;

      // �v���C���[�Q�̎��\������
      std::cout << "�O�[" ;
    }
    else if ( randomNum < 2 )
    {
      // randomNum �� 1 �ȏ� 2 ���� �̏ꍇ�A�`���L
      player2Hand = SCISSORS ;

      // �v���C���[�Q�̎��\������
      std::cout << "�`���L" ;
    }
    else if ( randomNum < 3 )
    {
      // randomNum �� 2 �ȏ� 3 ���� �̏ꍇ�A�p�[
      player2Hand = PAPER ;

      // �v���C���[�R�̎��\������
      std::cout << "�p�[" ;
    }

    // ����������������������������������������������������
    // �@�C �ǂ��炪�������𔻒肵�A���ʂ�\������
    // ����������������������������������������������������

    // �v���C���[�P�����ꍇ
    if ( ( player1Hand == STONE    && player2Hand == SCISSORS )
      || ( player1Hand == SCISSORS && player2Hand == PAPER    )
      || ( player1Hand == PAPER    && player2Hand == STONE    ) )
    {
      // �W�����P���̌��ʂ�\������
      std::cout << "\n�v���C���[�P�������܂����I\n\n" ;

      // ������������������������������������������������
      // �@�D �v���C���[�P�̏������񐔂����Z����
      // ������������������������������������������������
      player1WinCount++ ;
    }
    // �v���C���[�Q�����ꍇ
    else if ( ( player1Hand == STONE    && player2Hand == PAPER    )
           || ( player1Hand == SCISSORS && player2Hand == STONE    )
           || ( player1Hand == PAPER    && player2Hand == SCISSORS ) )
    {
      // �W�����P���̌��ʂ�\������
      std::cout << "\n�v���C���[�Q�������܂����I\n\n" ;

      // ������������������������������������������������
      // �@�D �v���C���[�Q�̏������񐔂����Z����
      // ������������������������������������������������
      player2WinCount++ ;
    }
    // ���������̏ꍇ
    else
    {
      // �W�����P���̌��ʂ�\������
      std::cout << "\n���������ł��I\n\n" ;
    }
  }

  // ��������������������������������������������������������
  // �@�G �ŏI�I�ȏ��҂𔻒肵�A��ʂɕ\������
  // ��������������������������������������������������������
      std::cout << "�y�W�����P���I���z\n\n" ;

  // �v���C���[�P�̏�������������
  if ( player1WinCount > player2WinCount )
  {
    // �v���C���[�P�̏�����\������B
    std::cout << player1WinCount << "��" << player2WinCount
              << "�Ńv���C���[�P�̏����ł��I\n\n" ;
  }
  // �v���C���[�Q�̏�������������
  else if ( player1WinCount < player2WinCount )
  {
    // �v���C���[�Q�̏�����\������B
    std::cout << player1WinCount << "��" << player2WinCount
              << "�Ńv���C���[�Q�̏����ł��I\n\n" ;
  }
  // �v���C���[�P�ƂQ�̏�������������
  else if ( player1WinCount == player2WinCount )
  {
    // ����������\������B
    std::cout << player1WinCount << "��" << player2WinCount
              << "�ň��������ł��I\n\n" ;
  }
}


GENERATE_ENTRY_POINT( SimpleJanken )