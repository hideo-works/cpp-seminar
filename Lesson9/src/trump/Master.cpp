#include "Master.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>

namespace trump {

void Master::prepareGame( Hand* cards ) const
{
  std::cout << "�y�J�[�h��z��܂��z\n" ;
  
  // �g�����v���V���b�t������
  cards->shuffle() ;
  
  // �g�����v�̖������擾����
  int numberOfCards = cards->getNumberOfCards() ;
  
  // �v���C���[�̐l�����擾����
  int numberOfPlayers = players_.size() ;
  
  for ( int index = 0 ; index < numberOfCards ; ++index )
  {
    // �J�[�h����ꖇ����
    const Card* card = cards->pickCard( 0 ) ;
    
    // �e�v���C���[�ɏ��ԂɃJ�[�h��z��
    Player* player = players_.at( index % numberOfPlayers ) ;
    player->receiveCard( card ) ;
  }
}


void Master::startGame()
{
  std::cout << "\n�y�Q�[�����J�n���܂��z\n" ;
  
  // �v���C���[�̐l�����擾����
  for ( int count = 0 ; players_.size() > 1 ; ++count )
  {
    int playerIndex = count % players_.size() ; 
    int nextPlayerIndex = (count + 1) % players_.size() ;
    
    // �w������v���C���[�̎擾
    Player* player = players_.at( playerIndex ) ;
    
    // ���̃v���C���[�̎擾
    Player* nextPlayer = players_.at( nextPlayerIndex ) ;
                
    // �v���C���[���w������
    std::cout << "\n" << *player << "����̔Ԃł��B\n" ;
    player->play( nextPlayer ) ;
  }
  
  // �v���C���[���オ���Ďc��1���ɂȂ�ƃ��[�v�𔲂���
  std::cout << "�y�Q�[�����I�����܂����z\n" ;
}


void Master::declareWin( const Player* winner )
{
  // �オ�����v���C���[
  std::cout << "  " << *winner << "���񂪏オ��܂����I\n" ;
  
  // �オ�����v���C���[�����X�g����͂���
  this->deregisterPlayer( winner ) ;
}


void Master::registerPlayer( Player* player )
{
  // ���X�g�ɎQ���҂�ǉ�����
  players_.push_back( player ) ;
}


void Master::deregisterPlayer( const Player* player )
{
  // ���X�g����Q���҂��폜����
  PlayerArray_t::iterator it  = players_.begin() ;
  PlayerArray_t::iterator end = players_.end() ;
  for ( ; it != end ; ++it )
  {
    if ( *it == player ) {
      players_.erase( it ) ;
      break ;
    }
  }

  // �c��v���C���[���P�l�ɂȂ������͔s�҂�\������
  if ( players_.size() == 1 )
  {
    Player* loser = players_.at( 0 ) ;
    std::cout << "  " << *loser << "����̕����ł��I\n" ;
  }
}

} // trump
