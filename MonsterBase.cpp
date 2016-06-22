#include "MonsterBase.h"

using namespace std;

MonsterBase::MonsterBase()
{
    Monster first(1, 1, 50, "Centaur");
    Monster second(1, 1, 50, "Harpyia");
    Monster third(1, 1, 50, "Griffin");

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

MonsterBase BaseOfMonsters;
