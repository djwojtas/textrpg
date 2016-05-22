#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
using namespace std;

class Monster
{
    int strength;
    int agility;
    int hp;
    string name;
public:
    Monster(int s, int a, int hpoints, string n);

    //Getters
    int getStrength() const;
    int getAgility() const;
    int getHP() const;
    string getName() const;
    //END OF GETTERS-------------

    //Setters
    void setAgility(int a);
    void setStrength(int s);
    void setHP(int hpoints);
    void setName(string n);
    //END OF SETTERS-------------

    //Utility
    void printMonster() const;
};

#endif // MONSTER_H
