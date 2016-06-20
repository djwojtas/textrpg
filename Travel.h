/**
* \file Travel.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Travel class
*/
// -------------------------------------------------------------------------

#ifndef TRAVEL_H
#define TRAVEL_H

// -------------------------------------------------------------------------

#include "GameStep.h"
#include "ArtefactBase.h"

// -------------------------------------------------------------------------

/**
* \class Travel
* \author RPGteam
* \date 20.06.2016
* \brief Travel class, which will let you to "set off to dangerous areas or to travel by safe roads"...
*/
class Travel:public GameStep
{
    ArtefactBase *BaseOfArtefacts; ///< pointer to class that holds vector of all artifacts
    int choice; ///< 1 -> dangerous areas ;;; 2 -> safe roads
public:
    /// \brief Choice setter
    ///
    /// \param c - 1 -> dangerous areas ;;; 2 -> safe roads
    void setChoice(int c);

    /// \brief Choice getter
    ///
    /// \return 1 -> dangerous areas ;;; 2 -> safe roads
    int getChoice() const;

    /// \brief This function will ask player, if he wants to "set off to dangerous areas or to travel by safe roads" ;;; 1 means -> dangerous areas ;;; 2 means -> safe roads
    ///
    /// \param subject - Heroe, who will go on an expedition
    void play(Heroe& subject);

    /// \brief Next step after Travel
    ///
    /// \return If choice is 1 -> it is Battle. If choice is 2 -> it is Fate
    GameStep* getNext();

};

#endif
