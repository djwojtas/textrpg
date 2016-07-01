/**
* \file Dice.h
* \author RPGteam
* \date 1.07.2016
* \version 1.0
* \brief File contains the definition of Dice class
*/
// -------------------------------------------------------------------------

#ifndef DICE_H
#define DICE_H

// -------------------------------------------------------------------------

/**
* \class Dice
* \author RPGteam
* \date 1.07.2016
* \brief Dice class
*/
class Dice
{
    int amount_of_pips; ///< Amount of dots on the dice
public:
    /// \brief The default constructor
    Dice();

    /// \brief Parameterized constructor
    ///
    /// \param amount_of_pips_ - Amount of pips on newly-created dice
    Dice(int amount_of_pips_);

    /// \brief Rolling -- randomizing amount of pips on the dice
    void rollDice();

    /// \brief amount_of_pips Getter
    ///
    /// \return Amount of pips on the dice
    int getAmountOfPips() const;

    /// \brief Operator which compares amounts of pips on die
    ///
    /// \param ex - Dice to compare
    /// \return True if first dice has less pips than the second ; false if has not
    bool operator < (const Dice ex);

    /// \brief Operator which compares amounts of pips on die
    ///
    /// \param ex - Dice to compare
    /// \return True if the first dice has more pips than the second ; false if has not
    bool operator > (const Dice ex);

    /// \brief Operator which compares amounts of pips on die
    ///
    /// \param ex - Dice to compare
    /// \return True if the first dice has the same amount of pips as the second ; false if has not
    bool operator == (const Dice ex);
};

#endif
