#ifndef RIDDLE_BASE_H
#define RIDDLE_BASE_H

#include "Riddle.h"
#include <vector>

using namespace std;

class RiddleBase
{
    vector<Riddle> base;
public:
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

    int getSize()
    {
        return base.size();
    }

} BaseOfRiddles;

#endif
