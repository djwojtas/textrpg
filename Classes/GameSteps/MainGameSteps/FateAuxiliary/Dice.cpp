#include "Dice.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Dice::Dice()
{
    ;
}

Dice::Dice(int amount_of_pips_)
{
    amount_of_pips = amount_of_pips_;
}

void Dice::rollDice()
{
    amount_of_pips = rand() % 6 + 1;
}

int Dice::getAmountOfPips() const
{
    return amount_of_pips;
}

bool Dice::operator < (const Dice ex)
{
    return this->amount_of_pips < ex.getAmountOfPips();
}

bool Dice::operator > (const Dice ex)
{
    return this->amount_of_pips > ex.getAmountOfPips();
}

bool Dice::operator == (const Dice ex)
{
    return this->amount_of_pips == ex.getAmountOfPips();
}
