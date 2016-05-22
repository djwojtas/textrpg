#include "Battle.h"
#include "Monster.h"
#include "RiddleBase.h"

#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void Battle::play(Heroe& subject)
{
    int drawn_strength =( rand() % 8 ) + 2; //from 2 to 9
    int drawn_agility =( rand() % 8 ) + 2;
    int drawn_hp =( rand() % 18 ) + 2; //from 2 to 19

    Monster random_monster(drawn_strength, drawn_agility, drawn_hp, "Random Monster");

    cout<<random_monster.getName()<<" attacked you!"<<endl<<endl;

    subject.printHeroe();
    random_monster.printMonster();

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = random_monster.getStrength();
    int monster_agility_total = random_monster.getAgility();
    int monster_hp_total = random_monster.getHP();
    while(true)
    {
        int heroe_dmg = heroe_strength_total*(rand()%heroe_agility_total);
        cout<<subject.getName()<<" cause "<<heroe_dmg<<" DMG!"<<endl;

        Sleep(500);

        random_monster.setHP(random_monster.getHP()-heroe_dmg);

        if(random_monster.getHP()<=0)
        {
            break;
        }

        int monster_dmg=monster_strength_total*(rand()%monster_agility_total);
        cout<<random_monster.getName()<<" cause "<<monster_dmg<<" DMG!"<<endl;
        Sleep(500);

        subject.getDMG(monster_dmg);

        if(subject.getHP()<=0)
        {
            break;
        }
    }

    if(subject.getHP()<=0)
    {
        cout<<"You Died!"<<endl;
    }
    else if(random_monster.getHP()<=0)
    {
        cout<<"You Defeated"<<random_monster.getName()<<endl;
    }
}

void Battle::play(Heroe& subject, Monster& opponent)
{
    cout<<opponent.getName()<<" attacked you!"<<endl<<endl;

    subject.printHeroe();
    opponent.printMonster();

    int heroe_strength_total = subject.getStrength()+subject.getStrengthBoost();
    int heroe_agility_total = subject.getAgility()+subject.getAgilityBoost();
    int heroe_hp_total = subject.getHP()+subject.getHPBoost();

    int monster_strength_total = opponent.getStrength();
    int monster_agility_total = opponent.getAgility();
    int monster_hp_total = opponent.getHP();
    while(true)
    {
        int heroe_dmg = heroe_strength_total*(rand()%heroe_agility_total);
        cout<<subject.getName()<<" cause "<<heroe_dmg<<" DMG!"<<endl;

        Sleep(500);

        opponent.setHP(opponent.getHP()-heroe_dmg);

        if(opponent.getHP()<=0)
        {
            break;
        }

        int monster_dmg=monster_strength_total*(rand()%monster_agility_total);
        cout<<opponent.getName()<<" cause "<<monster_dmg<<" DMG!"<<endl;
        Sleep(500);

        subject.getDMG(monster_dmg);

        if(subject.getHP()<=0)
        {
            break;
        }
    }

    if(subject.getHP()<=0)
    {
        cout<<"You Died!"<<endl;
    }
    else if(opponent.getHP()<=0)
    {
        cout<<"You Defeated "<<opponent.getName()<<endl;
    }
}

GameStep* Battle::getNext()
{
    int index_of_riddle=( rand() % BaseOfRiddles.getSize() );
    Riddle drawn_riddle=BaseOfRiddles.getRiddle(index_of_riddle);

    Riddle* riddle_after_battle=new Riddle(drawn_riddle);

    return riddle_after_battle;
}
