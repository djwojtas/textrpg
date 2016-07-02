/**
* \file GameStep.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of GameStep abstract class, which represents current state of game
*/
// -------------------------------------------------------------------------

#ifndef GAMESTEP_H
#define GAMESTEP_H

// -------------------------------------------------------------------------

#include "../Characters/Heroe.h"

// -------------------------------------------------------------------------

/**
* \class GameStep
* \author RPGteam
* \date 20.06.2016
* \brief GameStep abstract class, which represents current state of game
*/
class GameStep
{
public:
    /// \brief Virtual function used to carry out the action connected with current game state
    ///
    /// \param subject - Heroe, who will take part in action
    virtual void play(Heroe& subject) = 0;

    /// \brief Virtual function used to get GameStep, which should occur after completing current
    ///
    /// \return GameStep, which should occur after completing current
    virtual GameStep* getNext() = 0;
};

#endif
