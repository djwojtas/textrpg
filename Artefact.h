/**
* \file Artefact.h
* \author RPGteam
* \date 18.06.2016
* \version 1.0
* \brief File contains the definition of Artefact class
*/
// -------------------------------------------------------------------------

#ifndef ARTEFACT_H
#define ARTEFACT_H

// --------------------------------------------------------------

#include <iostream>

using namespace std;

// --------------------------------------------------------------

/// Enum that represent skills
typedef enum Skill
{STRENGTH=0, ///< strength
 AGILITY, ///< agility
 HP ///< health points
} E_Skill;

/**
* \class Artefact
* \author RPGteam
* \date 18.06.2016
* \brief The definition of Artefact class
*/
class Artefact
{
private:
    string name; ///< Name of artefact
    E_Skill skill_to_boost; ///< Skill, which is strengthened by artefact
    int boost_amount; ///< How much the skill is strengthened
public:
    /// \brief The class constructor
    ///
    /// \param n - name of the created Artefact
    /// \param skill_input - which skill is going to be strengthened by artefact
    /// \param ba - boost amount
    Artefact(string n, E_Skill skill_input, int ba)
    {
        name=n;
        skill_to_boost=skill_input;
        boost_amount=ba;
    }

    /// \brief Name setter
    ///
    /// \param n - name to set
    void setName(string n);

    /// \brief Skill-to-boost setter
    ///
    /// \param s - Skill-to-boost to set
    void setSkillBoost(E_Skill s);

    /// \brief Boost amount setter
    ///
    /// \param a - Boost amount to set
    void setBoostAmount(int a);

    /// \brief Name getter
    ///
    /// \return name of the Artefact
    string getName() const;

    /// \brief Skill-to-boost getter
    ///
    /// \return which skill is boosted by artefact
    E_Skill getSkillBoost() const;

    /// \brief Boost amount getter
    ///
    /// \return boost amount
    int getBoostAmount() const;

    /// \brief Simple printing artefact on screen
    void printArtefact() const;

};

#endif
