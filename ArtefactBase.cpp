#include "ArtefactBase.h"
#include "AskPlayer.h"

using namespace std;

ArtefactBase::ArtefactBase()
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

Artefact ArtefactBase::getArtefact(int index)
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

void ArtefactBase::popArtefact(int index)
{
    if((index>=base.size())||(index<0))
    {
        return;
    }
    else
    {
        base.erase(base.begin() + index);
    }
}

void ArtefactBase::pushArtefact(Artefact to_push)
{
    base.push_back(to_push);
}

int ArtefactBase::getSize()
{
    return base.size();
}

ArtefactBase BaseOfArtefacts;
