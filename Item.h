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
		int weight; ///< Item Weight
		
		
	public: 

		/// \brief Price getter
    ///
    /// \return price of the item
		int getPrice();

		/// \brief Weight getter
    ///
    /// \return weight of the item
		int getWeight();
		

		/// \brief Printing item parameters on the screen
		virtual void print() = 0;
		

};

#endif
