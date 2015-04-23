#include "Player.h"
#include "Master.h"
#include "Table.h"
#include "Hand.h"
#include "Card.h"

Player::Player( const std::string& name, Master* master, Table* table )
  : name_( name ), master_( master ), table_( table )
{
  myHand_ = new Hand() ;
}


Player::~Player()
{
  delete myHand_ ;
}


void Player::play( Player* nextPlayer )
{
  // ���̃v���C���[�Ɏ�D���o���Ă��炤
  Hand* nextHand = nextPlayer->showHand() ;

  // ����̎�D����J�[�h���ꖇ����
  const Card* pickedCard = nextHand->pickCard() ;

  // ���������ʂ�\��
  std::cout << *this << "�F"
            << *nextPlayer << "���񂩂� " << *pickedCard << " �������܂���\n" ;

  // �������J�[�h�������̎�D�ɉ����A�������̃J�[�h����������̂Ă�
  this->dealCard( pickedCard ) ;

  // ��D���[���ɂȂ������ǂ������ׂ�
  if ( myHand_->getNumberOfCards() == 0 )
  {
    // �i�s���ɏオ���錾����
    master_->declareWin( this ) ;
  }
  else
  {
    // ���݂̎�D��\������
    std::cout << *this << "�F�c��̎�D�� " << *myHand_ << "�ł�\n" ;
  }
}


Hand* Player::showHand()
{
  // �������̎��_�Ŏ�D���c��1���Ȃ�Ώオ��ƂȂ�̂Ő錾����
  if ( myHand_->getNumberOfCards() == 1 )
  {
    master_->declareWin( this ) ;
  }

  // ������O�ɃV���b�t������
  myHand_->shuffle() ;

  return myHand_ ;
}


void Player::receiveCard( const Card* card )
{
  // �������J�[�h�������̎�D�ɉ����A�������̃J�[�h����������̂Ă�
  this->dealCard( card ) ;
}


void Player::dealCard( const Card* card )
{
  // �J�[�h�������̎�D�ɉ�����
  myHand_->addCard( card ) ;

  // ���������J�[�h�Ɠ����J�[�h��T��
  Hand::CardList_t sameCards = myHand_->findSameNumberCard() ;

  // �����J�[�h�̑g�ݍ��킹�����݂����ꍇ
  if ( sameCards.size() > 0 )
  {
      // �e�[�u���փJ�[�h���̂Ă�
    std::cout << *this << "�F" ;
    table_->disposeCard( sameCards ) ;
  }
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
