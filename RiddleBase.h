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
    RiddleBase()
    {
        Riddle first("What has roots as nobody sees, Is taller than trees Up, up, up it goes, And yet never grows?", "Mountain");
        Riddle second("Thirty white horses on a red hill, First they champ, Then they stamp, Then they stand still.", "Teeth");
        Riddle third("It cannot be seen, cannot be felt, Cannot be heard, cannot be smelt. It lies behind stars and under hills, And empty holes it fills. It comes first and follows after, Ends life, kills laughter.", "Dark");
        Riddle fourth("A box without hinges, key or lid, Yet golden treasure inside is hid.", "Egg");

        base.push_back(first);
        base.push_back(second);
        base.push_back(third);
        base.push_back(fourth);
    }

    /// \brief Function which allows to "pull out" some Riddle from the base
    ///
    /// \param index - index of Riddle in vector (base)
    /// \return some Riddle from the base
    Riddle getRiddle(int index)
    {
        if(index>base.size())
        {
            return base[0];
        } else
        {
            return base[index];
        }
    }

    /// \brief Function which returns size of our Riddle base
    ///
    /// \return Amount of Riddles in our base
    int getSize()
    {
        return base.size();
    }

} BaseOfRiddles;

#endif
