#include "Heroe.h"

#include <vector>

using namespace std;

Heroe::Heroe(string n, int s, int a, int hpoints)
{
    name=n;
    strength=s;
    agility=a;
    hp=hpoints;
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

int Heroe::getRuneCount(int r)
{
    return rune_count;
}

void Heroe::addArtefact(Artefact &ar)
{
    artefact_list.push_back(ar);
}

void Heroe::printHeroe()
{
    cout<<endl;
    cout<<"Name = "<<name<<endl;
    cout<<"Strength = "<<strength<<endl;
    cout<<"Agility = "<<agility<<endl;
    cout<<"Health Points = "<<hp<<endl;
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
