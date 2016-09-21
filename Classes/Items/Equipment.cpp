#include "Equipment.h"

int Equipment::getRequiredStrength()
{
    return requiredStrength;
}

int Equipment::getRequiredAgility()
{
    return requiredAgility;
}

Equipment::Equipment(int requiredStrength_, int requiredAgility_, int boost_targets_[3], double boost_multiplier_[3], int boost_adder_[3], int price_, std::string name_, std::string description_)
{
  requiredStrength = requiredStrength_;
  requiredAgility = requiredAgility_;
  boost_targets = new int[3];
  boost_multiplier = new double[3];
  boost_adder = new int[3];
  for(int i=0; i<3 ;++i)
  {
    boost_targets[i] = boost_targets_[i];
    boost_multiplier[i] = boost_multiplier_[i];
    boost_adder[i] = boost_adder_[i];
  }
  setPrice(price_);
  setName(name_);
  setDescription(description_);
}

Equipment::Equipment(){}

int Equipment::getBoostTarget(int which)
{
  return boost_targets[which];
}

int* Equipment::getBoostTargets()
{
  return boost_targets;
}

double Equipment::getBoostMultiplier(int which)
{
  return boost_multiplier[which];
}

double* Equipment::getBoostMultipliers()
{
  return boost_multiplier;
}

int Equipment::getBoostAdder(int which)
{
  return boost_adder[which];
}

int* Equipment::getBoostAdders()
{
  boost_adder;
}
