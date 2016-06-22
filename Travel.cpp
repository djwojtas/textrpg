#include "Travel.h"
#include "Battle.h"
#include "Fate.h"
#include "AskPlayer.h"
#include "WriteOut.h"

using namespace std;

void Travel::setChoice(int choice_)
{
    choice=choice_;
}

int Travel::getChoice() const
{
    return choice;
}

void Travel::play(Heroe& subject)
{
    write<<"\n\n"<<subject.getName()<<"!"<<" You are about to set off for travel!\n\n";

    int user_choice=ask.askForInt(
                      "Type 1 /to set off to dangerous areas/ or 2 /to travel by safe roads/: ",
                      "You do not like sticking to rules, huh?",
                      1,2);

    this->setChoice(user_choice);
}

GameStep* Travel::getNext()
{
    if(getChoice()==1)
    {
        Battle* battle_after_travel = new Battle;
        return battle_after_travel;
    }
    else if (getChoice()==2)
    {
        Fate* fate_after_travel=new Fate();
        return fate_after_travel;
    }
}
