/**
* \file Fate.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Fate class
*/
// -------------------------------------------------------------------------

#ifndef FATE_H
#define FATE_H

// -------------------------------------------------------------------------

#include "GameStep.h"
#include "ArtefactBase.h"

// -------------------------------------------------------------------------

/**
* \class Fate
* \author RPGteam
* \date 20.06.2016
* \brief Fate class
*/
class Fate : public GameStep
{
    ArtefactBase *BaseOfArtefacts; ///< pointer to class that holds vector of all artifacts
    int good_or_bad_luck; ///< 0 -> bad luck ; 1 -> good luck
public:
    /// \brief Default class constructor
    Fate(ArtefactBase *BaseOfArtefacts_);

    /// \brief Play the action connected with Fate game state
    ///
    /// \param subject - Heroe, who will be subject of good or bad luck
    void play(Heroe& subject);

    /// \brief Unfinished function TBD!
    ///
    /// \return Unfinished function TBD!
    GameStep* getNext();

    /// \brief Good-Or-Bad-Luck Getter
    ///
    /// \return 0 -> bad luck ; 1 -> good luck
    int getGoodOrBadLuck();

    /// \brief Good-Or-Bad-Luck Setter
    ///
    /// \param s - 0 -> bad luck ; 1 -> good luck
    void setGoodOrBadLuck(int s);
};

#endif