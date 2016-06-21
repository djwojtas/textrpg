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

/// Enum, that represent skills (Heroe's skills or Monster's skills
typedef enum Skill
{STRENGTH=0, ///< Strength
AGILITY, ///< Agility
HP ///< HealthPoints
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
    /// \param name_ - name of the created Artefact
    /// \param skill_to_boost_ - which skill is going to be strengthened by artefact
    /// \param boost_amount_ - boost amount
    Artefact(string name_, E_Skill skill_to_boost_, int boost_amount_);

    /// \brief Name setter
    ///
    /// \param name_ - name to set
    void setName(string name_);

    /// \brief Skill-to-boost setter
    ///
    /// \param skill_to_boost_ - Skill-to-boost to set
    void setSkillBoost(E_Skill skill_to_boost_);

    /// \brief Boost amount setter
    ///
    /// \param boost_amount_ - Boost amount to set
    void setBoostAmount(int boost_amount_);

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
