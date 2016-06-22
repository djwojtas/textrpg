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

// -------------------------------------------------------------------------

/**
* \class Fate
* \author RPGteam
* \date 20.06.2016
* \brief Fate class
*/
class Fate : public GameStep
{
    int good_or_bad_luck; ///< 0 -> bad luck ; 1 -> good luck
public:
    /// \brief Default class constructor
    Fate();

    /// \brief Heroe is forced to play one of few games. Success could lead to pleasant things, however failure would probably lead to unpleasant moments
    ///
    /// \param subject - Heroe, who will play game
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
    /// \param good_or_bad_luck_ - 0 -> bad luck ; 1 -> good luck
    void setGoodOrBadLuck(int good_or_bad_luck_);
};

#endif
