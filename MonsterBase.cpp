#include "MonsterBase.h"

using namespace std;

MonsterBase::MonsterBase()
{
    Monster first(10, 10, 10, "Centaur");
    Monster second(5, 5, 5, "Harpyia");
    Monster third(20, 20, 20, "Griffin");

    base.push_back(first);
    base.push_back(second);
    base.push_back(third);
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
