/**
* \file Start.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Start class
*/
// -------------------------------------------------------------------------

#ifndef START_H
#define START_H

// -------------------------------------------------------------------------

#include "../GameStep.h"

// -------------------------------------------------------------------------

/**
* \class Start
* \author RPGteam
* \date 20.06.2016
* \brief Start class used to initialize the game
*/
class Start:public GameStep
{
public:
    /// \brief Initialize the game, it means -> Randomize Heroe attributes
    ///
    /// \param subject - Heroe, who will be initialized
    void play(Heroe& subject);

    /// \brief Unfinished function TBD!
    ///
    /// \return Unfinished function TBD!
    GameStep* getNext();
};

#endif
