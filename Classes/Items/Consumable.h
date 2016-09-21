/**
* \file Equipment.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of Consumable class
*/
// -------------------------------------------------------------------------

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"

// -------------------------------------------------------------------------

/**
* \class Consumable
* \author RPGteam
* \date 14.09.2016
* \brief Consumable class
*/

class Consumable: public Item
{
  private:
    int time; ///< duration of consumable effects in turns, 0 if there is no effect time
    int boost_target; ///< 1 - strength, 2 - agility, 3 - health
    double boost_multiplier; ///< number by which boost target will be multiplied, 1 for no effect
    int boost_adder; ///< number which will be added to boost target,0 for no effect
    bool isPermanent; ///< determines if after time runs out effects should be taken back

  public:

    /// \brief Consumable constructor
    ///
    /// \param time_ - duration of consumable effects in turns, 0 if there is no effect time
    /// \param boost_target_- 1 - strength, 2 - agility, 3 - health
    /// \param boost_multiplier_ - 1 - strength, 2 - agility, 3 - health
    /// \param boost_adder_ - which will be added to boost target,0 for no effect
    /// \param isPermanent_ - determines if after time runs out effects should be taken back
    Consumable(int time_, int boost_target_, double boost_multiplier_, int boost_adder_, bool isPermanent_, int price_, std::string name_, std::string description_);

    /// \brief default Consumable constructor, leaves everything uninitialized
    Consumable();

    /// \brief time getter
    ///
    /// \return duration of consumable effects in turns, 0 if there is no effect time
    int getTime();

    /// \brief boost target getter
    ///
    /// \return 1 - strength, 2 - agility, 3 - health
    int getBoostTarget();

    /// \brief boost multiplier getter
    ///
    /// \return number by which boost target will be multiplied
    double getBoostMultiplier();

    /// \brief boost adder getter
    ///
    /// \return number which will be added to boost target
    int getBoostAdder();

    /// \brief boost permanent getter
    ///
    /// \return Number by which boost target will be multiplied
    bool getIsPermanent();

    /// \brief time setter
    ///
    /// \param time_ - duration of consumable effects in turns, 0 if there is no effect time
    void setTime(int time_);

    /// \brief boost target setter
    ///
    /// \param boost_target_ - 1 - strength, 2 - agility, 3 - health
    void setBoostTarget(int boost_target_);

    /// \brief boost multiplier
    ///
    /// \param boost_multiplier_ - number by which boost target will be multiplied
    void setBoostMultiplier(double boost_multiplier_);

    /// \brief boost adder
    ///
    /// \param boost_adder_ - number which will be added to boost target
    void setBoostAdder(int boost_adder_);

    /// \brief is boost permanent
    ///
    /// \param isPermanent_ - Number by which boost target will be multiplied
    void setIsPermanent(bool isPermanent_);

};

#endif
