#include "SimpleJanken.h"
#include <iostream>

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// 　プログラムのスタートはここから
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
void SimpleJanken::main( int argc, char* argv[] )
{
  // プレイヤー１の勝ち数
  int player1WinCount = 0 ;

  // プレイヤー２の勝ち数
  int player2WinCount = 0 ;

  // プレイヤー１が出す手
  HandType player1Hand = STONE ;

  // プレイヤー２が出す手
  HandType player2Hand = STONE ;

  // ジャンケンの手を決めるのに使用する乱数
  int randomNum ;

  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
  // 　① プログラムが開始したことを表示する
  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
  // プログラム開始メッセージを表示する
  std::cout << "【ジャンケン開始】\n\n" ;

  // ジャンケンを３回実施する
  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
  // 　⑥ 勝負した回数を加算する
  // 　⑦ ３回勝負が終わったか？
  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
  for ( int cnt = 0 ; cnt < 3 ; ++cnt )
  {
    // 何回戦目かを表示する
    std::cout << "【" << cnt + 1 << "回戦目】\n" ;

    // ■■■■■■■■■■■■■■■■■■■■■■■■■■
    // 　② プレイヤー１が何を出すか決める
    // ■■■■■■■■■■■■■■■■■■■■■■■■■■
    // 0 以上 3 未満の整数として乱数を得る
    randomNum = rand() % 3 ;

    if ( randomNum < 1 )
    {
      // randomNum が 0 以上 1 未満 の場合、グー
      player1Hand = STONE ;

      // プレイヤー１の手を表示する
      std::cout << "グー" ;
    }
    else if ( randomNum < 2 )
    {
      // randomNum が 1 以上 2 未満 の場合、チョキ
      player1Hand = SCISSORS ;

      // プレイヤー１の手を表示する
      std::cout << "チョキ" ;
    }
    else if ( randomNum < 3 )
    {
      // randomNum が 2 以上 3 未満 の場合、パー
      player1Hand = PAPER ;

      // プレイヤー１の手を表示する
      std::cout << "パー" ;
    }

    std::cout << " vs. " ;

    // ■■■■■■■■■■■■■■■■■■■■■■■■■■
    // 　③ プレイヤー２が何を出すか決める
    // ■■■■■■■■■■■■■■■■■■■■■■■■■■

    // 0 以上 3 未満の整数として乱数を得る
    randomNum = rand() % 3 ;

    if ( randomNum < 1 )
    {
      // randomNum が 0 以上 1 未満 の場合、グー
      player2Hand = STONE ;

      // プレイヤー２の手を表示する
      std::cout << "グー" ;
    }
    else if ( randomNum < 2 )
    {
      // randomNum が 1 以上 2 未満 の場合、チョキ
      player2Hand = SCISSORS ;

      // プレイヤー２の手を表示する
      std::cout << "チョキ" ;
    }
    else if ( randomNum < 3 )
    {
      // randomNum が 2 以上 3 未満 の場合、パー
      player2Hand = PAPER ;

      // プレイヤー３の手を表示する
      std::cout << "パー" ;
    }

    // ■■■■■■■■■■■■■■■■■■■■■■■■■■
    // 　④ どちらが勝ちかを判定し、結果を表示する
    // ■■■■■■■■■■■■■■■■■■■■■■■■■■

    // プレイヤー１が勝つ場合
    if ( ( player1Hand == STONE    && player2Hand == SCISSORS )
      || ( player1Hand == SCISSORS && player2Hand == PAPER    )
      || ( player1Hand == PAPER    && player2Hand == STONE    ) )
    {
      // ジャンケンの結果を表示する
      std::cout << "\nプレイヤー１が勝ちました！\n\n" ;

      // ■■■■■■■■■■■■■■■■■■■■■■■■
      // 　⑤ プレイヤー１の勝った回数を加算する
      // ■■■■■■■■■■■■■■■■■■■■■■■■
      player1WinCount++ ;
    }
    // プレイヤー２が勝つ場合
    else if ( ( player1Hand == STONE    && player2Hand == PAPER    )
           || ( player1Hand == SCISSORS && player2Hand == STONE    )
           || ( player1Hand == PAPER    && player2Hand == SCISSORS ) )
    {
      // ジャンケンの結果を表示する
      std::cout << "\nプレイヤー２が勝ちました！\n\n" ;

      // ■■■■■■■■■■■■■■■■■■■■■■■■
      // 　⑤ プレイヤー２の勝った回数を加算する
      // ■■■■■■■■■■■■■■■■■■■■■■■■
      player2WinCount++ ;
    }
    // 引き分けの場合
    else
    {
      // ジャンケンの結果を表示する
      std::cout << "\n引き分けです！\n\n" ;
    }
  }

  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
  // 　⑧ 最終的な勝者を判定し、画面に表示する
  // ■■■■■■■■■■■■■■■■■■■■■■■■■■■■
      std::cout << "【ジャンケン終了】\n\n" ;

  // プレイヤー１の勝ち数が多い時
  if ( player1WinCount > player2WinCount )
  {
    // プレイヤー１の勝ちを表示する。
    std::cout << player1WinCount << "対" << player2WinCount
              << "でプレイヤー１の勝ちです！\n\n" ;
  }
  // プレイヤー２の勝ち数が多い時
  else if ( player1WinCount < player2WinCount )
  {
    // プレイヤー２の勝ちを表示する。
    std::cout << player1WinCount << "対" << player2WinCount
              << "でプレイヤー２の勝ちです！\n\n" ;
  }
  // プレイヤー１と２の勝ち数が同じ時
  else if ( player1WinCount == player2WinCount )
  {
    // 引き分けを表示する。
    std::cout << player1WinCount << "対" << player2WinCount
              << "で引き分けです！\n\n" ;
  }
}


GENERATE_ENTRY_POINT( SimpleJanken )