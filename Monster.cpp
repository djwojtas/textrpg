#include "Monster.h"

Monster::Monster(int strength_, int agility_, int hp_, string name_)
{
    strength=strength_;
    agility=agility_;
    hp=hp_;
    max_hp=hp_;
    name=name_;
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

int Monster::getMaxHP() const
{
    return max_hp;
}

string Monster::getName() const
{
    return name;
}

void Monster::setAgility(int agility_)
{
    agility=agility_;
}

void Monster::setStrength(int strength_)
{
    strength=strength_;
}

void Monster::setHP(int hp_)
{
    hp=hp_;
}

void Monster::setMaxHP(int max_hp_)
{
    max_hp=max_hp_;
}

void Monster::setName(string name_)
{
    name=name_;
}

bool Monster::getDMG(int dmg_amount)
{
    hp -= dmg_amount;
    if(hp<=0) return true;
      else return false;
}

void Monster::printMonster() const
{
    cout<<endl;
    cout<<"Monster Name = "<<getName()<<endl;
    cout<<"Strength = "<<getStrength()<<endl;
    cout<<"Agility = "<<getAgility()<<endl;
    cout<<"Health Points = "<<getHP()<<endl<<"-----"<<endl;
}

