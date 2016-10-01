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

    strength_adder=0;
    agility_adder=0;
    hp_adder=0;

    strength_multiplier=1;
    agility_multiplier=1;
    hp_multiplier=1;
}

Heroe::Heroe()
{
    name="";

    strength=0;
    agility=0;
    hp=0;
    max_hp=0;

    strength_adder=0;
    agility_adder=0;
    hp_adder=0;

    strength_multiplier=1;
    agility_multiplier=1;
    hp_multiplier=1;
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

void Heroe::setStrengthAdder(int strength_adder_)
{
    strength_adder=strength_adder_;
}

void Heroe::setAgilityAdder(int agility_adder_)
{
    agility_adder=agility_adder_;
}

void Heroe::setHPAdder(int hp_adder_)
{
    hp_adder=hp_adder_;
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

int Heroe::getStrengthAdder() const
{
    return strength_adder;
}

int Heroe::getAgilityAdder() const
{
    return agility_adder;
}

int Heroe::getHPAdder() const
{
    return hp_adder;
}

string Heroe::getName() const
{
    return name;
}

void Heroe::printHeroe() const
{
    cout<<endl;
    cout<<"Name = "<<getName()<<endl;
    cout<<"Strength = "<<getFullStrength();
    cout<<"Agility = "<<getFullAgility();
    cout<<"Health Points = "<<getFullHP();
}

bool Heroe::getDMG(int dmg_amount)
{
    hp -= dmg_amount;
    cout<<"\n\n"<<dmg_amount<<"\n\n";
    if(hp<=0) return true;
      else return false;
}

void Heroe::setStrengthMultiplier(int strength_multiplier_)
{
  strength_multiplier = strength_multiplier_;
}

void Heroe::setAgilityMultiplier(int agility_multiplier_)
{
  agility_multiplier = agility_multiplier_;
}

void Heroe::setHPMultiplier(int hp_multiplier_)
{
  hp_multiplier = hp_multiplier_;
}

int Heroe::getStrengthMultiplier() const
{
  return strength_multiplier;
}

int Heroe::getAgilityMultiplier() const
{
  return agility_multiplier;
}

int Heroe::getHPMultiplier() const
{
  return hp_multiplier;
}

int Heroe::getFullStrength() const
{
  return strength * strength_multiplier + strength_adder;
}

int Heroe::getFullAgility() const
{
  return agility * agility_multiplier + agility_adder;
}

int Heroe::getFullHP() const
{
  return hp * hp_multiplier + hp_adder;
}
