#include "Murata.h"

Murata::Murata( const std::string& name )
  // スーパークラスのコンストラクタを呼び出す
  : Player( name )
{
}


Player::HandType Murata::showHand()
{
  // 必ずグーを出す
  return STONE ;
}
