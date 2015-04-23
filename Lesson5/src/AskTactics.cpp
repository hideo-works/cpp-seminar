#include "AskTactics.h"
#include <iostream>

Player::HandType AskTactics::readTactics()
{
  std::cout << "\n�W�����P���̎����͂��ĉ������B\n"
            << "1: �O�[\n"
            << "2: �`���L\n"
            << "3: �p�[\n\n" ;

  // �W�����P���̎�
  Player::HandType hand = Player::STONE ;

  while ( true ) {
    std::cout << "? " ;

    int input ;

    // ���͕�������󂯎��
    std::cin >> input ;

    // 1 �` 3 �̂����ꂩ�����͂��ꂽ�烋�[�v�𔲂���
    if ( 1 <= input && input <= 3 ) {
      switch ( input ) {
        case 1 :
          hand = Player::STONE ;
          break ;

        case 2 :
          hand = Player::SCISSORS ;
          break ;

        case 3 :
          hand = Player::PAPER ;
          break ;

        default :
          break ;
      }
      break ;
    }
    else {
      std::cout << "���͂�����������܂���B�ēx���͂��ĉ������B\n" ;
    }

    // �����ȊO�����͂��ꂽ�ꍇ�ɂ͗�O���X���[
    std::cin.exceptions( std::ios::badbit | std::ios::failbit ) ;
  }

  return hand ;
}
