#include <iostream>

#include "Heroe.h"
#include "Artefact.h"
#include "Riddle.h"
#include "Start.h"
#include "Monster.h"
#include "Battle.h"

using namespace std;

int main()
{
    Start main_adventure;

    Artefact WloczniaSmierci("Spear of Death", STRENGTH, 1);
    Artefact MieczPrzeznaczenia("Sword of Destiny", AGILITY, 2);
    Heroe leszek ("Lech",2,2,3);

    main_adventure.play(leszek);

    leszek.addArtefact(WloczniaSmierci);
    leszek.addArtefact(MieczPrzeznaczenia);
    //leszek.printHeroe();

    //Riddle zagadka("Ta rzecz glebokie korzenie miewa, wyzsza jest nizli drzewa, ku niebu siega wyniosle, chociaz ni piedzi nie rosnie", "gora");

    //zagadka.play(leszek);

   // leszek.printHeroe();

    Monster orc_warrior(1, 2, 300, "Orc Warrior");

    Battle bitewka;

    bitewka.play(leszek, orc_warrior);



    return 0;
}
