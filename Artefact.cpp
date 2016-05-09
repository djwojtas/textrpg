#include "Artefact.h"


using namespace std;

void Artefact::setName(string n)
{
    name=n;
}

void Artefact::setSkillBoost(E_Skill s)
{
    skill_to_boost=s;
}

void Artefact::setBoostAmount(int a)
{
    boost_amount=a;
}

string Artefact::getName()
{
    return name;
}

E_Skill Artefact::getSkillBoost()
{
    return skill_to_boost;
}

int Artefact::getBoostAmount()
{
    return boost_amount;
}

void Artefact::printArtefact()
{
    string skill_in;

    if(skill_to_boost==0) skill_in="Strength";
    if(skill_to_boost==1) skill_in="Agility";
    if(skill_to_boost==2) skill_in="Health Points";

    cout<<name<<"("<<skill_in<<" + "<<boost_amount<<")"<<endl;

}
