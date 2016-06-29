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
    int fail_or_victory; ///< 0 -> fail ; 1 -> victory
public:
    /// \brief Default class constructor
    Fate();

    /// \brief Heroe is forced to play one of few games. Success could lead to pleasant things, however failure would probably lead to unpleasant moments
    ///
    /// \param subject - Heroe, who will play game
    void play(Heroe& subject);

    /// \brief Get TRAVEL after FATE
    ///
    /// \return Pointer to TRAVEL GameStep
    GameStep* getNext();

    /// \brief Fail-Or-Victory Getter
    ///
    /// \return 0 -> fail ; 1 -> victory
    int getFailOrVictory();

    /// \brief Fail-Or-Victory Setter
    ///
    /// \param fail_or_victory_ - 0 -> fail ; 1 -> victory
    void setFailOrVictory(int fail_or_victory_);
};

/// \brief Function which represents guessing game possible in Fate--Play
///
/// \param subject - Heroe, who will play game
/// \return integer representing if Heroe won or failed the game 0->success ;;; 1-> fail
int playGuessingGame(Heroe& subject);

/// \brief Function which represents Rock Paper Scissors Game possible in Fate--Play
///
/// \param subject - Heroe, who will play game
/// \return integer representing if Heroe won or failed the game 0->success ;;; 1-> fail
int playRockPaperScissors(Heroe& subject);

/// \brief Function, which is called when Heroe win Fate-Game
///
/// \param subject - Heroe, who won the game
void playVictory(Heroe& subject);

/// \brief Function, which is called when Heroe lose Fate-Game
///
/// \param subject - Heroe, who lost the game
void playFail(Heroe& subject);

#endif
