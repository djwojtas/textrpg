#include "WriteOut.h"
#include "AskPlayer.h"
#include "../Characters/Heroe.h"
#include "ConsoleColor.h"
#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

void AskPlayer::setState(int state_)
{
    state=state_;
}

void AskPlayer::endSection()
{
  cout<<"\n\n.";
  Sleep(1000);
  cout<<"\n";
}

void AskPlayer::endChapter()
{
  cout<<"\n\n.";
  Sleep(500);
  cout<<"\n.";
  Sleep(1000);
  cout<<"\n.";
  Sleep(1000);
  cout<<"\n";
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
    color.setColor(6);
    if(!state) cout<<"\n";
    write<<"\n// "<<message<<" //";
    state=1;
    color.setColor(7);
}

int AskPlayer::askForInt(string message, string fail_message, int minimum, int maximum, string narrate_message)
{
    int answer;

    while(1)
    {
        say(message);
        if(narrate_message.size()) narrate(narrate_message);
        say("\n\n\\> ");
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

double AskPlayer::askForDouble(string message, string fail_message, double minimum, double maximum, string narrate_message)
{
    double answer;

    while(1)
    {
        say(message);
        if(narrate_message.size()) narrate(narrate_message);
        say("\n\n\\> ");
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

string AskPlayer::askForString(string message, string fail_message, string narrate_message)
{
    string answer;

    while(1)
    {
        say(message);
        if(narrate_message.size()) narrate(narrate_message);
        say("\n\n\\> ");
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

void AskPlayer::printFight(Heroe& subject, Monster& monster_to_print, int subject_agility_boost, int monster_agility_boost, int subject_def_boost, int monster_def_boost)
{
  cout<<"\n\n     "<<subject.getName();
  for(int i=0; i<(35-(subject.getName().size())); ++i) cout<<" ";
  cout<<monster_to_print.getName();

  cout<<"\n\n     STR: "<<subject.getFullStrength();
  for(int i=0; i<(27-((subject.getFullStrength()/10)+1)); ++i) cout<<" ";
  cout<<"STR: "<<monster_to_print.getStrength();

  cout<<"\n     AGI: "<<subject.getFullAgility()<<" + "<<subject_agility_boost;
  for(int i=0; i<(24-(((subject.getFullStrength())/10)+1)-(((subject_agility_boost)/10)+1)); ++i) cout<<" ";
  cout<<"AGI: "<<monster_to_print.getAgility()<<" + "<<monster_agility_boost;

  cout<<"\n     HP: "<<subject.getFullHP();
  for(int i=0; i<(28-((subject.getFullHP()/10)+1)); ++i) cout<<" ";
  cout<<"HP: "<<monster_to_print.getHP();

  cout<<"\n     DEF: "<<subject.getFullDef()<<" + "<<subject_def_boost;;
  for(int i=0; i<(24-((subject.getFullDef()/10)+1)-(((subject_def_boost)/10)+1)); ++i) cout<<" ";
  cout<<"DEF: "<<monster_to_print.getDef()<<" + "<<monster_def_boost;

  cout<<"\n\n";
}

/** \brief Only one existing AskPlayer object, used to interact with player */
AskPlayer ask;
