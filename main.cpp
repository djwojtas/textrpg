#include <iostream>

#include "Heroe.h"
#include "Artefact.h"
#include "Riddle.h"
#include "Start.h"

using namespace std;

int main()
{
    Start main_adventure;

    Artefact WloczniaSmierci("Spear of Death", STRENGTH, 10);
    Artefact MieczPrzeznaczenia("Sword of Destiny", AGILITY, 100);
    Heroe leszek ("Lech",2,2,3);

    main_adventure.play(leszek);

    leszek.addArtefact(WloczniaSmierci);
    leszek.addArtefact(MieczPrzeznaczenia);
    //leszek.printHeroe();

    Riddle zagadka("Ta rzecz glebokie korzenie miewa, wyzsza jest nizli drzewa, ku niebu siega wyniosle, chociaz ni piedzi nie rosnie", "gora");

    zagadka.play(leszek);

    leszek.printHeroe();

    return 0;
}
