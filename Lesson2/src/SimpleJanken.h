#ifndef SIMPLEJANKEN_H
#define SIMPLEJANKEN_H

#include "Executable.h"

/**
 * �I�u�W�F�N�g�w�����g�p���Ȃ��W�����P���v���O����
 */
class SimpleJanken : public Executable
{
public:
  // �W�����P���̎��\���萔
  enum HandType {
    STONE    = 0, // �O�[
    SCISSORS = 1, // �`���L
    PAPER    = 2  // �p�[
  } ;

public:
  // �G���g���|�C���g
  void main( int argc, char* argv[] ) ;
} ;

#endif // SIMPLEJANKEN_H