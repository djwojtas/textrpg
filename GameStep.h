#ifndef GAMESTEP_H
#define GAMESTEP_H

class GameStep
{
public:
  virtual void play(Heroe&) = 0;
  virtual GameStep* getNext() = 0;
};

#endif
