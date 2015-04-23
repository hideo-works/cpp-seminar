#include "AskTactics.h"
#include <iostream>

Player::HandType AskTactics::readTactics()
{
  std::cout << "\nジャンケンの手を入力して下さい。\n"
            << "1: グー\n"
            << "2: チョキ\n"
            << "3: パー\n\n" ;

  // ジャンケンの手
  Player::HandType hand = Player::STONE ;

  while ( true ) {
    std::cout << "? " ;

    int input ;

    // 入力文字列を受け取る
    std::cin >> input ;

    // 1 ～ 3 のいずれかが入力されたらループを抜ける
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
      std::cout << "入力が正しくありません。再度入力して下さい。\n" ;
    }

    // 整数以外が入力された場合には例外をスロー
    std::cin.exceptions( std::ios::badbit | std::ios::failbit ) ;
  }

  return hand ;
}
