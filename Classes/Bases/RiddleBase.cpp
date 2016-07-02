#include "RiddleBase.h"

using namespace std;

RiddleBase::RiddleBase()
{
    Riddle first("What has roots as nobody sees\nIs taller than trees\nUp, up, up it goes\nAnd yet never grows?", "mountain");
    Riddle second("Thirty white horses on a red hill\nFirst they champ\nThen they stamp\nThen they stand still.", "teeth");
    Riddle third("It cannot be seen cannot be felt\nCannot be heard cannot be smelt.\nIt lies behind stars and under hills\nAnd empty holes it fills.\nIt comes first and follows after\nEnds life, kills laughter.", "dark");
    Riddle fourth("A box without hinges, key or lid\nYet golden treasure inside is hid.", "egg");
    Riddle fifth("Voiceless it cries\nWingless flutters\nToothless bites\nMouthless mutters...", "wind");
    Riddle seventh("This thing all things devours: Birds, beasts, trees, flowers\nGnaws iron, bites steel\nGrinds hard stones to meal\nSlays king, ruins town, And beats high mountain down.", "time");
    Riddle sixth("Alive without breath, As cold as death\nNever thirsty, ever drinking, All in mail never clinking", "fish");


    base.push_back(first);
    base.push_back(second);
    base.push_back(third);
    base.push_back(fourth);
    base.push_back(fifth);
    base.push_back(sixth);
    base.push_back(seventh);
}

Riddle RiddleBase::getRiddle(int index)
{
    if(index>base.size())
    {
        return base[0];
    }
    else
    {
        return base[index];
    }
}

void RiddleBase::popRiddle(int index)
{
    if((index>=base.size())||(index<0))
    {
        return;
    }
    else
    {
        base.erase(base.begin() + index);
    }
}

int RiddleBase::getSize()
{
    return base.size();
}

RiddleBase BaseOfRiddles;
