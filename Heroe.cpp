#include "Heroe.h"

#include <vector>

using namespace std;

Heroe::Heroe(string n, int s, int a, int hpoints)
{
    name=n;

    strength=s;
    agility=a;
    hp=hpoints;

    strength_boost=0;
    agility_boost=0;
    hp_boost=0;

    rune_count=0;
}

void Heroe::setStrength(int s)
{
    strength=s;
}

void Heroe::setAgility(int a)
{
    agility=a;
}

void Heroe::setHP(int hpoints)
{
    hp=hpoints;
}

void Heroe::setStrengthBoost(int sb)
{
    strength_boost=sb;
}

void Heroe::setAgilityBoost(int ab)
{
    agility_boost=ab;
}

void Heroe::setHPBoost(int hpb)
{
    hp_boost=hpb;
}

void Heroe::setRuneCount(int r)
{
    rune_count=r;
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

void Heroe::addArtefact(Artefact &ar)
{
    artefact_list.push_back(ar);

    if(ar.getSkillBoost()==STRENGTH)
    {
        this->strength_boost=ar.getBoostAmount();
    } else
    if (ar.getSkillBoost()==AGILITY)
    {
        this->agility_boost=ar.getBoostAmount();
    } else
    if (ar.getSkillBoost()==HP)
    {
        this->hp_boost=ar.getBoostAmount();
    }
}

void Heroe::printHeroe() const
{
    cout<<endl;
    cout<<"Name = "<<getName()<<endl;
    cout<<"Strength = "<<getStrength()<<" (+"<<getStrengthBoost()<<") "<<endl;
    cout<<"Agility = "<<getAgility()<<" (+"<<getAgilityBoost()<<") "<<endl;
    cout<<"Health Points = "<<getHP()<<" (+"<<getHPBoost()<<") "<<endl;
    cout<<"Possessed Runes = "<<getRuneCount()<<endl;

    cout<<endl;
    cout<<"--List of Artefacts--"<<endl;

    if(artefact_list.size()==0)
    {
        cout<<"  NONE"<<endl;
        return;
    }

    for(int i=0; i<artefact_list.size(); i++)
    {
        cout<<"  "<<i+1<<". ";
        artefact_list[i].printArtefact();
    }
}

void Heroe::getDMG(int dmg_amount)
{
    if(dmg_amount>getHPBoost())
    {
        dmg_amount-=getHPBoost();
        setHPBoost(0);
        setHP(getHP()-dmg_amount);
    } else {
        setHPBoost(getHPBoost()-dmg_amount);
    }
}
