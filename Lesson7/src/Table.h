#ifndef TABLE_H
#define TABLE_H

#include "Card.h"
#include <iostream>

/**
 * テーブルを表すクラス。
 */
class Table
{
  /** カードを並べる場を表す２次元配列 */
  const Card* table_[4][13] ;

public:
  /** コンストラクタ。 */
  Table() ;

  /** デストラクタ。 */
  virtual ~Table() ;

  /**
   * テーブルにカードを置く。
   * 
   * @param card カード
   */
  void putCard( const Card* card ) ;

  /**
   * テーブルにカードが置かれているか調べる。
   * 
   * @return カードが置かれている場合はtrue
   */
  bool isThereCard( Card::SuitType suit, int number ) const ;

  /**
   * テーブルを文字列で表現する。
   * 
   * @return 場の文字列表現
   */
  std::string toString() const ;
} ;


std::ostream& operator << ( std::ostream& output, const Table& table ) ;

#endif // TABLE_H
