#ifndef OLDMAIDTABLE_H
#define OLDMAIDTABLE_H

#include <trump/Table.h>

namespace oldmaid {

/**
 * ばば抜きのテーブルを表すクラス。
 */
class OldMaidTable : public trump::Table
{
private:
  /** 捨てられたカードを保持しておくためのリスト */
  CardList_t disposedCards_ ;

public:
  /** デストラクタ。 */
  virtual ~OldMaidTable() ;

  /**
   * カードを捨てる。
   * 
   * @param cards 捨てるカード
   */
  void putCard( const CardList_t& cards ) ;

  /**
   * カードを見る。
   * 
   * @return テーブルに置かれたカードを表す配列
   */
  CardMultiArray_t getCards() const ;
} ;

} // oldmaid

#endif // OLDMAIDTABLE_H
