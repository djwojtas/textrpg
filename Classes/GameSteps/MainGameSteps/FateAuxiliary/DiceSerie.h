/**
* \file DiceSerie.h
* \author RPGteam
* \date 1.07.2016
* \version 1.0
* \brief File contains the definition of DiceSerie class
*/
// -------------------------------------------------------------------------

#ifndef DICE_SERIE_H
#define DICE_SERIE_H

// -------------------------------------------------------------------------

#include <vector>
#include "dice.h"

using namespace std;

// -------------------------------------------------------------------------

/**
* \class DiceSerie
* \author RPGteam
* \date 1.07.2016
* \brief DiceSerie class
*/
class DiceSerie
{
    vector<Dice> dice_serie; ///< Just five die
    int die_combination_value; ///< Integer, which represents the value of certain poker combination
    vector<int> counters; ///< Auxiliary vector, that is used while measuring the value of die combination
public:
    /// \brief The default constructor
    DiceSerie();

    /// \brief The parameterized constructor
    ///
    /// \param one - Amount of pips on 1st dice
    /// \param two - Amount of pips on 2nd dice
    /// \param three - Amount of pips on 3rd dice
    /// \param four - Amount of pips on 4th dice
    /// \param five - Amount of pips on 5th dice
    DiceSerie(int one, int two, int three, int four, int five);

    /// \brief Rolling -- randomizing amount of pips on the whole 5 die
    void roll();

    /// \brief Printing basic info about die
    void printDie();

    /// \brief Re-Rolling certain die ;;; if n-th element of the vector contains "true", the n-th dice in series will be re-rolled
    ///
    /// \param dieToReRoll - Reference to "re-rolling mask" vector
    void rollChosen(vector<bool>& dieToReRoll);

    /// \brief User chooses which die will be re-rolled
    void rollChosenUserInput();

    /// \brief Computer chooses which die will be re-rolled
    void computerReRoll();

    /// \brief Function, which refreshes the value of series combination
    void refreshValue();

    /// \brief Value of series combination getter
    ///
    /// \return Integer which represents the value of die combination
    int getValue();

    /// \brief Auxiliary function, which fills /vector<int> counters/ with numbers of occurrences for certain pips amount. WARNING! Counters vector is shifted related to pips amount by -1 ;;; e.g. for die combination = (1, 1, 2, 5, 6) ;;; counters[0]=2 ;;; counters[1]=1 ;;; counters[2]=0 ;;; counters[3]=0 ;;; counters[4]=1 ;;; counters[5]=1 ;;;
    void countAmountsOfPips();

    /// \brief Function which checks if there is Poker combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isPoker();

    /// \brief Function which checks if there is FourOfAKind combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isFourOfAKind();

    /// \brief Function which checks if there is FullHouse combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isFullHouse();

    /// \brief Function which checks if there is GreatStraight combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isGreatStraight();

    /// \brief Function which checks if there is LittleStraight combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isLittleStraight();

    /// \brief Function which checks if there is ThreeOfAKind combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isThreeOfAKind();

    /// \brief Function which checks if there is TwoPair combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isTwoPair();

    /// \brief Function which checks if there is OnePair combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isOnePair();

    /// \brief Function which checks if there is HighCard combination
    ///
    /// \return True if there is this combination ;;; false if there is not
    bool isHighCard();

    /// \brief Function which checks which series has greater value
    ///
    /// \return True if first series has lesser value ; false if has not
    bool operator < (DiceSerie& ex);

    /// \brief Function which checks which series has greater value
    ///
    /// \return True if first series has greater value ; false if has not
    bool operator > (DiceSerie& ex);

    /// \brief Function which checks if series has same value
    ///
    /// \return True if first series has same value as the second
    bool operator == (DiceSerie& ex);
};

#endif
