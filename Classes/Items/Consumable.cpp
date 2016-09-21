#include "Consumable.h"

int Consumable::getTime()
{
  return time;
}

int Consumable::getBoostTarget()
{
  return boost_target;
}

double Consumable::getBoostMultiplier()
{
  return boost_multiplier;
}

int Consumable::getBoostAdder()
{
  return boost_adder;
}

bool Consumable::getIsPermanent()
{
  return isPermanent;
}

void Consumable::setTime(int time_)
{
  time = time_;
}

void Consumable::setBoostTarget(int boost_target_)
{
  boost_target = boost_target_;
}

void Consumable::setBoostMultiplier(double boost_multiplier_)
{
  boost_multiplier = boost_multiplier_;
}

void Consumable::setBoostAdder(int boost_adder_)
{
  boost_adder = boost_adder_;
}

void Consumable::setIsPermanent(bool isPermanent_)
{
  isPermanent = isPermanent_;
}

Consumable::Consumable(int time_, int boost_target_, double boost_multiplier_, int boost_adder_, bool isPermanent_, int price_, std::string name_, std::string description_)
{
  setPrice(price_);
  setName(name_);
  setDescription(description_);
  time = time_;
  boost_target = boost_target_;
  boost_multiplier = boost_multiplier_;
  boost_adder = boost_adder_;
  isPermanent = isPermanent_;
}

Consumable::Consumable(){}
