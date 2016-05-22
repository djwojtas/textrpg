#include <iostream>

#include "Heroe.h"
#include "Artefact.h"
#include "Riddle.h"
#include "Start.h"
#include "Monster.h"
#include "Battle.h"
#include "Travel.h"

#include <vector>

using namespace std;

int main()
{
    vector<Riddle> Riddles;
    Start main_adventure;

    Artefact WloczniaSmierci("Spear of Death", STRENGTH, 1);
    Artefact MieczPrzeznaczenia("Sword of Destiny", AGILITY, 2);
    Heroe leszek ("Lech",2,2,3);

    main_adventure.play(leszek);

    leszek.addArtefact(WloczniaSmierci);
    leszek.addArtefact(MieczPrzeznaczenia);

    Monster orc_warrior(1, 2, 300, "Orc Warrior");

    /*Battle bitewka;

    bitewka.play(leszek, orc_warrior);

    bitewka.getNext()->play(leszek);*/

    Travel podroz;

    podroz.play(leszek);

    podroz.getNext()->play(leszek);

    return 0;
}
