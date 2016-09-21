/**
* \file Equipment.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of Equipment class
*/
// -------------------------------------------------------------------------

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"

// -------------------------------------------------------------------------

/**
* \class Equipment
* \author RPGteam
* \date 21.06.2016
* \brief Equipment class
*/

class Equipment: public Item
{
  private:
    int requiredStrength; ///< Strength required to equip this item
    int requiredAgility; ///< Agility required to equip this item
    int* boost_targets; ///< 0 - no effect (don't use for 1st one), 1 - strength, 2 - agility, 3 - health
    double* boost_multiplier; ///< array of numbers by which boost targets will be multiplied, 1 for no effect
    int* boost_adder; ///< numbers which will be added to boost targets, 0 for no effect

  public:

    /// \brief Consumable constructor
    ///
    /// \param time_ - duration of consumable effects in turns, 0 if there is no effect time
    /// \param boost_target_- 1 - strength, 2 - agility, 3 - health
    /// \param boost_multiplier_ - 1 - strength, 2 - agility, 3 - health
    /// \param boost_adder_ - which will be added to boost target,0 for no effect
    /// \param isPermanent_ - determines if after time runs out effects should be taken back
    Equipment(int requiredStrength_, int requiredAgility_, int boost_targets_[3], double boost_multiplier_[3], int boost_adder_[3], int price_, std::string name_, std::string description_);

    /// \brief default Consumable constructor, leaves everything uninitialized
    Equipment();

    /// \brief Required Strength getter
    ///
    /// \return Required Strength to equip the item
    int getRequiredStrength();

    /// \brief Required Agility getter
    ///
    /// \return Required Agility to equip the item
    int getRequiredAgility();

    /// \brief Boost target getter
    ///
    /// \return returns specific (0-2) boost target
    int getBoostTarget(int which);

    /// \brief Boost targets getter
    ///
    /// \return returns pointer to boost targets
    int* getBoostTargets();

    /// \brief Boost multiplier getter
    ///
    /// \return returns specific (0-2) boost multiplier
    double getBoostMultiplier(int which);

    /// \brief Boost multipliers getter
    ///
    /// \return returns pointer to boost multipliers
    double* getBoostMultipliers();

    /// \brief Boost adder getter
    ///
    /// \return returns specific (0-2) boost adder
    int getBoostAdder(int which);

    /// \brief Boost adders getter
    ///
    /// \return returns pointer to boost adders
    int* getBoostAdders();
};

#endif
