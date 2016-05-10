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

int Heroe::getStrength(int s)
{
    return strength;
}

int Heroe::getAgility(int a)
{
    return agility;
}

int Heroe::getHP(int hpoints)
{
    return hp;
}

int Heroe::getStrengthBoost()
{
    return strength_boost;
}

int Heroe::getAgilityBoost()
{
    return agility_boost;
}

int Heroe::getHPBoost()
{
    return hp_boost;
}

int Heroe::getRuneCount(int r)
{
    return rune_count;
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

void Heroe::printHeroe()
{
    cout<<endl;
    cout<<"Name = "<<name<<endl;
    cout<<"Strength = "<<strength<<" (+"<<strength_boost<<") "<<endl;
    cout<<"Agility = "<<agility<<" (+"<<agility_boost<<") "<<endl;
    cout<<"Health Points = "<<" (+"<<hp_boost<<") "<<endl;
    cout<<"Possessed Runes = "<<rune_count<<endl;

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