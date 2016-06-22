#include "ConsoleColor.h"
#include <windows.h>

ConsoleColor::ConsoleColor()
{
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 7);
}

void ConsoleColor::setColor(int color)
{
  SetConsoleTextAttribute(hConsole, color);
}

ConsoleColor color;
