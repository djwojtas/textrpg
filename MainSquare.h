/**
* \file MainSquare.h
* \author RPGteam
* \date 23.06.2016
* \version 1.0
* \brief File contains the definition of MainSquare class
*/
// -------------------------------------------------------------------------

#ifndef MAINSQUARE_H
#define MAINSQUARE_H

// -------------------------------------------------------------------------

#include "GameStep.h"

// -------------------------------------------------------------------------

/**
* \class MainSquare
* \author RPGteam
* \date 23.06.2016
* \brief MainSquare class, which represents staying in the Main Square of the City
*/
class MainSquare : public GameStep
{
public:
    /// \brief TBD!
    ///
    /// \param subject - TBD!
    void play(Heroe& subject);

    /// \brief TBD!
    ///
    /// \return TBD!
    GameStep* getNext();
};

#endif
