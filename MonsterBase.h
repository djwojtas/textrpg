/**
* \file MonsterBase.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of MonsterBase class
*/
// -------------------------------------------------------------------------

#ifndef MONSTER_BASE_H
#define MONSTER_BASE_H

// -------------------------------------------------------------------------

#include "Monster.h"
#include <vector>

using namespace std;

// -------------------------------------------------------------------------

/**
* \class MonsterBase
* \author RPGteam
* \date 21.06.2016
* \brief The definition of MonsterBase class. This class is singleton used to store different monsters from game universe
*/
class MonsterBase
{
    vector<Monster> base; ///< Vector, that contains all the Monsters from the Game Universe
public:
    /// \brief The class constructor, in which different Monster are pushed to the vector
    MonsterBase();

    /// \brief Function which allows to "pull out" some Monsters from the base
    ///
    /// \param index - index of Monster in vector (base)
    /// \return some Monster from the base
    Monster getMonster(int index);

    /// \brief Function which returns size of our Monster base
    ///
    /// \return Amount of Monsters in our base
    int getSize();

};

/** \brief Only one existing MonsterBase object, used to store Monsters */
extern MonsterBase BaseOfMonsters;

#endif
