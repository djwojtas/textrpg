#include "City.h"
#include "Suburbs.h"
#include "../../API/AskPlayer.h"
#include "../../API/WriteOut.h"

using namespace std;

void Suburbs::setChoice(int choice_)
{
    choice=choice_;
}

int Suburbs::getChoice() const
{
    return choice;
}

void Suburbs::play(Heroe& subject)
{
    //TBD
    ask.say("(#SUBURBS) You are standing on huge pavement tiles...");
    int user_choice=ask.askForInt("","Do not joke traveler!", 1, 2, "Type in 1 to go to Traders's Office\n2 to go to somewhere else.");

    int next_step=1;

    if(user_choice==1)
    {
        next_step = visitTrader(subject);
    }
    else if(user_choice==2)
    {
        next_step = 2;
    }

    setChoice(next_step);
}

GameStep* Suburbs::getNext()
{
    //TBD
    if(getChoice()==1)
    {
        Suburbs* stay_at_suburbs=new Suburbs();
        return stay_at_suburbs;
    }
    else if(getChoice()==2)
    {
        City* city_after_suburbs=new City();
        return city_after_suburbs;
   }
}

int visitTrader(Heroe& subject)
{
    ask.say("The little man of middle age with a magnificent mustache greets you.");

    ask.say("\"You will not find any interesting here, i guess by your appearance.\"\n- The Trader says stroking his mustache.");

    //TBD
    //Procedura kupowania

    int user_choice=ask.askForInt("You leave bright trader's office and find yourself on the Suburbs again.","Do not joke traveler!", 1, 2, "Type in 1 to stay at the Suburbs or 2 to go somewhere else");
    return user_choice;
}
