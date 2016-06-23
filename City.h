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

#include "GameStep.h"

// -------------------------------------------------------------------------

/**
* \class City
* \author RPGteam
* \date 23.06.2016
* \brief City class, to handle situation, when heroe stays in city
*/
class City : public GameStep
{
    int choice; ///< 1 -> main square ;;; 2 -> left district ;; 3 -> right district
public:
    /// \brief Choice setter
    ///
    /// \param choice_ - 1 -> main square ;;; 2 -> left district ;; 3 -> right district
    void setChoice(int choice_);

    /// \brief Choice getter
    ///
    /// \return 1 -> main square ;;; 2 -> left district ;; 3 -> right district
    int getChoice() const;

    /// \brief This function will ask player, where he wants to ;;; 1 -> main square ;;; 2 -> left district ;; 3 -> right district
    ///
    /// \param subject - Heroe, who will wander through city
    void play(Heroe& subject);

    /// \brief Next step after City
    ///
    /// \return If choice is 1 -> it is MainSquare. If choice is 2 -> it is LeftDistrict. If choice is 3 -> it is RightDistrict
    GameStep* getNext();

};

#endif
