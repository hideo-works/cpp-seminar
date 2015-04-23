#ifndef FANTANRULE_H
#define FANTANRULE_H

#include <trump/Rule.h>
#include <trump/Card.h>

namespace fantan {

/**
 * 七並べ用ルールクラス。
 */
class FantanRule : public trump::Rule
{
public:
  /**
   * テーブルに置けるカードを探す。
   * 
   * @param hand 手札
   * @param table テーブル
   * @return 見つかったカードの組み合わせ。見つからなかった場合はサイズが0のリストを返す。
   */
  CardList_t findCandidate( trump::Hand* hand, const trump::Table* table ) ;

private:
  /**
   * テーブルにカードが置かれているか調べる。
   * 
   * @param table テーブル
   * @param suit スート
   * @param number 数
   * @return カードが置かれている場合はtrue
   */
  bool isThereCard( const trump::Table* table, trump::Card::SuitType suit, int number ) const ;
} ;

} // fantan

#endif // FANTANRULE_H
