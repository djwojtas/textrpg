#ifndef TRAVEL_H
#define TRAVEL_H

#include "GameStep.h"

class Travel:public GameStep
{
    int choice;
public:
    void setChoice(int c);
    int getChoice() const;
    void play(Heroe& subject);
    GameStep* getNext();

};

#endif
