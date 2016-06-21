#include "Item.h"
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
    int price; ///< Item Price
    int weight; ///< Item Weight
    int requiredStrength; ///< Strength required to equip this item
    int requiredAgility; ///< Agility required to equip this item


  public:

    /// \brief Required Strength getter
    ///
    /// \return Required Strength to equip the item
    int getRequiredStrength();

    /// \brief Required Agility getter
    ///
    /// \return Required Agility to equip the item
    int getRequiredAgility();



};

#endif
