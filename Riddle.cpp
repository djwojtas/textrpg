#include "Riddle.h"

#include "Battle.h"
#include "Fate.h"
#include "Travel.h"
#include "WriteOut.h"
#include "AskPlayer.h"

#include <cstdlib>
#include <ctime>

using namespace std;

Riddle::Riddle(string riddle_text_, string correct_answer_)
{
    riddle_text=riddle_text_;
    correct_answer=correct_answer_;
}

string Riddle::getRiddleText() const
{
    return riddle_text;
}

string Riddle::getCorrectAnswer() const
{
    return correct_answer;
}

void Riddle::play(Heroe& subject)
{
    write<<"-----RIDDLE!-----\n\n";

    write<<getRiddleText()<<"\n";

    string user_answer = ask.askForString("Type in your answer: ", "Excuse me, i did not hear you? Could you repeat?");

    if(user_answer==correct_answer)
    {
        write<<"Correct! In reward, you receive one rune!\n\n";
        int current_rune_count=subject.getRuneCount();
        subject.setRuneCount(current_rune_count+1);
    } else {
        write<<"Incorrect! Maybe next time you will be successful... \n\n";
    }
}

GameStep* Riddle::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
