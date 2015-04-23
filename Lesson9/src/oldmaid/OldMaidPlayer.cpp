#include "OldMaidPlayer.h"
#include "BackHand.h"
#include <trump/Rule.h>
#include <trump/Table.h>
#include <trump/Hand.h>
#include <trump/Master.h>
#include <trump/Card.h>

using namespace trump ;

namespace oldmaid {

OldMaidPlayer::OldMaidPlayer( const std::string& name, Master* master, Table* table, Rule* rule )
  : Player( name, master, table, rule )
{
  backHand_ = new BackHand( myHand_ ) ;
}


OldMaidPlayer::~OldMaidPlayer()
{
  delete backHand_ ;
}


void OldMaidPlayer::receiveCard( const Card* card )
{
  // �󂯎�����J�[�h����D�։�����
  Player::receiveCard( card ) ;

  // ���[�����g�p���ăe�[�u���ɏo����J�[�h�����邩�T��
  Rule::CardList_t candidate = rule_->findCandidate( myHand_, table_ ) ;

  // �e�[�u���ɏo����J�[�h������ꍇ�͏�ɏo��
  if ( candidate.size() > 0 )
  {
    std::cout << *this << "�F" ;
    table_->putCard( candidate ) ;
  }
}


void OldMaidPlayer::play( Player* nextPlayer )
{
  // ���̃v���C���[�Ɏ�D��񎦂��Ă��炤
  BackHand* nextPlayersHand = static_cast<OldMaidPlayer*>( nextPlayer )->showHand() ;

  // ����̎�D����J�[�h���ꖇ����
  int numberOfHands = nextPlayersHand->getNumberOfCards() ;
  const Card* pickedCard = nextPlayersHand->pickCard( rand() % numberOfHands ) ;

  // ���������ʂ�\��
  std::cout << *this << "�F"
            << *nextPlayer << "���񂩂� " << *pickedCard << " �������܂���\n" ;

  // �������J�[�h�������̎�D�ɉ�����
  myHand_->addCard( pickedCard ) ;

  // �e�[�u���ɏo����J�[�h�̑g�ݍ��킹�����邩�T��
  Rule::CardList_t sameCards = rule_->findCandidate( myHand_, table_ ) ;

  // �����J�[�h�̑g�ݍ��킹�����݂����ꍇ
  if ( sameCards.size() > 0 )
  {
    std::cout << *this << "�F" ;
    table_->putCard( sameCards ) ;

    // ��D���[���ɂȂ������ǂ������ׂ�
    if ( myHand_->getNumberOfCards() == 0 )
    {
      // �i�s���ɏオ���錾����
      master_->declareWin( this ) ;
    }
  }

  // ���݂̎�D��\��
  std::cout << *this << "�F�c��̎�D�� " << *myHand_ << "�ł�\n" ;
}


BackHand* OldMaidPlayer::showHand()
{
  // �������̎��_�Ŏ�D���c��1���Ȃ�Ώオ��ƂȂ�̂Ő錾����
  if ( myHand_->getNumberOfCards() == 1 )
  {
    master_->declareWin( this ) ;
  }

  // ������O�ɃV���b�t������
  myHand_->shuffle() ;

  // ����Ɏ�D�𗠂��猩���邽�߁ABackHand��Ԃ�
  return backHand_ ;
}

} // oldmaid
