#include "Battle.h"
#include "Monster.h"
#include "RiddleBase.h"
#include "MonsterBase.h"
#include "WriteOut.h"

#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include  "AskPlayer.h"

using namespace std;

void Battle::play(Heroe& subject)
{
    Monster random_monster = BaseOfMonsters.getMonster( rand() % BaseOfMonsters.getSize() );

    ask.say(random_monster.getName() + " attacked you!");

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = random_monster.getStrength();
    int monster_agility_total = random_monster.getAgility();
    int monster_hp_total = random_monster.getHP();

    bool flag_win = true;

    while(true)
    {
        ask.printFight(subject, random_monster);

        int heroe_dmg = ceil((double)(heroe_strength_total + ceil((rand()%heroe_agility_total + (heroe_agility_total/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
        Sleep(500);
        ask.narrate(subject.getName() + " caused " + to_string(heroe_dmg) + " damage to " + random_monster.getName() + "!");
        if(random_monster.getDMG(heroe_dmg)) break;
        flag_win = false;

        int monster_dmg = ceil((double)(monster_strength_total + ceil((rand()%monster_agility_total + (monster_agility_total/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
        Sleep(500);
        ask.narrate(random_monster.getName() + " caused " + to_string(monster_dmg) + " damage to " + subject.getName() + "!");
        if(subject.getDMG(monster_dmg)) break;
        flag_win = true;
    }

    if(flag_win)
    {
        ask.say("You Defeated " + random_monster.getName() + "\n\n");
    }
    else
    {
        ask.endChapter();
        ask.say("You Died! RIP[*]");
        exit(0);
    }
}

void Battle::play(Heroe& subject, Monster opponent)
{
    ask.say(opponent.getName() + " attacked you!");

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = opponent.getStrength();
    int monster_agility_total = opponent.getAgility();
    int monster_hp_total = opponent.getHP();

    bool flag_win = true;

    while(true)
    {
        ask.printFight(subject, opponent);

        int heroe_dmg = ceil((double)(heroe_strength_total + ceil((rand()%heroe_agility_total + (heroe_agility_total/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
        Sleep(500);
        ask.narrate(subject.getName() + " caused " + to_string(heroe_dmg) + " damage to " + opponent.getName() + "!");
        if(opponent.getDMG(heroe_dmg)) break;
        flag_win = false;

        int monster_dmg = ceil((double)(monster_strength_total + ceil((rand()%monster_agility_total + (monster_agility_total/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
        Sleep(500);
        ask.narrate(opponent.getName() + " caused " + to_string(monster_dmg) + " damage to " + subject.getName() + "!");
        if(subject.getDMG(monster_dmg)) break;
        flag_win = true;
    }

    if(flag_win)
    {
        ask.endChapter();
        ask.say("You Died! RIP[*]");
        exit(0);
    }
    else
    {
        ask.say("You Defeated " + opponent.getName() + "\n\n");
    }
}

GameStep* Battle::getNext()
{
    int index_of_riddle=( rand() % BaseOfRiddles.getSize() );
    Riddle drawn_riddle=BaseOfRiddles.getRiddle(index_of_riddle);
    Riddle* riddle_after_battle=new Riddle(drawn_riddle);
    return riddle_after_battle;
}
