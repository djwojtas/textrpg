#ifndef GAMESTEP_H
#define GAMESTEP_H

#include "Heroe.h"

class GameStep
{
public:
  virtual void play(Heroe& subject) = 0;
  virtual GameStep* getNext() = 0;
};

#endif
