#include "Fate.h"
#include "Travel.h"
#include "ArtefactBase.h"
#include "WriteOut.h"
#include "AskPlayer.h"

#include <ctime>
#include <cstdlib>

using namespace std;

Fate::Fate()
{
    good_or_bad_luck=0;
}

void Fate::play(Heroe& subject)
{
    if(BaseOfArtefacts.getSize()==0)
    {
        ask.say("You have every possible Artefact in your inventory, you greedy bastard!\n\n");
        return;
    }

    srand( time( NULL ) );
    setGoodOrBadLuck(rand()%2);

    if(good_or_bad_luck==1) //Szczescie
    {
        ask.say("Good fortune!");
        int drawn_number=rand()%5; //0 to 4;

        if(drawn_number==0) /*20% na zdobycie artefaktu*/
        {
            int index_of_artefact=( rand() % BaseOfArtefacts.getSize() );
            Artefact drawn_artefact=BaseOfArtefacts.getArtefact(index_of_artefact);
            subject.addArtefact(drawn_artefact);
            ask.say("you've received: ");
            drawn_artefact.printArtefact();
            write<<"\n\n";
            BaseOfArtefacts.popArtefact(index_of_artefact);
        }
    }
    else //Pech
    {
        /*Utrata artefaktow lub zachowanie artefaktow*/
        ask.say("Bad fortune!");

        int drawn_number=rand()%5; //0 to 4;

        if(drawn_number==0) /*20% na utratę artefaktu*/
        {
            if(subject.getAmountOfArtefacts()==0)
            {
                ask.say("You would lose some Artefacts, but fortunately you have none of them! Lucky bastard!");
                write<<"\n\n";
                return;
            }
            else
            {
                int artefact_index = rand() % subject.getAmountOfArtefacts();
                BaseOfArtefacts.pushArtefact( subject.loseArtefact(artefact_index) );
                ask.say("Unfortunately, you've lost this artefact!: ");
                BaseOfArtefacts.getArtefact(BaseOfArtefacts.getSize()-1).printArtefact();
                write<<"\n\n";
            }
        }
        else
        {
            ask.say("Fortunately, you've saved your artefacts!");
        }
    }
}

int Fate::getGoodOrBadLuck()
{
    return good_or_bad_luck;
}

void Fate::setGoodOrBadLuck(int good_or_bad_luck_)
{
    good_or_bad_luck=good_or_bad_luck_;
}

GameStep* Fate::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
