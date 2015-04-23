#ifndef TABLE_H
#define TABLE_H

#include <list>

class Card ;

/**
 * テーブルを表すクラス。
 */
class Table
{
public:
  typedef std::list<const Card*> CardList_t ;

private:
  /** 捨てられたカードを保持しておくためのリスト */
  CardList_t disposedCards_ ;

public:
  /** デストラクタ。 */
  virtual ~Table() ;

  /**
   * カードを捨てる。
   * 
   * @param cards 捨てるカードの配列
   */
  void disposeCard( const CardList_t& cards ) ;
} ;

#endif // TABLE_H
