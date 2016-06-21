#include "Fate.h"
#include "ArtefactBase.h"

#include <ctime>
#include <cstdlib>

extern ArtefactBase BaseOfArtefacts;

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
        cout<<"Good fortune!"<<endl;
        int index_of_artefact=( rand() % BaseOfArtefacts.getSize() );
        Artefact drawn_artefact=BaseOfArtefacts.getArtefact(index_of_artefact);

        subject.addArtefact(drawn_artefact);
        cout<<"you've received: ";
        drawn_artefact.printArtefact();
    }
    else //Pech
    {
        /*Utrata artefaktow lub zachowanie artefaktow*/
        cout<<"Bad fortune!"<<endl;
        int drawn_number=rand()%5; //0 to 4;

        if(drawn_number==0) /*20% na utratę artefaktów*/
        {
            subject.loseArtefacts();
            cout<<"Unfortunately, you've lost every artefact you had!"<<endl;
        } else {
            cout<<"Fortunately, you've saved your artefacts!"<<endl;
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
    /*Next step*/
}
