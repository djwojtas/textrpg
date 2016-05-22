#ifndef RIDDLE_H
#define RIDDLE_H

#include "GameStep.h"

class Riddle:public GameStep
{
    string riddle_text;
    string correct_answer;
public:
    Riddle(string rt, string ca);
    string getRiddleText() const;
    string getCorrectAnswer() const;
    void play(Heroe& subject);
    GameStep* getNext();
};

#endif
