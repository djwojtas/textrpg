/**
* \file City.h
* \author RPGteam
* \date 23.06.2016
* \version 1.0
* \brief File contains the definition of City class
*/
// -------------------------------------------------------------------------

#ifndef CITY_H
#define CITY_H

// -------------------------------------------------------------------------

#include "../GameStep.h"

// -------------------------------------------------------------------------

/**
* \class City
* \author RPGteam
* \date 23.06.2016
* \brief City class, to handle situation, when heroe stays in city
*/
class City : public GameStep
{
    int choice; ///< 1 -> suburbs ;;; 2 -> main square ;;; 3 -> left district ;; 4 -> right district
public:
    /// \brief Choice setter
    ///
    /// \param choice_ - 1 -> suburbs ;;; 2 -> main square ;;; 3 -> left district ;; 4 -> right district
    void setChoice(int choice_);

    /// \brief Choice getter
    ///
    /// \return 1 -> suburbs ;;; 2 -> main square ;;; 3 -> left district ;; 4 -> right district
    int getChoice() const;

    /// \brief This function will ask player, where he wants to ;;; 1 -> main square ;;; 2 -> left district ;; 3 -> right district
    ///
    /// \param subject - Heroe, who will wander through city
    void play(Heroe& subject);

    /// \brief Next step after City
    ///
    /// \return If choice is 1 it is suburbs ;;; if 2 it is main square ;;; if 3 it is left district ;; if 4 it is right district
    GameStep* getNext();

};

#endif
