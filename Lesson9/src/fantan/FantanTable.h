#ifndef FANTANTABLE_H
#define FANTANTABLE_H

#include <trump/Table.h>

namespace fantan {

/**
 * 七並べのテーブルを表すクラス。
 */
class FantanTable : public trump::Table
{
private:
  /** カードを並べるテーブルを表す２次元配列 */
  CardMultiArray_t table_ ;

public:
  /** コンストラクタ。 */
  FantanTable() ;

  /** デストラクタ。 */
  virtual ~FantanTable() ;

  /**
   * カードを置く。
   * 
   * @param card カード
   */
  void putCard( const CardList_t& cards ) ;

  /**
   * カードを見る。
   * 
   * @return テーブルに置かれたカードを表す配列
   */
  CardMultiArray_t getCards() const ;

  /**
   * テーブルを文字列で表現する。
   * 
   * @return 場の文字列表現
   */
  std::string toString() const ;
} ;

} // fantan

#endif // FANTANTABLE_H
