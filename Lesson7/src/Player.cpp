#include "Player.h"
#include "Table.h"
#include "Hand.h"
#include "Card.h"
#include "Master.h"

Player::Player( const std::string& name, Master* master, Table* table )
  : name_( name ), master_( master ), table_( table ), pass_( 0 )
{
  myHand_ = new Hand() ;
}


Player::~Player()
{
  delete myHand_ ;
}


void Player::play()
{
  // ���݂̎�D��\������
  std::cout << "  " << *myHand_ << "\n" ;
  
  // ��D�ɂ���J�[�h��1�����`�F�b�N���āA��ɒu���邩���ׂ�
  int handSize = myHand_->getNumberOfCards() ;
  for ( int position = 0 ; position < handSize ; ++position )
  {
    // ��D�ɂ���J�[�h������
    const Card* lookingCard = myHand_->lookCard( position ) ;

    int number = lookingCard->getNumber() ;
    Card::SuitType suit = lookingCard->getSuit() ;

    // �����ڂ��Ă����D�̍����E�ɃJ�[�h������΁A�J�[�h��u����
    int leftNumber = (number != 1) ? number - 1 : 13 ;
    int rightNumber = (number != 13) ? number + 1 : 1 ;

    if ( ( true == table_->isThereCard( suit, leftNumber ) )
      || ( true == table_->isThereCard(suit, rightNumber ) ) )
    {
      // ��D����J�[�h�������ăe�[�u���ɒu��
      table_->putCard( myHand_->pickCard( position ) ) ;

      // ��D���Ȃ��Ȃ�����A�オ���錾����
      if ( myHand_->getNumberOfCards() == 0 )
      {
        master_->declareWin( this ) ;
      }

      return ;
    }
  }

  // �e�[�u���ɒu����J�[�h���Ȃ������ꍇ�A�p�X����
  ++pass_ ;
  master_->pass( this ) ;

  // �p�X�񐔂�4��ȏ�Ȃ�΃J�[�h��S�ăe�[�u���ɒu��
  if ( pass_ > 3 )
  {
    // ��D��S�ăe�[�u���ɒu��
    for ( int count = 0 ; count < handSize ; ++count )
    {
      table_->putCard( myHand_->pickCard( 0 ) ) ;
    }
  }
}


void Player::receiveCard( const Card* card )
{
  if ( card->getNumber() == 7 )
  {
    // �J�[�h��7�̏ꍇ�́A�e�[�u���ɃJ�[�h��u��
    table_->putCard( card ) ;
  }
  else
  {
    // �J�[�h��7�łȂ��ꍇ�́A�󂯎�����J�[�h����D�։�����
    myHand_->addCard( card ) ;
  }
}


int Player::getPass() const
{
  return pass_ ;
}


std::string Player::toString() const
{
  return name_ ;
}


std::ostream& operator << ( std::ostream& output, const Player& player )
{
  output << player.toString() ;
  return output ;
}
