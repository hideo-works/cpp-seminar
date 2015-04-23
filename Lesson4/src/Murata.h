#ifndef MURATA_H
#define MURATA_H

#include "Player.h"

/**
 * プレイヤーを継承した村田さんクラス。
 */
class Murata : public Player
{
public:
  /**
   * コンストラクタ。
   * 
   * @param name 名前
   */
  Murata( const std::string& name ) ;

  /**
   * ジャンケンの手を出す。
   * スーパークラスの同名メソッドをオーバーライドしている。
   * 
   * @return ジャンケンの手
   */
  HandType showHand() ;
} ;

#endif // MURATA_H
