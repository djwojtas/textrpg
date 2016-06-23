/**
* \file Riddle.h
* \author RPGteam
* \date 20.06.2016
* \version 1.0
* \brief File contains the definition of Riddle class. Riddles occurs after Battles
*/
// -------------------------------------------------------------------------

#ifndef RIDDLE_H
#define RIDDLE_H

// -------------------------------------------------------------------------

#include "GameStep.h"

// -------------------------------------------------------------------------

/**
* \class Riddle
* \author RPGteam
* \date 20.06.2016
* \brief Riddle class. Riddles occurs after Battles
*/
class Riddle:public GameStep
{
    string riddle_text; ///< Content of the Riddle
    string correct_answer; ///< Riddle solution
public:
    /// \brief The class constructor
    ///
    /// \param riddle_text_ - Content of Riddle
    /// \param correct_answer_ - Correct Answer
    Riddle(string riddle_text_, string correct_answer_);

    /// \brief Riddle Text Getter
    ///
    /// \return Content of Riddle
    string getRiddleText() const;

    /// \brief Correct Answer Getter
    ///
    /// \return Riddle solution
    string getCorrectAnswer() const;

    /// \brief Carry out the action connected with Riddle game state
    ///
    /// \param subject - Heroe, who will try to solve the Riddle
    void play(Heroe& subject);

    /// \brief Get TRAVEL after BATTLE
    ///
    /// \return Pointer to TRAVEL GameStep
    GameStep* getNext();
};

#endif
