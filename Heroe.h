#ifndef HEROE_H
#define HEROE_H

#include "Artefact.h"
#include <vector>

using namespace std;

class Heroe
{
private:
    int strength;
    int agility;
    int hp;
    vector <Artefact> artefact_list;
    int rune_count;
    string name;
public:
    Heroe(string n, int s, int a, int hpoints);

    //Setters
    void setStrength(int s);
    void setAgility(int a);
    void setHP(int hpoints);
    void setRuneCount(int r);

    //Getters
    int getStrength(int s);
    int getAgility(int a);
    int getHP(int hpoints);
    int getRuneCount(int r);

    //Utility
    void addArtefact(Artefact &ar);
    void printHeroe();
};

#endif
