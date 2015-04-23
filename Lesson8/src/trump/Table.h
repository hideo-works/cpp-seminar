#ifndef TABLE_H
#define TABLE_H

#if _MSC_VER > 1000
#pragma warning(disable:4786)
#pragma warning(disable:4661)
#endif

#include <list>
#include <vector>
#include <iostream>

namespace trump {

class Card ;

/**
 * テーブルを表すインターフェース。
 */
class Table
{
public:
  typedef std::list<const Card*>   CardList_t ;
  typedef std::vector<const Card*> CardArray_t ;
  typedef std::vector<CardArray_t> CardMultiArray_t ;

public:
  /** デストラクタ。 */
  virtual ~Table() {}

  /**
   * カードを置く。
   * テーブルに置かれたカードをどのように扱うかは、サブクラスで実装する。
   * 
   * @param cards カード
   */
  virtual void putCard( const CardList_t& cards ) = 0 ;

  /**
   * カードを見る。
   * 
   * @return テーブルに置かれたカードを表す配列
   */
  virtual CardMultiArray_t getCards() const = 0 ;

  /**
   * テーブルを文字列で表現する。
   * 
   * @return 場の文字列表現
   */
  virtual std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Table& table ) ;

} // trump

#endif // TABLE_H
