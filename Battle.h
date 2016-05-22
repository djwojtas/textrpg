#ifndef BATTLE_H
#define BATTLE_H

#include "GameStep.h"
#include "Monster.h"

class Battle:public GameStep
{
public:
    void play(Heroe& subject); /* Battle with random monster*/
    void play(Heroe& subject, Monster& opponent); /* Battle with defined monster*/
    GameStep* getNext();
};

#endif
