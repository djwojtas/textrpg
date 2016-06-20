/**
* \file ArtefactBase.h
* \author RPGteam
* \date 18.06.2016
* \version 1.0
* \brief File contains the definition of ArtefactBase class
*/
// -------------------------------------------------------------------------

#ifndef ARTEFACT_BASE_H
#define ARTEFACT_BASE_H

// -------------------------------------------------------------------------

#include "Artefact.h"
#include <vector>

using namespace std;

// -------------------------------------------------------------------------

/**
* \class ArtefactBase
* \author RPGteam
* \date 18.06.2016
* \brief The definition of ArtefactBase class. This class is singleton used to store different artefacts from game universe
*/
class ArtefactBase
{
    vector<Artefact> base; ///< Vector, that contains all the artefacts from the Game Universe
public:
    /// \brief The class constructor, in which different artefacts are pushed to the vector
    ArtefactBase()
    {
        //Strength
        Artefact s_first("Centaur's Axe", STRENGTH, 2);
        Artefact s_second("Sword of Hellfire", STRENGTH, 4);
        Artefact s_third("Titan's Gladius", STRENGTH, 8);

        //Agility
        Artefact a_first("Boots of Speed", AGILITY, 2);
        Artefact a_second("Cape of Velocity", AGILITY, 4);
        Artefact a_third("Angel Wings", AGILITY, 8);

        //HP
        Artefact hp_first("Ring of Vitality", HP, 2);
        Artefact hp_second("Vial of Lifeblood", HP, 4);
        Artefact hp_third("Necklace of Dragonteeth", HP, 8);

        base.push_back(s_first);
        base.push_back(a_first);
        base.push_back(hp_first);

        base.push_back(s_second);
        base.push_back(a_second);
        base.push_back(hp_second);

        base.push_back(s_third);
        base.push_back(a_third);
        base.push_back(hp_third);
    }

    /// \brief Function which allows to "pull out" some artefact from the base
    ///
    /// \param index - index of artefact in vector (base)
    /// \return some artefact from the base
    Artefact getArtefact(int index)
    {
        if(index>base.size())
        {
            return base[0];
        }
        else
        {
            return base[index];
        }
    }

    /// \brief Function which returns size of our Artefact base
    ///
    /// \return Amount of artefacts in our base
    int getSize()
    {
        return base.size();
    }

} BaseOfArtefacts;

#endif
