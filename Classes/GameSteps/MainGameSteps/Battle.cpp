#include "Battle.h"
#include "../../Characters/Monster.h"
#include "../../Bases/RiddleBase.h"
#include "../../Bases/MonsterBase.h"
#include "../../API/WriteOut.h"
#include  "../../API/AskPlayer.h"

#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <sstream>

using namespace std;

void Battle::play(Heroe& subject)
{
    Monster random_monster = BaseOfMonsters.getMonster( rand() % BaseOfMonsters.getSize() );

    play(subject, random_monster);
}

void Battle::play(Heroe& subject, Monster opponent)
{
    ask.say(opponent.getName() + " attacked you!");

    int heroe_strength_total = subject.getFullStrength();
    int heroe_agility_total = subject.getFullAgility();
    int heroe_hp_total = subject.getFullHP();

    int monster_strength_total = opponent.getStrength();
    int monster_agility_total = opponent.getAgility();
    int monster_hp_total = opponent.getHP();

    bool flag_win = true;

    int subject_agility_boost = 0;
    int monster_agility_boost = 0;

    while(true)
    {
        ask.printFight(subject, opponent, subject_agility_boost, monster_agility_boost);

        int choice=ask.askForInt("What should i do?",
                                 "I've got no time, give correct answer!",
                                 1, 3,
                                 "1 - Attack\n  DMG = STR and some AGI, CHANCE = AGI)\n"
                                 "2 - Defend\n  increases AGI by 3, you lose 1 in the end of turn\n"
                                 "3 - Go for critical strike\n  DMG = STR + HP, CHANCE uses AGI and HP, less hp is more DMG and bigger CHANCE"
                                 );

        if(choice == 1)
        {
          int heroe_dmg = ceil((double)(heroe_strength_total + ceil((rand()%(heroe_agility_total+subject_agility_boost) + ((heroe_agility_total+subject_agility_boost)/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
          Sleep(500);
          int chance = rand()%101;
          int chance_boost = subject.getAgility() + subject_agility_boost + 45 - opponent.getAgility() - monster_agility_boost + rand()%11;
          if(chance_boost>95) chance_boost=95;
          if(chance_boost<30) chance_boost=30;

          if(chance>chance_boost)
          {
            ask.narrate(subject.getName() + " missed " + opponent.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
          }
          else
          {
            ask.narrate(subject.getName() + " caused " + to_string(heroe_dmg) + " damage to " + opponent.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
            if(opponent.getDMG(heroe_dmg)) break;
          }
        }
        else if(choice == 2)
        {
          subject_agility_boost += 3;
          ask.narrate(subject.getName() + " defends and have now " + to_string(subject_agility_boost) + " more AGI!");
        }
        else
        {
          int heroe_dmg = ceil(((double)(double)heroe_strength_total*(((double)subject.getMaxHP())/((double)subject.getHP())))*((double)(rand()% 3 + 7)/5.0));
          Sleep(500);
          int chance = rand()%101;
          int chance_boost = (subject.getAgility()+subject_agility_boost)/4 + 10 + (25 * ((((double)subject.getMaxHP())/((double)subject.getHP())) - 1));
          if(chance_boost>50) chance_boost=50;

          if(chance>chance_boost)
          {
            ask.narrate(subject.getName() + " missed " + opponent.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
          }
          else
          {
            ask.narrate(subject.getName() + " caused " + to_string(heroe_dmg) + " critical damage to " + opponent.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
            if(opponent.getDMG(heroe_dmg)) break;
          }
        }

        flag_win = false;

        choice=rand()%11;

        if(choice < 6)
        {
          int monster_dmg = ceil((double)(monster_strength_total + ceil((rand()%(monster_agility_total+monster_agility_boost) + ((monster_agility_total+monster_agility_boost)/2))*0.25))*((double)(rand()% 3 + 7)/5.0));
          Sleep(500);
          int chance = rand()%101;
          int chance_boost = opponent.getAgility() + monster_agility_boost + 45 - subject.getAgility() - subject_agility_boost + rand()%11;
          if(chance_boost>95) chance_boost=95;
          if(chance_boost<5) chance_boost=5;

          if(chance>chance_boost)
          {
            ask.narrate(opponent.getName() + " missed " + subject.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
          }
          else
          {
            ask.narrate(opponent.getName() + " caused " + to_string(monster_dmg) + " damage to " + subject.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
            if(subject.getDMG(monster_dmg)) break;
          }
        }
        else if(choice < 10)
        {
          monster_agility_boost += 3;
          ask.narrate(opponent.getName() + " defends and have now " + to_string(monster_agility_boost) + " more AGI!");
        }
        else
        {
          int monster_dmg = ceil(((double)((double)monster_strength_total*(((double)opponent.getMaxHP())/((double)opponent.getHP()))))*((double)(rand()% 3 + 7)/5.0));
          Sleep(500);
          int chance = rand()%101;
          int chance_boost = (opponent.getAgility()+monster_agility_boost-subject.getAgility()-subject_agility_boost)/4 + 10 + (25 * (((double)opponent.getMaxHP())/((double)opponent.getHP()) - 1));
          if(chance_boost>50) chance_boost=50;
          if(chance_boost<10) chance_boost=10;

          if(chance>chance_boost)
          {
            ask.narrate(opponent.getName() + " missed " + subject.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
          }
          else
          {
            ask.narrate(opponent.getName() + " caused " + to_string(monster_dmg) + " critical damage to " + subject.getName() + " with " + to_string(chance_boost) + "% chance to hit!");
            if(opponent.getDMG(monster_dmg)) break;
          }
        }

        if(monster_agility_boost) --monster_agility_boost;
        if(subject_agility_boost) --subject_agility_boost;

        flag_win = true;
    }

    if(flag_win)
    {
        ask.say("You Defeated " + opponent.getName() + "\n\n");
    }
    else
    {
        ask.endChapter();
        ask.say("You Died! RIP[*]");
        exit(0);
    }
}

GameStep* Battle::getNext()
{
    int index_of_riddle=( rand() % BaseOfRiddles.getSize() );
    Riddle drawn_riddle=BaseOfRiddles.getRiddle(index_of_riddle);
    Riddle* riddle_after_battle=new Riddle(drawn_riddle);
    return riddle_after_battle;
}
