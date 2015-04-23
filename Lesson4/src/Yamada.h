#ifndef YAMADA_H
#define YAMADA_H

#include "Player.h"

/**
 * プレイヤーを継承した山田さんクラス。
 */
class Yamada : public Player
{
public:
  /**
   * コンストラクタ。
   * 
   * @param name 名前
   */
  Yamada( const std::string& name ) ;

  /**
   * ジャンケンの手を出す。
   * スーパークラスの同名メソッドをオーバーライドしている。
   * 
   * @return ジャンケンの手
   */
  HandType showHand() ;
} ;

#endif // YAMADA_H
