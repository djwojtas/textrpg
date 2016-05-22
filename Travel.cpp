#include "Travel.h"
#include "Battle.h"

using namespace std;

void Travel::setChoice(int c)
{
    choice=c;
}

int Travel::getChoice() const
{
    return choice;
}

void Travel::play(Heroe& subject)
{
    cout<<endl;
    cout<<"-----TRAVEL!-----"<<endl<<endl;


    int user_choice=0;
    while(((user_choice!=1)&&(user_choice!=2))||(cin.fail()))
    {
        cout<<"Type 1 /to set off to dangerous areas/ or 2 /to travel by safe roads/ :";
        cin>>user_choice;
    }

    this->setChoice(user_choice);
}

GameStep* Travel::getNext()
{
    if(getChoice()==1)
    {
        Battle* battle_after_travel = new Battle;
        return battle_after_travel;
    }
}
