#include <iostream>
#include <ctime>

#include "Classes/Characters/Heroe.h"
#include "Classes/Items/Artefact.h"
#include "Classes/GameSteps/MainGameSteps/Riddle.h"
#include "Classes/GameSteps/MainGameSteps/Start.h"
#include "Classes/Characters/Monster.h"
#include "Classes/GameSteps/MainGameSteps/Battle.h"
#include "Classes/GameSteps/MainGameSteps/Travel.h"
#include "Classes/API/WriteOut.h"
#include "Classes/API/ConsoleColor.h"

#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));

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
