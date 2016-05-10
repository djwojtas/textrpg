#ifndef HEROE_H
#define HEROE_H

#include "Artefact.h"
#include <vector>

using namespace std;

class Heroe
{
private:
    //Own Skills
    int strength;
    int agility;
    int hp;

    //Artefact boosts
    int strength_boost;
    int agility_boost;
    int hp_boost;

    vector <Artefact> artefact_list;
    int rune_count;
    string name;
public:
    Heroe(string n, int s, int a, int hpoints);

    //Setters
    void setStrength(int s);
    void setAgility(int a);
    void setHP(int hpoints);

    void setStrengthBoost(int sb);
    void setAgilityBoost(int ab);
    void setHPBoost(int hpb);

    void setRuneCount(int r);
    //END OF SETTERS-------------

    //Getters
    int getStrength(int s);
    int getAgility(int a);
    int getHP(int hpoints);

    int getStrengthBoost();
    int getAgilityBoost();
    int getHPBoost();

    int getRuneCount(int r);
    //END OF GETTERS-----------

    //Utility
    void addArtefact(Artefact &ar);
    void printHeroe();
};

#endif
