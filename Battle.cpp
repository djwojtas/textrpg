#include "Battle.h"
#include "Monster.h"
#include "RiddleBase.h"
#include "MonsterBase.h"
#include "WriteOut.h"

#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void Battle::play(Heroe& subject)
{
    Monster random_monster = BaseOfMonsters.getMonster( rand() % BaseOfMonsters.getSize() );

    write<<"\n\n"<<random_monster.getName()<<" attacked you!\n\n";

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = random_monster.getStrength();
    int monster_agility_total = random_monster.getAgility();
    int monster_hp_total = random_monster.getHP();
    while(true)
    {
        int heroe_dmg = heroe_strength_total*(rand()%heroe_agility_total);
        write<<subject.getName()<<" cause "<<to_string(heroe_dmg)<<" DMG! \n";

        Sleep(300);

        random_monster.setHP(random_monster.getHP()-heroe_dmg);

        if(random_monster.getHP()<=0)
        {
            break;
        }

        int monster_dmg=monster_strength_total*(rand()%monster_agility_total);
        write<<random_monster.getName()<<" cause "<<to_string(monster_dmg)<<" DMG! \n";

        Sleep(300);

        subject.getDMG(monster_dmg);

        if(subject.getHP()<=0)
        {
            break;
        }
    }

    if(subject.getHP()<=0)
    {
        write<<"\nYou Died! RIP[*]\n";
        exit(0);
    }
    else if(random_monster.getHP()<=0)
    {
        write<<"\nYou Defeated "<<random_monster.getName()<<"\n\n";
    }
}

void Battle::play(Heroe& subject, Monster& opponent)
{
    write<<opponent.getName()<<" attacked you!\n\n";

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = opponent.getStrength();
    int monster_agility_total = opponent.getAgility();
    int monster_hp_total = opponent.getHP();

    while(true)
    {
        int heroe_dmg = heroe_strength_total*(rand()%heroe_agility_total);
        write<<subject.getName()<<" cause "<<to_string(heroe_dmg)<<" DMG! \n";

        Sleep(300);

        opponent.setHP(opponent.getHP()-heroe_dmg);

        if(opponent.getHP()<=0)
            break;

        int monster_dmg=monster_strength_total*(rand()%monster_agility_total);
        write<<opponent.getName()<<" cause "<<to_string(monster_dmg)<<" DMG! \n";
        Sleep(300);

        subject.getDMG(monster_dmg);

        if(subject.getHP()<=0)
            break;
    }

    if(subject.getHP()<=0)
    {
        write<<"\nYou Died! RIP[*]\n";
        exit(0);
    }
    else if(opponent.getHP()<=0)
    {
        write<<"\nYou Defeated "<<opponent.getName()<<"\n";
    }
}

GameStep* Battle::getNext()
{
    int index_of_riddle=( rand() % BaseOfRiddles.getSize() );
    Riddle drawn_riddle=BaseOfRiddles.getRiddle(index_of_riddle);
    Riddle* riddle_after_battle=new Riddle(drawn_riddle);
    return riddle_after_battle;
}
