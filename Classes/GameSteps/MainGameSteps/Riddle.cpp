#include "Riddle.h"

#include "Battle.h"
#include "../../Bases/RiddleBase.h"
#include "Fate.h"
#include "Travel.h"
#include "../../API/WriteOut.h"
#include "../../API/AskPlayer.h"

#include <cstdlib>
#include <ctime>

#include <algorithm>

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
    ask.narrate("-----RIDDLE!-----");
    ask.say(getRiddleText());
    string user_answer = ask.askForString("Type in your answer: ", "Excuse me, i did not hear you? Could you repeat?");

    transform(user_answer.begin(), user_answer.end(), user_answer.begin(), ::tolower);

    if(user_answer==correct_answer)
    {
        ask.say("Correct! In reward, you receive one rune!");
        int current_rune_count=subject.getRuneCount();
        subject.setRuneCount(current_rune_count+1);

        int index_to_pop;
        for(index_to_pop=0; index_to_pop<BaseOfRiddles.getSize(); index_to_pop++)
        {
            if((BaseOfRiddles.getRiddle(index_to_pop)).getCorrectAnswer()==getCorrectAnswer())
                break;
        }
        BaseOfRiddles.popRiddle(index_to_pop);
    } else {
        ask.say("Incorrect! Maybe next time you will be successful...");
    }

    ask.endSection();
}

GameStep* Riddle::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
