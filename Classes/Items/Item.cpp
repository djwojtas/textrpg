#include "Item.h"

int Item::getPrice()
{
	return price;
}

std::string Item::getName()
{
	return name;
}

std::string Item::getDescription()
{
	return description;
}

void Item::setPrice(int price_)
{
  price = price_;
}

void Item::setName(std::string name_)
{
  name = name_;
}

void Item::setDescription(std::string description_)
{
  description = description_;
}

Item::Item(int price_, std::string name_, std::string description_)
{
  price = price_;
  name = name_;
  description = description_;
}

Item::Item(){}
