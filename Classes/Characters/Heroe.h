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
    int def; ///< Heroe defense
    int max_hp; ///< Heroe Maximum HP

    //Artefact boosts
    int strength_adder; ///< Amount of boosted strength
    int agility_adder; ///< Amount of boosted agility
    int hp_adder; ///< Amount of boosted Health Points
    int def_adder; ///< Amount of boosted defense

    double strength_multiplier; ///< Amount of boosted strength
    double agility_multiplier; ///< Amount of boosted agility
    double hp_multiplier; ///< Amount of boosted Health Points
    double def_multiplier; ///< Amount of boosted defense

    string name; ///< Just Heroe name
public:
    /// \brief Parametric class constructor
    ///
    /// \param name_ - Heroe's name
    /// \param strength_ - Heroe's strength
    /// \param agility_ - Heroe's agility
    /// \param hp_ - Heroe's HP
    Heroe(string name_, int strength_, int agility_, int hp_, int def_);

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

    /// \brief Def setter
    ///
    /// \param def_ - def to set
    void setDef(int def_);

    /// \brief MAX HP setter
    ///
    /// \param max_hp_ - HP to set
    void setMaxHP(int max_hp_);

    /// \brief Boosted-Strength setter
    ///
    /// \param strength_boost_ - Boosted-Strength to set
    void setStrengthAdder(int strength_adder_);

    /// \brief Boosted-Agility setter
    ///
    /// \param agility_boost_ - Boosted-Agility to set
    void setAgilityAdder(int agility_adder_);

    /// \brief Boosted-HP setter
    ///
    /// \param hp_boost_ - Boosted-HP to set
    void setHPAdder(int hp_adder_);

    /// \brief Multiplier-Strength setter
    ///
    /// \param strength_multiplier_ - Multiplier-Strength to set
    void setStrengthMultiplier(int strength_multiplier_);

    /// \brief Multiplier-Agility setter
    ///
    /// \param agility_multiplier_ - Multiplier-Agility to set
    void setAgilityMultiplier(int agility_multiplier_);

    /// \brief Multiplier-HP setter
    ///
    /// \param hp_multiplier_ - Multiplier-HP to set
    void setHPMultiplier(int hp_multiplier_);
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

    /// \brief def getter
    ///
    /// \return Heroe's def
    int getDef() const;

    /// \brief Boosted-Strength getter
    ///
    /// \return Heroe's Boosted-Strength
    int getStrengthAdder() const;

    /// \brief Boosted-Agility getter
    ///
    /// \return Heroe's Boosted-Agility
    int getAgilityAdder() const;

    /// \brief Boosted-HP getter
    ///
    /// \return Heroe's Boosted-HP
    int getHPAdder() const;

    /// \brief Multiplier-Strength getter
    ///
    /// \return Heroe's Multiplier-Strength
    int getStrengthMultiplier() const;

    /// \brief Multiplier-Agility getter
    ///
    /// \return Heroe's Multiplier-Agility
    int getAgilityMultiplier() const;

    /// \brief Multiplier-HP getter
    ///
    /// \return Heroe's Multiplier-HP
    int getHPMultiplier() const;

    /// \brief Max HP getter
    ///
    /// \return Heroe's max HP
    int getMaxHP() const;

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

    /// \brief Returns strength multiplied by multiplier and added adder
    ///
    /// \return actual character strength with all eq and consumables
    int getFullStrength() const;

    /// \brief Returns agility multiplied by multiplier and added adder
    ///
    /// \return actual character agility with all eq and consumables
    int getFullAgility() const;

    /// \brief Returns HP multiplied by multiplier and added adder
    ///
    /// \return actual character HP with all eq and consumables
    int getFullHP() const;

    /// \brief Returns def multiplied by multiplier and added adder
    ///
    /// \return actual character def with all eq and consumables
    int getFullDef() const;
};

#endif
