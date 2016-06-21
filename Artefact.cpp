#include "Artefact.h"

using namespace std;

Artefact::Artefact(string name_, E_Skill skill_to_boost_, int boost_amount_)
{
    name=name_;
    skill_to_boost=skill_to_boost_;
    boost_amount=boost_amount_;
}

void Artefact::setName(string name_)
{
    name=name_;
}

void Artefact::setSkillBoost(E_Skill skill_to_boost_)
{
    skill_to_boost=skill_to_boost_;
}

void Artefact::setBoostAmount(int boost_amount_)
{
    boost_amount=boost_amount_;
}

string Artefact::getName() const
{
    return name;
}

E_Skill Artefact::getSkillBoost() const
{
    return skill_to_boost;
}

int Artefact::getBoostAmount() const
{
    return boost_amount;
}

void Artefact::printArtefact() const
{
    string skill_in;

    if(skill_to_boost==0) skill_in="Strength";
    if(skill_to_boost==1) skill_in="Agility";
    if(skill_to_boost==2) skill_in="Health Points";

    cout<<name<<"("<<skill_in<<" + "<<boost_amount<<")"<<endl;

}
