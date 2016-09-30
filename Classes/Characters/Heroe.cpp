#include "Heroe.h"

#include <vector>

using namespace std;

Heroe::Heroe(string name_, int strength_, int agility_, int hp_)
{
    name=name_;

    strength=strength_;
    agility=agility_;
    hp=hp_;
    max_hp=hp_;

    strength_boost=0;
    agility_boost=0;
    hp_boost=0;

    rune_count=0;
}

Heroe::Heroe()
{
    name="";

    strength=0;
    agility=0;
    hp=0;
    max_hp=0;

    strength_boost=0;
    agility_boost=0;
    hp_boost=0;

    rune_count=0;
}

void Heroe::setName(string name_)
{
  name=name_;
}

void Heroe::setStrength(int strength_)
{
    strength=strength_;
}

void Heroe::setAgility(int agility_)
{
    agility=agility_;
}

void Heroe::setHP(int hp_)
{
    hp=hp_;
}

void Heroe::setMaxHP(int max_hp_)
{
    max_hp=max_hp_;
}

void Heroe::setStrengthBoost(int strength_boost_)
{
    strength_boost=strength_boost_;
}

void Heroe::setAgilityBoost(int agility_boost_)
{
    agility_boost=agility_boost_;
}

void Heroe::setHPBoost(int hp_boost_)
{
    hp_boost=hp_boost_;
}

void Heroe::setRuneCount(int rune_count_)
{
    rune_count=rune_count_;
}

int Heroe::getStrength() const
{
    return strength;
}

int Heroe::getAgility() const
{
    return agility;
}

int Heroe::getHP() const
{
    return hp;
}

int Heroe::getMaxHP() const
{
    return max_hp;
}

int Heroe::getStrengthBoost() const
{
    return strength_boost;
}

int Heroe::getAgilityBoost() const
{
    return agility_boost;
}

int Heroe::getHPBoost() const
{
    return hp_boost;
}

int Heroe::getRuneCount() const
{
    return rune_count;
}

string Heroe::getName() const
{
    return name;
}

void Heroe::printHeroe() const
{
    cout<<endl;
    cout<<"Name = "<<getName()<<endl;
    cout<<"Strength = "<<getStrength()<<" (+"<<getStrengthBoost()<<") "<<endl;
    cout<<"Agility = "<<getAgility()<<" (+"<<getAgilityBoost()<<") "<<endl;
    cout<<"Health Points = "<<getHP()<<" (+"<<getHPBoost()<<") "<<endl;
    cout<<"Possessed Runes = "<<getRuneCount()<<endl;
}

bool Heroe::getDMG(int dmg_amount)
{
    hp -= dmg_amount;
    cout<<"\n\n"<<dmg_amount<<"\n\n";
    if(hp<=0) return true;
      else return false;
}
