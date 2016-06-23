#include "Travel.h"
#include "Battle.h"
#include "Fate.h"
#include "City.h"
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
    ask.say(subject.getName() + "! You are about to set off for travel!");

    int user_choice=ask.askForInt(
                      "Where do you want to go?",
                      "You do not like sticking to rules, huh?",
                      1,3,
                      "Type 1 to set off to dangerous areas\n2 to travel by safe roads\n3 to direct your steps towards towering city, which shows up on the horizon:"
                      );
    ask.endSection();

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
    else if (getChoice()==3)
    {
        City* city_after_travel=new City();
        return city_after_travel;
    }
}
