#include "WriteOut.h"
#include "AskPlayer.h"
#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

void AskPlayer::setState(int state_)
{
    state=state_;
}

void AskPlayer::playerSay(string message)
{
    if(state) cout<<"\n";
    write<<"\n\\> "<<message;
    state=0;
}

void AskPlayer::say(string message)
{
    if(!state) cout<<"\n";
    write<<"\n"<<message;
    state=1;
}

void AskPlayer::narrate(string message)
{
    if(!state) cout<<"\n";
    write<<"\n// "<<message<<" //";
    state=1;
}

int AskPlayer::askForInt(string message, string fail_message, int minimum, int maximum)
{
    int answer;

    while(1)
    {
        say(message + "\n\n\\> ");
        cin>>answer;
        state=0;
        if(!cin.fail() && (answer>=minimum) && (answer<=maximum)) break;
        say(fail_message);
        state=1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return answer;
}

double AskPlayer::askForDouble(string message, string fail_message, double minimum, double maximum)
{
    double answer;

    while(1)
    {
        say(message + "\n\n\\> ");
        cin>>answer;
        state=0;
        if(!cin.fail() && (answer>=minimum) && (answer<=maximum)) break;
        say(fail_message);
        state=1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return answer;
}

string AskPlayer::askForString(string message, string fail_message)
{
    string answer;

    while(1)
    {
        say(message + "\n\n\\> ");
        cin>>answer;
        state=0;
        if(!cin.fail()) break;
        say(fail_message);
        state=1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return answer;
}

/** \brief Only one existing AskPlayer object, used to interact with player */
AskPlayer ask;
