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
    int def; ///< Monster's defense
    int max_hp; ///< Monster's maximum Health Points
    string name; ///< Monster's name
public:
    /// \brief The class constructor
    ///
    /// \param strength_ - Monster's strength
    /// \param agility_ - Monster's agility
    /// \param hp_ - Monster's HP
    /// \param name_ - Monster's name
    Monster(int strength_, int agility_, int hp_, int def, string name_);

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

    /// \brief def getter
    ///
    /// \return Monster's def
    int getDef() const;

    /// \brief Max HP getter
    ///
    /// \return Monster's Max HP
    int getMaxHP() const;

    /// \brief Name getter
    ///
    /// \return Monster's name
    string getName() const;
    //END OF GETTERS-------------

    //Setters

    /// \brief Agility setter
    ///
    /// \param agility_ - agility to set
    void setAgility(int agility_);

    /// \brief Strength setter
    ///
    /// \param strength_ - strength to set
    void setStrength(int strength_);

    /// \brief HP setter
    ///
    /// \param hp_ - HP to set
    void setHP(int hp_);

    /// \brief def setter
    ///
    /// \param def_ - def to set
    void setDef(int def_);

    /// \brief Max HP setter
    ///
    /// \param max_hp_ - Max HP to set
    void setMaxHP(int max_hp_);

    /// \brief Name setter
    ///
    /// \param name_ - Name to set
    void setName(string name_);
    //END OF SETTERS-------------

    //Utility
    /// \brief Simple printing base info about Monster on the screen
    void printMonster() const;

    /// \brief Function, which is used, when Monster receives Damage
    ///
    /// \param dmg_amount - How much damage is received
    bool getDMG(int dmg_amount);
};

#endif // MONSTER_H
