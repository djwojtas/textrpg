#include "Monster.h"

Monster::Monster(int s, int a, int hpoints, string n)
{
    strength=s;
    agility=a;
    hp=hpoints;
    name=n;
}

int Monster::getStrength() const
{
    return strength;;
}

int Monster::getAgility() const
{
    return agility;
}

int Monster::getHP() const
{
    return hp;
}

string Monster::getName() const
{
    return name;
}

void Monster::setAgility(int a)
{
    agility=a;
}

void Monster::setStrength(int s)
{
    strength=s;
}

void Monster::setHP(int hpoints)
{
    hp=hpoints;
}

void Monster::setName(string n)
{
    name=n;
}

void Monster::printMonster() const
{
    cout<<endl;
    cout<<"Monster Name = "<<getName()<<endl;
    cout<<"Strength = "<<getStrength()<<endl;
    cout<<"Agility = "<<getAgility()<<endl;
    cout<<"Health Points = "<<getHP()<<endl<<"-----"<<endl;
}

