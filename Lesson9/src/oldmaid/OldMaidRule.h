#ifndef OLDMAIDRULE_H
#define OLDMAIDRULE_H

#include <trump/Rule.h>

namespace oldmaid {

/**
 * ばば抜き用ルールクラス。
 */
class OldMaidRule : public trump::Rule
{
public:
  /**
   * 手札とテーブルから、テーブルに出しうるカードの組み合わせを探す。
   * 
   * @param hand  手札
   * @param table テーブル
   * @return 見つかったカードの組み合わせ。見つからなかった場合はサイズが0のリストを返す。
   */
  CardList_t findCandidate( trump::Hand* hand, const trump::Table* table ) ;
} ;

} // oldmaid

#endif // OLDMAIDRULE_H
