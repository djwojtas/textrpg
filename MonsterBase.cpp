#include "MonsterBase.h"

using namespace std;

MonsterBase::MonsterBase()
{
    /* Monster(str, agi, hp, name) */

    //woodland creatures
    Monster cockroach(1, 1, 1, "Cockroach");  //3
    Monster mouse(1, 2, 1, "Mouse");          //4
    Monster rat(2, 2, 1, "Rat");              //5
    Monster huge_worm(2, 1, 2, "Big worm");   //5
    Monster wasp(1, 5, 1, "Wasp");            //7
    Monster spider(2, 5, 2, "Spider");        //9
    Monster fox(2, 5, 3, "Fox");              //10
    Monster coyote(3, 6, 3, "Coyote");        //12
    Monster wolf(5, 5, 4, "Wolf");            //14
    Monster hawk(2, 12, 3, "Hawk");           //17
    Monster eagle(4, 10, 4, "Eagle");         //18
    Monster honey_badger(3, 6, 15, "Honey Badger");//24
    Monster tiger(10, 10, 10, "Tiger");       //30
    Monster bear(20, 8, 15, "Bear");          //43

    //orcs, goblins maybe undead or elfs or tons of other shit later
    /*Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );
    Monster wasp(, , , );*/

    base.push_back(cockroach);
    base.push_back(mouse);
    base.push_back(rat);
    base.push_back(huge_worm);
    base.push_back(wasp);
    base.push_back(spider);
    base.push_back(fox);
    base.push_back(coyote);
    base.push_back(wolf);
    base.push_back(hawk);
    base.push_back(eagle);
    base.push_back(honey_badger);
    base.push_back(tiger);
    base.push_back(bear);
}

Monster MonsterBase::getMonster(int index)
{
    if(index>base.size())
    {
        return base[0];
    }
    else
    {
        return base[index];
    }
}

int MonsterBase::getSize()
{
    return base.size();
}

/** \brief Only one existing MonsterBase object, used to store Monsters */
MonsterBase BaseOfMonsters;
