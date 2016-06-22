/**
* \file ConsoleColor.h
* \author RPGteam
* \date 22.06.2016
* \version 1.0
* \brief File contains the definition of ConsoleColor class
*/
// -------------------------------------------------------------------------

#ifndef CONSOLE_COLOR_H
#define CONSOLE_COLOR_H

// -------------------------------------------------------------------------

#include <windows.h>

using namespace std;

// -------------------------------------------------------------------------

/**
* \class ConsoleColor
* \author RPGteam
* \date 22.06.2016
* \brief The definition of ConsoleColor class. This class is singleton used to color console
*/
class ConsoleColor
{
    HANDLE hConsole;
public:
    /// \brief The class constructor
    ConsoleColor();

    /// \brief Function to set color
    ///
    /// \param color - index of proper color
    void setColor(int color);
};

/** \brief Only one existing ConsoleColor object, used to change text color */
extern ConsoleColor color;

#endif
