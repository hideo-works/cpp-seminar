#include "FantanPlayer.h"
#include "FantanMaster.h"
#include <trump/Card.h>
#include <trump/Hand.h>
#include <trump/Rule.h>
#include <trump/Table.h>

using namespace trump ;

namespace fantan {

FantanPlayer::FantanPlayer( const std::string& name, Master* master, Table* table, Rule* rule )
  : Player( name, master, table, rule ), pass_( 0 )
{
}


void FantanPlayer::receiveCard( const Card* card )
{
  if ( card->getNumber() == 7 )
  {
    // �J�[�h��7�̏ꍇ�́A�e�[�u���ɃJ�[�h��u��
    std::cout << name_ << "�F" << *card << "��u���܂����B\n" ;
    Table::CardList_t cards ;
    cards.push_back( card ) ;
    table_->putCard( cards ) ;
  }
  else
  {
    // �J�[�h��7�łȂ��ꍇ�́A�󂯎�����J�[�h����D�։�����
    Player::receiveCard( card ) ;
  }
}


void FantanPlayer::play( Player* nextPlayer )
{
  // ���݂̎�D��\������
  std::cout << "  " << *myHand_ << "\n" ;

  // ���݂̎�D����e�[�u���ɏo������̂�T��
  Rule::CardList_t candidate = rule_->findCandidate( myHand_, table_ ) ;

  // ��₪����ꍇ�̓e�[�u���ɏo��
  if ( candidate.size() > 0 )
  {
    std::cout << "  " << *candidate.front() << "��u���܂����B\n\n" ;
    table_->putCard( candidate ) ;

    // �e�[�u���̏�Ԃ�\������
    std::cout << *table_ << "\n" ;

    // ��D���Ȃ��Ȃ�����A�オ���錾����
    if ( myHand_->getNumberOfCards() == 0 )
    {
      master_->declareWin( this ) ;
    }
  }
  else
  {
    // �e�[�u���ɏo����J�[�h���Ȃ������ꍇ�A�p�X����
    ++pass_ ;
    static_cast<FantanMaster*>(master_)->pass( this ) ;

    // �p�X�񐔂������񐔈ȏ�Ȃ�΃J�[�h��S�ăe�[�u���ɒu��
    if ( pass_ > FantanMaster::PASS_LIMIT )
    {
      int numberOfHand = myHand_->getNumberOfCards() ;
      // ��D��S�ăe�[�u���ɒu��
      for ( int count = 0 ; count < numberOfHand ; ++count )
      {
        Table::CardList_t cards ;
        cards.push_back( myHand_->pickCard( 0 ) ) ;
        table_->putCard( cards ) ;
      }
    }
  }
}


int FantanPlayer::getPass() const
{
  return pass_ ;
}

} // fantan
