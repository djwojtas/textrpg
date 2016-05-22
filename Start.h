#ifndef START_H
#define START_H

#include "GameStep.h"

class Start:public GameStep
{
public:
    void play(Heroe& subject);
    GameStep* getNext();
};

#endif
