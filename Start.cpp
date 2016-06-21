#include "Start.h"
#include "Battle.h"
#include "Travel.h"
#include "Fate.h"
#include <cstdlib>
#include <ctime>

void Start::play(Heroe& subject)
{
    cout<<"Hello /"<<subject.getName()<<"/ Let the adventure begin!"<<endl<<endl;

    srand( time( NULL ) );

    int drawn_strength =( rand() % 8 ) + 2; //from 2 to 9
    int drawn_agility =( rand() % 8 ) + 2;
    int drawn_hp =( rand() % 8 ) + 2;

    subject.setStrength(drawn_strength);
    subject.setAgility(drawn_agility);
    subject.setHP(drawn_hp);
}

GameStep* Start::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
