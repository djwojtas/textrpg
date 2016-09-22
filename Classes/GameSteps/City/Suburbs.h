/**
* \file Suburbs.h
* \author RPGteam
* \date 14.09.2016
* \version 1.0
* \brief File contains the definition of Suburbs class
*/
// -------------------------------------------------------------------------

#ifndef SUBURBS_H
#define SUBURBS_H

// -------------------------------------------------------------------------

#include "../GameStep.h"

// -------------------------------------------------------------------------

/**
* \class Suburbs
* \author RPGteam
* \date 23.06.2016
* \brief Suburbs class, which represents staying in the Suburbs of the City
*/
class Suburbs : public GameStep
{
    int choice; ///< 1 -> stay at Suburbs ;;; 2 -> go somewhere else
public:
    /// \brief Choice setter
    ///
    /// \param choice_ - 1 -> stay at Suburbs ;;; 2 -> go somewhere else
    void setChoice(int choice_);

    /// \brief Choice getter
    ///
    /// \return 1 -> stay at Suburbs ;;; 2 -> go somewhere else
    int getChoice() const;

    /// \brief TBD!
    ///
    /// \param subject - TBD!
    void play(Heroe& subject);

    /// \brief TBD!
    ///
    /// \return TBD!
    GameStep* getNext();
};

/// \brief Function which represents visiting Trader
///
/// \param subject - Heroe, who will visit the Trader
/// \return Heroe's choice, what to do next ;;; 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
int visitTrader(Heroe& subject);

#endif
