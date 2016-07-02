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

#include "../Items/Artefact.h"
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
    ArtefactBase();

    /// \brief Function which allows to "pull out" some artefact from the base
    ///
    /// \param index - index of artefact in vector (base)
    /// \return some artefact from the base
    Artefact getArtefact(int index);

    /// \brief Function which allows to "delete" some artefact from the base
    ///
    /// \param index - index of artefact, which will be deleted
    void popArtefact(int index);

    /// \brief Function which allows to add some artefact to the base
    ///
    /// \param to_push - Artefact, which will be stored in base
    void pushArtefact(Artefact to_push);

    /// \brief Function which returns size of our Artefact base
    ///
    /// \return Amount of artefacts in our base
    int getSize();

};

/** \brief Only one existing ArtefactBase object, used to store Artefacts */
extern ArtefactBase BaseOfArtefacts;

#endif
