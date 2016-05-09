#include <iostream>

#include "Heroe.h"
#include "Artefact.h"

using namespace std;

int main()
{
    Artefact WloczniaSmierci("Spear of Death", STRENGTH, 10);
    Artefact MieczPrzeznaczenia("Sword of Destiny", AGILITY, 100);
    Heroe leszek ("Lech",2,2,3);
    leszek.addArtefact(WloczniaSmierci);
    leszek.addArtefact(MieczPrzeznaczenia);
    leszek.printHeroe();
    return 0;
}
