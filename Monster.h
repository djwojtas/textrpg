/**
* \file Monster.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Monster class
*/
// -------------------------------------------------------------------------

#ifndef MONSTER_H
#define MONSTER_H

// -------------------------------------------------------------------------

#include <iostream>
using namespace std;

// -------------------------------------------------------------------------

/**
* \class Monster
* \author RPGteam
* \date 20.06.2016
* \brief Just Monster class
*/
class Monster
{
    int strength; ///< Monster's strength
    int agility; ///< Monster's agility
    int hp; ///< Monster's Health Points
    string name; ///< Monster's name
public:
    /// \brief The class constructor
    ///
    /// \param s - Monster's strength
    /// \param a - Monster's agility
    /// \param hpoints - Monster's HP
    /// \param n - Monster's name
    Monster(int s, int a, int hpoints, string n);

    //Getters
    /// \brief Strength getter
    ///
    /// \return Monster's Strength
    int getStrength() const;

    /// \brief Agility getter
    ///
    /// \return Monster's Agility
    int getAgility() const;

    /// \brief HP getter
    ///
    /// \return Monster's HP
    int getHP() const;

    /// \brief Name getter
    ///
    /// \return Monster's name
    string getName() const;
    //END OF GETTERS-------------

    //Setters

    /// \brief Agility setter
    ///
    /// \param s - agility to set
    void setAgility(int a);

    /// \brief Strength setter
    ///
    /// \param s - strength to set
    void setStrength(int s);

    /// \brief HP setter
    ///
    /// \param hpoints - HP to set
    void setHP(int hpoints);

    /// \brief Name setter
    ///
    /// \param hpoints - Name to set
    void setName(string n);
    //END OF SETTERS-------------

    //Utility
    /// \brief Simple printing base info about Monster on the screen
    void printMonster() const;
};

#endif // MONSTER_H
