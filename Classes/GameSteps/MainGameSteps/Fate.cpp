#include "Fate.h"
#include "Travel.h"
#include "../../Bases/ArtefactBase.h"
#include "FateAuxiliary/DiceSerie.h"
#include "../../API/WriteOut.h"
#include "../../API/AskPlayer.h"


#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

Fate::Fate()
{
    fail_or_victory=0;
}

void Fate::play(Heroe& subject)
{
    if(BaseOfArtefacts.getSize()==0)
    {
        ask.say("You have every possible Artefact in your inventory, you greedy bastard!\n\n");
        return;
    }

    int success = 0;
    int game_number = rand()%3;

    if (game_number==0){ success = playRockPaperScissors(subject); }
    else if (game_number==1){ success = playGuessingGame(subject); }
    else if (game_number==2){ success = playDiceGame(subject); }

    setFailOrVictory(success);

    if(getFailOrVictory())
        playVictory(subject);
    else
        playFail(subject);
}

int Fate::getFailOrVictory()
{
    return fail_or_victory;
}

void Fate::setFailOrVictory(int fail_or_victory_)
{
    fail_or_victory=fail_or_victory_;
}

GameStep* Fate::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}

int playGuessingGame(Heroe& subject)
{
    int success=0;
    srand( time( NULL ) );
    int counter=0;

    int computer_number = rand()%101;

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
    }
    while (counter!=6);

    return success;
}

int playRockPaperScissors(Heroe& subject)
{
    srand( time( NULL ) );
    int success=0;

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
            if((user_choice=="rock")||(user_choice=="paper")||(user_choice=="scissors"))
            {
                break;
            }
            else
            {
                ask.say("What the hell are u doin' with this hands boi!?");
                ask.narrate("Try again");
            }
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
            if(user_number==0)
            {
                ask.narrate("You present your hand. Unfortunately, odd stranger also chose ROCK.\nYou play again.");
                continue;
            }
            else if(user_number==1)
            {
                ask.narrate("You present your hand. Unfortunately, odd stranger also chose PAPER.\nYou play again.");
                continue;
            }
            else if(user_number==2)
            {
                ask.narrate("You present your hand. Unfortunately, odd stranger also chose SCISSORS.\nYou play again.");
                continue;
            }
        }
        else
        {
            if(user_number==0)
            {
                if(computer_number==1)
                {
                    ask.narrate("You present your hand. Unfortunately, odd stranger chose PAPER :'(");
                    break;
                }
                if(computer_number==2)
                {
                    ask.narrate("You present your hand. Odd stranger chose SCISSORS.\n\"What a looser\" - you think...");
                    success=1;
                    break;
                }
            }
            else if (user_number==1)
            {
                if(computer_number==0)
                {
                    ask.narrate("You present your hand. Odd stranger chose ROCK.\n\"What a looser\" - you say to yourself...");
                    success=1;
                    break;
                }
                if(computer_number==2)
                {
                    ask.narrate("You present your hand. Unfortunately, odd stranger chose SCISSORS :'(");
                    break;
                }
            }
            else
            {
                if(computer_number==0)
                {
                    ask.narrate("You present your hand. Unfortunately, odd stranger chose ROCK :'(");
                    break;
                }
                if(computer_number==1)
                {
                    ask.narrate("You present your hand. Odd stranger chose PAPER.\n\"What a looser\" - you say in mind...");
                    success=1;
                    break;
                }
            }
        }
    }

    return success;
}

int playDiceGame(Heroe& subject)
{
    ask.narrate("Odd stranger tackles you on the road.");
    ask.say("Hello wanderer, let's play the DICE POKER Game!");

    DiceSerie user_serie;
    DiceSerie computer_serie;

    ask.narrate("You roll your five die.");
    user_serie.roll();

    ask.narrate("This is the die combination which you managed to roll: ");
    cout<<endl;
    user_serie.printDie();

    ask.narrate("Odd stranger rolls his five die.");
    computer_serie.roll();

    ask.narrate("This is his outcome: ");
    cout<<endl;
    computer_serie.printDie();
    cout<<endl;

    user_serie.rollChosenUserInput();

    ask.narrate("So this is your final combination: ");
    cout<<endl;
    user_serie.printDie();

    ask.narrate("Odd stranger thinks which die he should re-roll...");
    //Sleep(200);
    ask.narrate("Finally he decides and rolls.");
    computer_serie.computerReRoll();
    ask.narrate("This is what he achieved: ");
    computer_serie.printDie();

    user_serie.countAmountsOfPips();
    user_serie.refreshValue();

    computer_serie.countAmountsOfPips();
    computer_serie.refreshValue();

    return ( user_serie > computer_serie );
}

void playVictory(Heroe& subject)
{
    ask.say("You have won traveler! You're good!");
    int drawn_number=rand()%101;

    if(drawn_number<=70) /*70% chance for winning some Artefacts*/
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

void playFail(Heroe& subject)
{
    ask.say("You have lost traveler!");

    int drawn_number=rand()%101;

    if(drawn_number<=35) /*35% chance for losing some Artefacts*/
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
