/**
* \file RightDistrict.h
* \author RPGteam
* \date 23.06.2016
* \version 1.0
* \brief File contains the definition of RightDistrict class
*/
// -------------------------------------------------------------------------

#ifndef RIGHTDISTRICT_H
#define RIGHTDISTRICT_H

// -------------------------------------------------------------------------

#include "GameStep.h"

// -------------------------------------------------------------------------

/**
* \class RightDistrict
* \author RPGteam
* \date 23.06.2016
* \brief RightDistrict class, which represents staying in the Right District of the City
*/
class RightDistrict : public GameStep
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
