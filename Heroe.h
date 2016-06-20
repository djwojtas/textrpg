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

#include "Artefact.h"
#include <vector>

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

    //Artefact boosts
    int strength_boost; ///< Amount of boosted strength
    int agility_boost; ///< Amount of boosted agility
    int hp_boost; ///< Amount of boosted Health Points

    vector <Artefact> artefact_list; ///< List of Artefacts owned by Heroe
    int rune_count; ///< Amount of runed, which Heroe obtained
    string name; ///< Just Heroe name
public:
    /// \brief The class constructor
    ///
    /// \param n - Heroe's name
    /// \param s - Heroe's strength
    /// \param a - Heroe's agility
    /// \param hpoints - Heroe's HP
    Heroe(string n, int s, int a, int hpoints);

    //Setters
    /// \brief Strength setter
    ///
    /// \param s - strength to set
    void setStrength(int s);

    /// \brief Agility setter
    ///
    /// \param s - agility to set
    void setAgility(int a);

    /// \brief HP setter
    ///
    /// \param hpoints - HP to set
    void setHP(int hpoints);

    /// \brief Boosted-Strength setter
    ///
    /// \param sb - Boosted-Strength to set
    void setStrengthBoost(int sb);

    /// \brief Boosted-Agility setter
    ///
    /// \param ab - Boosted-Agility to set
    void setAgilityBoost(int ab);

    /// \brief Boosted-HP setter
    ///
    /// \param hpb - Boosted-HP to set
    void setHPBoost(int hpb);

    /// \brief Rune-Count setter
    ///
    /// \param r - Rune-Count to set
    void setRuneCount(int r);
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
    /// \brief Function used to add new Artefact to the Heroe's list
    ///
    /// \param ar - Artefact, which will be added to the list
    void addArtefact(Artefact &ar);

    /// \brief Simple printing base info about Heroe on the screen
    void printHeroe() const;

    /// \brief Function, which is used, when Heroe receives Damage
    ///
    /// \param dmg_amount - How much damage is received
    void getDMG(int dmg_amount);

    /// \brief Function, which is used, when Heroe loses Artefact due to FATE ;'(
    void loseArtefacts();
};

#endif
