/**
* \file LeftDistrict.h
* \author RPGteam
* \date 23.06.2016
* \version 1.0
* \brief File contains the definition of LeftDistrict class
*/
// -------------------------------------------------------------------------

#ifndef LEFTDISTRICT_H
#define LEFTDISTRICT_H

// -------------------------------------------------------------------------

#include "../GameStep.h"

// -------------------------------------------------------------------------

/**
* \class LeftDistrict
* \author RPGteam
* \date 23.06.2016
* \brief LeftDistrict class, which represents staying in the Left District of the City
*/
class LeftDistrict : public GameStep
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
