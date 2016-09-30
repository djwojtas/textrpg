/**
* \file Heroe.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Heroe class
*/
// -------------------------------------------------------------------------

#ifndef HEROE_H
#define HEROE_H

// -------------------------------------------------------------------------

#include <vector>
#include <iostream>

using namespace std;

// -------------------------------------------------------------------------

/**
* \class Heroe
* \author RPGteam
* \date 20.06.2016
* \brief Just Heroe class
*/
class Heroe
{
private:
    //Own Skills
    int strength; ///< Heroe strength
    int agility; ///< Heroe agility
    int hp; ///< Heroe Health Points
    int max_hp; ///< Heroe Maximum HP

    //Artefact boosts
    int strength_boost; ///< Amount of boosted strength
    int agility_boost; ///< Amount of boosted agility
    int hp_boost; ///< Amount of boosted Health Points

    int rune_count; ///< Amount of runed, which Heroe obtained
    string name; ///< Just Heroe name
public:
    /// \brief Parametric class constructor
    ///
    /// \param name_ - Heroe's name
    /// \param strength_ - Heroe's strength
    /// \param agility_ - Heroe's agility
    /// \param hp_ - Heroe's HP
    Heroe(string name_, int strength_, int agility_, int hp_);

    /// \brief Default class constructor, sets everything to 0, name to ""
    Heroe();

    //Setters
    /// \brief Name setter
    ///
    /// \param name_ - name to set
    void setName(string name_);

    /// \brief Strength setter
    ///
    /// \param strength_ - strength to set
    void setStrength(int strength_);

    /// \brief Agility setter
    ///
    /// \param agility_ - agility to set
    void setAgility(int agility_);

    /// \brief HP setter
    ///
    /// \param hp_ - HP to set
    void setHP(int hp_);

    /// \brief MAX HP setter
    ///
    /// \param max_hp_ - HP to set
    void setMaxHP(int max_hp_);

    /// \brief Boosted-Strength setter
    ///
    /// \param strength_boost_ - Boosted-Strength to set
    void setStrengthBoost(int strength_boost_);

    /// \brief Boosted-Agility setter
    ///
    /// \param agility_boost_ - Boosted-Agility to set
    void setAgilityBoost(int agility_boost_);

    /// \brief Boosted-HP setter
    ///
    /// \param hp_boost_ - Boosted-HP to set
    void setHPBoost(int hp_boost_);

    /// \brief Rune-Count setter
    ///
    /// \param rune_count_ - Rune-Count to set
    void setRuneCount(int rune_count_);
    //END OF SETTERS-------------

    //Getters
    /// \brief Strength getter
    ///
    /// \return Heroe's Strength
    int getStrength() const;

    /// \brief Agility getter
    ///
    /// \return Heroe's Agility
    int getAgility() const;

    /// \brief HP getter
    ///
    /// \return Heroe's HP
    int getHP() const;

    /// \brief Boosted-Strength getter
    ///
    /// \return Heroe's Boosted-Strength
    int getStrengthBoost() const;

    /// \brief Boosted-Agility getter
    ///
    /// \return Heroe's Boosted-Agility
    int getAgilityBoost() const;

    /// \brief Boosted-HP getter
    ///
    /// \return Heroe's Boosted-HP
    int getHPBoost() const;

    /// \brief Max HP getter
    ///
    /// \return Heroe's max HP
    int getMaxHP() const;

    /// \brief Rune-Count getter
    ///
    /// \return - Amount of Runes possessed by Heroe
    int getRuneCount() const;

    /// \brief Name getter
    ///
    /// \return Heroe's name
    string getName() const;
    //END OF GETTERS-----------

    //Utility
    /// \brief Simple printing base info about Heroe on the screen
    void printHeroe() const;

    /// \brief Function, which is used, when Heroe receives Damage
    ///
    /// \param dmg_amount - How much damage is received
    bool getDMG(int dmg_amount);
};

#endif
