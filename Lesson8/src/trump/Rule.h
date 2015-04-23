#ifndef RULE_H
#define RULE_H

#include <list>

namespace trump {

class Card ;
class Hand ;
class Table ;

/**
 * トランプルールインターフェース。
 * 現在の手札とテーブルから、テーブルに出しうるカードの組み合わせを見つける。
 */
class Rule
{
public:
  typedef std::list<const Card*> CardList_t ;

public:
  /** デストラクタ。 */
  virtual ~Rule() {}

  /**
   * テーブルに置けるカードを探す。
   * 手札とテーブルから、テーブルに出しうるカードの組み合わせを探す。
   * 
   * @param hand 手札
   * @param table テーブル
   * @return 見つかったカードの組み合わせ。見つからなかった場合はサイズが0のリストを返す。
   */
  virtual CardList_t findCandidate( Hand* hand, const Table* table ) = 0 ;
} ;

} // trump

#endif // RULE_H
