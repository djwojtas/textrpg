#include "City.h"
#include "MainSquare.h"
#include "ArtefactBase.h"
#include "AskPlayer.h"
#include "WriteOut.h"

using namespace std;

void MainSquare::setChoice(int choice_)
{
    choice=choice_;
}

int MainSquare::getChoice() const
{
    return choice;
}

void MainSquare::play(Heroe& subject)
{
    //TBD
    ask.say("You are standing on the stones of The Main Square...");
    int user_choice=ask.askForInt("","Do not joke traveler!", 1, 2, "Type in 1 to go to Healer's Workshop\n2 to visit Blacksmith\n3 to go back to suburbs");

    int next_step=1;

    if(user_choice==1)
    {
        next_step = visitHealer(subject);
    }
    else if(user_choice==2)
    {
        next_step = visitBlacksmith(subject);
    }
    else if(user_choice==3)
    {
        next_step=2;
    }

    setChoice(next_step);
}

GameStep* MainSquare::getNext()
{
    //TBD
    if(getChoice()==1)
    {
        MainSquare* stay_at_main_square=new MainSquare();
        return stay_at_main_square;
    }
    else if(getChoice()==2)
    {
        City* city_after_main_square=new City();
        return city_after_main_square;
    }
}

int visitHealer(Heroe& subject)
{
    ask.say("Old gray-haired man in a snow-white gown greets you and smiles...");
    if(subject.getHP()<subject.getMaxHP())
    {
        ask.say("\"You seem to be somewhat in bad shape, young traveler! Let me get you back on your feet again...\"");
        ask.narrate("You regain your health points!");
        //TBD
        //cos w stylu subject.heal();
    }
    else if(subject.getHP()==subject.getMaxHP())
    {
        ask.say("\"What a mighty young man, you are!\nI am afraid you will not find anything interesting here...\" - he says with his velvet voice.");
    }
    int user_choice=ask.askForInt("You set your foots upon the Main Square again","Do not joke traveler!", 1, 2, "Type in 1 to stay at the Main Square or 2 to go back to suburbs");
    return user_choice;
}

int visitBlacksmith(Heroe& subject)
{
    ask.say("Enormously muscular man with magnificent black beard greets you.");

    if((subject.getAmountOfArtefacts()>0)&&(subject.getAmountOfArtefacts()<BaseOfArtefacts.getSize()))
    {
        ask.say("\"I see, that you have collected a few powerful Artefacts here.\"\n- The Blacksmith says stroking his beard.");
    }
    else if (subject.getAmountOfArtefacts()>=BaseOfArtefacts.getSize())
    {
        ask.say("\"You must be either very rich or very brave.\"\n- The Blacksmith says looking with respect at Artefacts in your equipment.");
    }

    //TBD
    //Procedura kupowania

    int user_choice=ask.askForInt("You leave dark forge and find yourself on the Main Square again.","Do not joke traveler!", 1, 2, "Type in 1 to stay at the Main Square or 2 to go back to suburbs");
    return user_choice;
}
