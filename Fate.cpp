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
    int computer_number = rand()%101;
    int success=0;
    int counter=0;

    //-----GUESSING GAME------//
    ask.narrate("Odd stranger tackles you on the road.");
    ask.say("Hello wanderer, let's play the Guessing Game!\nYou have 7 tries.");

    do
    {
        int user_number = ask.askForInt("Tell me number from 0 to 100.", "Do you can even count to 100?", 0, 100);
        if(user_number>computer_number)
        {
            ask.say("That is too big");
        }
        else if(user_number<computer_number)
        {
            ask.say("That is too small");
        }
        else
        {
            success = 1;
            break;
        }
        counter++;
    } while (counter!=6);
    //-----END OF GUESSING GAME------//

    setGoodOrBadLuck(success);

    if(good_or_bad_luck==1) //Szczescie
    {
        ask.say("You have won traveler! You're good!");
        int drawn_number=rand()%5; //0 to 4;

        if(drawn_number!=0) /*80% na zdobycie artefaktu*/
        {
            int index_of_artefact=( rand() % BaseOfArtefacts.getSize() );
            Artefact drawn_artefact=BaseOfArtefacts.getArtefact(index_of_artefact);
            subject.addArtefact(drawn_artefact);
            ask.say("I will give you this: ");
            drawn_artefact.printArtefact();
            write<<"\n\n";
            BaseOfArtefacts.popArtefact(index_of_artefact);
        }
        else
        {
            ask.say("Unfortunately, right now i do not have any Artefact for you...\n\n");
        }
    }
    else //Pech
    {
        /*Utrata artefaktow lub zachowanie artefaktow*/
        ask.say("Bad guessing! You have lost!");

        int drawn_number=rand()%3; //0 or 1;

        if(drawn_number==0) /*1/3 szansy na utratę artefaktu*/
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
                ask.say("I regret to say it, but i must take you this artefact!: ");
                BaseOfArtefacts.getArtefact(BaseOfArtefacts.getSize()-1).printArtefact();
                write<<"\n\n";
            }
        }
        else
        {
            ask.say("Umm, i do not feel quite mighty today. I will not take you any Artefact. Now go away!\n\n");
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
