#include "Start.h"
#include "Battle.h"
#include "Travel.h"
#include "Fate.h"
#include "AskPlayer.h"
#include <windows.h>
#include <string>

void Start::play(Heroe& subject)
{
    /*string name;
    int strength = -1, agility = -1, health = -1, points_to_spend = 16;
    bool repeat_flag;

    name=ask.askForString(
                      "Welcome, traveler. What is your name?",
                      "I don't think its your name."
                      );
    Sleep(300);
    ask.say("Tell me something about yourself, " + name);
    Sleep(350);
    ask.narrate("You have 16 point to spend on strength, agility and hp, choose wisely.");
    Sleep(500);
    strength=ask.askForInt(
                      "So, " + name + ", how strong are you?\n// 0-16 //",
                      "Stop kidding traveler. Tell the truth.",
                      0,points_to_spend);
    points_to_spend -= strength;
    Sleep(400);
    agility=ask.askForInt("And how agile are you?\n// 0-" + to_string(points_to_spend) + " //",
                          "Stop kidding traveler. Tell the truth.",
                          0,points_to_spend);
    points_to_spend -= agility;
    Sleep(500);
    if(points_to_spend<5) ask.say("U may be strong and agile, but you seem to be fragile..");
      else if(points_to_spend<10) ask.say("U seem to be very balanced in your skills.");
      else ask.say("Well, at least you seem very healthy");
    health = points_to_spend;
    Sleep(500);
    ask.narrate("You gain " + to_string(health) + " health points");
    Sleep(500);
    ask.playerSay("You are right. But i should be leaving.");
    ask.say("Wait! Drink this! This potion will make you stronger.");
    Sleep(200);
    ask.playerSay("Right...    .     .");
    Sleep(500);
    ++strength;
    ++agility;
    ++health;
    ask.narrate("Your stats increased by 1");
    Sleep(500);
    ask.playerSay("Wow, thank you. But now i must leave. Goodbye.");
    Sleep(350);
    ask.say("Good luck, " + name);
    ask.endSection();

    subject.setName(name);
    subject.setStrength(strength);
    subject.setAgility(agility);
    subject.setHP(health);
    subject.setMaxHP(health);*/
}

GameStep* Start::getNext()
{
    GameStep* to_return = new Travel();
    return to_return;
}
