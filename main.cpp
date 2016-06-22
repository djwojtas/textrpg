#include <iostream>

#include "Heroe.h"
#include "Artefact.h"
#include "Riddle.h"
#include "Start.h"
#include "Monster.h"
#include "Battle.h"
#include "Travel.h"
#include "WriteOut.h"

#include <vector>

using namespace std;

int main()
{
    Heroe main_character;
    Start main_adventure;
    GameStep* current_state = &main_adventure;

    while(true)
    {
        if(main_character.getRuneCount()>=7) { write<<"Congratulations! You have succeeded!"; break; }
        current_state->play(main_character);
        current_state=current_state->getNext();
    }

    return 0;
}
