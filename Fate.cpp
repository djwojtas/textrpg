#include "Fate.h"
#include "Travel.h"
#include "ArtefactBase.h"
#include "WriteOut.h"
#include "AskPlayer.h"


#include <algorithm>
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

    int success=0;

    int game_choice=rand()%2;

    //-----GUESSING GAME------//
    if(game_choice==0)
    {
        srand( time( NULL ) );
        int computer_number = rand()%101;
        int counter=0;

        ask.narrate("Odd stranger tackles you on the road.");
        ask.say("Hello wanderer, let's play the Guessing Game!\nYou have 6 tries.");

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
        }
        while (counter!=5);
    }
    //-----END OF GUESSING GAME------//
    //-----ROCK PAPER SCISSORS------//
    else if(game_choice==1)
    {
        ask.narrate("Odd stranger tackles you on the road.");
        ask.say("Hello wanderer, let's play the ROCK PAPER SCISSORS Game!");

        for(;;)
        {
            string user_choice;
            ask.narrate("Type in your choice (Rock, Paper, Scissors): ");
            for(;;)
            {
                user_choice = ask.askForString("", "");
                transform(user_choice.begin(), user_choice.end(), user_choice.begin(), ::tolower);
                if((user_choice=="rock")||(user_choice=="paper")||(user_choice=="scissors")) { break; }
                else { ask.say("What the hell are u doin' with this hands boi!?"); ask.narrate("Try again"); }
            }

            int user_number;

            if(user_choice=="rock")
            {
                user_number=0;
            }
            else if(user_choice=="paper")
            {
                user_number=1;
            }
            else if(user_choice=="scissors")
            {
                user_number=2;
            }

            int computer_number=rand()%3;

            if(user_number==computer_number)
            {
                if(user_number==0) { ask.narrate("You present your hand. Unfortunately, odd stranger also chose ROCK.\nYou play again."); continue; }
                else if(user_number==1) { ask.narrate("You present your hand. Unfortunately, odd stranger also chose PAPER.\nYou play again."); continue; }
                else if(user_number==2) { ask.narrate("You present your hand. Unfortunately, odd stranger also chose SCISSORS.\nYou play again."); continue; }
            }
            else
            {
                if(user_number==0)
                {
                    if(computer_number==1){ ask.narrate("You present your hand. Unfortunately, odd stranger chose PAPER :'("); break; }
                    if(computer_number==2){ ask.narrate("You present your hand. Odd stranger chose SCISSORS.\n\"What a looser\" - you think..."); success=1; break; }
                }
                else if (user_number==1)
                {
                    if(computer_number==0){ ask.narrate("You present your hand. Odd stranger chose ROCK.\n\"What a looser\" - you say to yourself..."); success=1; break; }
                    if(computer_number==2){ ask.narrate("You present your hand. Unfortunately, odd stranger chose SCISSORS :'("); break; }
                }
                else
                {
                    if(computer_number==0){ ask.narrate("You present your hand. Unfortunately, odd stranger chose ROCK :'(");  break; }
                    if(computer_number==1){ ask.narrate("You present your hand. Odd stranger chose PAPER.\n\"What a looser\" - you say in mind..."); success=1; break; }
                }
            }
        }
    }
    //-----END OF ROCK PAPER SCISSORS------//

    setGoodOrBadLuck(success);

    if(good_or_bad_luck==1) //Szczescie
    {
        ask.say("You have won traveler! You're good!");
        int drawn_number=rand()%101; //0 to 100;

        if(drawn_number<=60) /*60% na zdobycie artefaktu*/
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
        ask.say("You have lost traveler!");

        int drawn_number=rand()%101; //0 to 100;

        if(drawn_number<=35) /*35% szansy na utratę artefaktu*/
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
