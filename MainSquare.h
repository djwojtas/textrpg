/**
* \file MainSquare.h
* \author RPGteam
* \date 23.06.2016
* \version 1.0
* \brief File contains the definition of MainSquare class
*/
// -------------------------------------------------------------------------

#ifndef MAINSQUARE_H
#define MAINSQUARE_H

// -------------------------------------------------------------------------

#include "GameStep.h"

// -------------------------------------------------------------------------

/**
* \class MainSquare
* \author RPGteam
* \date 23.06.2016
* \brief MainSquare class, which represents staying in the Main Square of the City
*/
class MainSquare : public GameStep
{
    int choice; ///< 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
public:
    /// \brief Choice setter
    ///
    /// \param choice_ - 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
    void setChoice(int choice_);

    /// \brief Choice getter
    ///
    /// \return 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
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

/// \brief Function which represents visiting Healer's workshop
///
/// \param subject - Heroe, who will visit the Healer
/// \return Heroe's choice, what to do next ;;; 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
int visitHealer(Heroe& subject);

/// \brief Function which represents visiting Blacksmith's Forge
///
/// \param subject - Heroe, who will visit the Blacksmith
/// \return Heroe's choice, what to do next ;;; 1 -> stay at MainSquare ;;; 2 -> go back to suburbs
int visitBlacksmith(Heroe& subject);

#endif
