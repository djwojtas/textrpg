#ifndef FATE_H
#define FATE_H

#include "GameStep.h"

class Fate:public GameStep
{
    int good_or_bad_luck; //0 -> bad luck ; 1 -> good luck
public:
    Fate();
    void play(Heroe& subject);
    GameStep* getNext();

    //Getters
    int getGoodOrBadLuck();

    //Setters
    void setGoodOrBadLuck(int s);

};

#endif
