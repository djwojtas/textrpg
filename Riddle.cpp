#include "Riddle.h"

#include "Battle.h"
#include "Fate.h"
#include "Travel.h"

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
    cout<<endl;
    cout<<"-----RIDDLE!-----"<<endl<<endl;

    cout<<getRiddleText()<<endl<<endl;

    cout<<"Type in your answer: ";

    string user_answer;

    cin>>user_answer;

    if(user_answer==correct_answer)
    {
        cout<<"Correct! In reward, you receive rune!"<<endl<<endl;
        int current_rune_count=subject.getRuneCount();
        subject.setRuneCount(current_rune_count+1);
    } else {
        cout<<"Incorrect!"<<endl<<endl;
    }
}

GameStep* Riddle::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
