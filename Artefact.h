#ifndef ARTEFACT_H
#define ARTEFACT_H

#include <iostream>

using namespace std;

typedef enum Skill
{STRENGTH=0, AGILITY, HP} E_Skill;

class Artefact
{
private:
    string name;
    E_Skill skill_to_boost; //Skill, that artefact strenghten
    int boost_amount;
public:
    Artefact(string n, E_Skill skill_input, int ba)
    {
        name=n;
        skill_to_boost=skill_input;
        boost_amount=ba;
    }

    //Setters
    void setName(string n);
    void setSkillBoost(E_Skill s);
    void setBoostAmount(int a);

    //Getters
    string getName();
    E_Skill getSkillBoost();
    int getBoostAmount();

    //Utilities
    void printArtefact();

};

#endif
