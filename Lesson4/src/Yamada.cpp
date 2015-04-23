#include "Yamada.h"

Yamada::Yamada( const std::string& name )
  // スーパークラスのコンストラクタを呼び出す
  : Player( name )
{
}


Player::HandType Yamada::showHand()
{
  // 必ずパーを出す
  return PAPER ;
}
