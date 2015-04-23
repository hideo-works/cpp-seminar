#include "Master.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>

void Master::prepareGame( Hand* cards ) const
{
  std::cout << "【カードを配ります】\n" ;

  // トランプをシャッフルする
  cards->shuffle() ;

  // トランプの枚数を取得する
  int numberOfCards = cards->getNumberOfCards() ;

  // プレイヤーの人数を取得する
  int numberOfPlayers = players_.size() ;

  for ( int index = 0 ; index < numberOfCards ; ++index )
  {
    // カードから一枚引く
    const Card* card = cards->pickCard() ;

    // 各プレイヤーに順番にカードを配る
    Player* player = players_.at( index % numberOfPlayers ) ;
    player->receiveCard( card ) ;
  }
}


void Master::startGame()
{
  std::cout << "\n【ばば抜きを開始します】\n" ;

  // プレイヤーの人数を取得する
  for ( int count = 0 ; players_.size() > 1 ; ++count )
  {
    int playerIndex = count % players_.size() ;
    int nextPlayerIndex = (count + 1) % players_.size() ;

    // 指名するプレイヤーの取得
    Player* player = players_.at( playerIndex ) ;

    // 次のプレイヤーの取得
    Player* nextPlayer = players_.at( nextPlayerIndex ) ;

    // プレイヤーを指名する
    std::cout << "\n" << *player << "さんの番です\n" ;
    player->play( nextPlayer ) ;
  }

  // プレイヤーが上がって残り1名になるとループを抜ける
  std::cout << "【ばば抜きを終了しました】\n" ;
}


void Master::declareWin( const Player* winner )
{
  // 上がったプレイヤー
  std::cout << *winner << "さんが上がりました！\n" ;

  // 上がったプレイヤーをリストからはずす
  PlayerArray_t::iterator it  = players_.begin() ;
  PlayerArray_t::iterator end = players_.end() ;
  for ( ; it != end ; ++it )
  {
    if ( *it == winner ) {
      players_.erase( it ) ;
      break ;
    }
  }

  // 残りプレイヤーが１人になった時は敗者を表示する
  if ( players_.size() == 1 )
  {
    Player* loser = players_.at( 0 ) ;
    std::cout << *loser << "さんの負けです！\n" ;
  }
}


void Master::registerPlayer( Player* player )
{
  // リストに参加者を追加する
  players_.push_back( player ) ;
}
