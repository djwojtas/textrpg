#include "Fate.h"
#include "Travel.h"
#include "ArtefactBase.h"
#include "WriteOut.h"

#include <ctime>
#include <cstdlib>

using namespace std;

Fate::Fate()
{
    good_or_bad_luck=0;
}

void Fate::play(Heroe& subject)
{
    srand( time( NULL ) );
    setGoodOrBadLuck(rand()%2);

    if(good_or_bad_luck==1) //Szczescie
    {
        write<<"Good fortune!\n\n";
        int index_of_artefact=( rand() % BaseOfArtefacts.getSize() );
        Artefact drawn_artefact=BaseOfArtefacts.getArtefact(index_of_artefact);
        subject.addArtefact(drawn_artefact);
        write<<"you've received: ";
        drawn_artefact.printArtefact();
        write<<"\n\n";
    }
    else //Pech
    {
        /*Utrata artefaktow lub zachowanie artefaktow*/
        write<<"Bad fortune!\n\n";
        int drawn_number=rand()%5; //0 to 4;

        if(drawn_number==0) /*20% na utratę artefaktów*/
        {
            subject.loseArtefacts();
            write<<"Unfortunately, you've lost every artefact you had!\n\n";
        } else {
            write<<"Fortunately, you've saved your artefacts!\n\n";
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
