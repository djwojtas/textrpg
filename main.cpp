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

  main_adventure.play(main_character);


  return 0;
}
