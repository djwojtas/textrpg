/**
* \file RiddleBase.h
* \author RPGteam
* \date 18.06.2016
* \version 1.0
* \brief File contains the definition of RiddleBase class
*/
// -------------------------------------------------------------------------

#ifndef RIDDLE_BASE_H
#define RIDDLE_BASE_H

// -------------------------------------------------------------------------

#include "Riddle.h"
#include <vector>

using namespace std;

// -------------------------------------------------------------------------


/**
* \class RiddleBase
* \author RPGteam
* \date 18.06.2016
* \brief The definition of RiddleBase class. This class is singleton used to store different Riddles, that Heroe will try to solve after Battles
*/
class RiddleBase
{
    vector<Riddle> base; ///< Vector, that contains all the Riddles from the Game Universe
public:
    /// \brief The class constructor, in which different Riddles are pushed to the vector
    RiddleBase();

    /// \brief Function which allows to "pull out" some Riddle from the base
    ///
    /// \param index - index of Riddle in vector (base)
    /// \return some Riddle from the base
    Riddle getRiddle(int index);

    /// \brief Function which returns size of our Riddle base
    ///
    /// \return Amount of Riddles in our base
    int getSize();

};

#endif
