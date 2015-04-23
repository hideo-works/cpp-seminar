#include "Judge.h"
#include <iostream>

void Judge::startJanken( Player* player1, Player* player2 ) const
{
  // ジャンケンの開始を宣言する
  std::cout << "【ジャンケン開始】\n\n" ;

  // ジャンケンを3回行う
  for ( int cnt = 0 ; cnt < 3 ; ++cnt )
  {
    // 何回戦目か表示する
    std::cout << "【" << cnt + 1 << "回戦目】\n" ;

    // プレイヤーの手を見て、どちらが勝ちかを判定する。
    Player* winner = this->judgeJanken( player1, player2 ) ;

    if ( winner != NULL )
    {
      // 勝者を表示する
      std::cout << "\n" << winner->getName() << "が勝ちました!\n\n" ;

      // 勝ったプレイヤーへ結果を伝える
      winner->notifyResult( true ) ;
    }
    else
    {
      // 引き分けの場合
      std::cout << "\n引き分けです！\n\n" ;
    }
  }

  // ジャンケンの終了を宣言する
  std::cout << "【ジャンケン終了】\n\n" ;

  // 最終的な勝者を判定する
  Player* finalWinner = this->judgeFinalWinner( player1, player2 ) ;

  // 結果の表示
  std::cout << player1->getWinCount() << " 対 " << player2->getWinCount() << "で" ;

  if ( finalWinner != NULL )
  {
    std::cout << finalWinner->getName() << "の勝ちです！\n\n" ;
  }
  else
  {
    std::cout << "引き分けです！\n\n" ;
  }
}


Player* Judge::judgeJanken( Player* player1, Player* player2 ) const
{
  Player* winner = NULL ;

  // プレイヤー１の手を出す
  Player::HandType player1hand = player1->showHand() ;

  // プレイヤー２の手を出す
  Player::HandType player2hand = player2->showHand() ;

  // それぞれの手を表示する
  this->printHand( player1hand ) ;
  std::cout << " vs. " ;
  this->printHand( player2hand ) ;

  // プレイヤー１が勝つ場合
  if ( ( player1hand == Player::STONE    && player2hand == Player::SCISSORS )
    || ( player1hand == Player::SCISSORS && player2hand == Player::PAPER    )
    || ( player1hand == Player::PAPER    && player2hand == Player::STONE    ) )
  {
    winner = player1 ;
  }
  // プレイヤー２が勝つ場合
  else if ( ( player1hand == Player::STONE    && player2hand == Player::PAPER    )
         || ( player1hand == Player::SCISSORS && player2hand == Player::STONE    )
         || ( player1hand == Player::PAPER    && player2hand == Player::SCISSORS ) )
  {
    winner = player2 ;
  }

  // どちらでもない場合は引き分け(nullを返す)

  return winner ;
}


Player* Judge::judgeFinalWinner( Player* player1, Player* player2 ) const
{
  Player* winner = NULL ;

  // Player1から勝ち数を聞く
  int player1WinCount = player1->getWinCount() ;

  // Player2から勝ち数を聞く
  int player2WinCount = player2->getWinCount() ;

  if ( player1WinCount > player2WinCount )
  {
    // プレイヤー1の勝ち
    winner = player1 ;
  }
  else if ( player1WinCount < player2WinCount )
  {
    // プレイヤー2の勝ち
    winner = player2 ;
  }

  // どちらでもない場合は引き分け(nullを返す)

  return winner ;
}


void Judge::printHand( Player::HandType hand ) const
{
  switch ( hand )
  {
    case Player::STONE :
      std::cout << "グー" ;
      break ;

    case Player::SCISSORS :
      std::cout << "チョキ" ;
      break ;

    case Player::PAPER :
      std::cout << "パー" ;
      break ;

    default :
      break ;
  }
}
