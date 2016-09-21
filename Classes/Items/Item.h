/**
* \file Item.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of Item class
*/
// -------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include<iostream>

// -------------------------------------------------------------------------

/**
* \class Item
* \author RPGteam
* \date 21.06.2016
* \brief Item class
*/

class Item
{
private:
    int price; ///< Item Price
    std::string name; ///< Item name
    std::string description; ///< Item description

public:

    /// \brief Item constructor
    ///
    /// \param name_ - Item name
    /// \param description_ - Item description
    /// \param price_ - Item price
    Item(int price_, std::string name_, std::string description_);

    /// \brief default Item constructor, leaves everything uninitialized
    Item();

    /// \brief Price getter
    ///
    /// \return get price of the item
    int getPrice();

    /// \brief Price setter
    ///
    /// \param price_ - Item price
    void setPrice(int price_);

    /// \brief Name getter
    ///
    /// \return get name of the item
    std::string getName();

    /// \brief Name setter
    ///
    /// \param name_ - Item name
    void setName(std::string name_);

    /// \brief Description getter
    ///
    /// \return get description of the item
    std::string getDescription();

    /// \brief Description setter
    ///
    /// \param description_ - Item description
    void setDescription(std::string description_);

};

#endif
