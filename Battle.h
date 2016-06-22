/**
* \file Battle.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Battle class, which is used to handle battles in game
*/
// -------------------------------------------------------------------------

#ifndef BATTLE_H
#define BATTLE_H

// -------------------------------------------------------------------------

#include "GameStep.h"
#include "Monster.h"

// -------------------------------------------------------------------------

/**
* \class Battle
* \author RPGteam
* \date 20.06.2016
* \brief Battle class, which is used to handle battles in game
*/
class Battle:public GameStep
{
public:
    /// \brief Battle with random monster
    ///
    /// \param subject - Heroe, who will take part in battle
    void play(Heroe& subject);

    /// \brief Battle with already defined monster
    ///
    /// \param subject - Heroe, who will take part in battle
    /// \param opponent - Monster, which will be opponent in battle
    void play(Heroe& subject, Monster opponent);

    /// \brief Get RIDDLE after BATTLE
    ///
    /// \return Pointer to Riddle GameStep
    GameStep* getNext();
};

#endif
