/**
* \file WriteOut.h
* \author RPGteam
* \date 21.06.2016
* \version 1.0
* \brief File contains the definition of WriteOut class
*/
// -------------------------------------------------------------------------

#ifndef WRITEOUT_H
#define WRITEOUT_H

#include <iostream>

using namespace std;

/**
* \class WriteOut
* \author RPGteam
* \date 21.06.2016
* \brief WriteOut class provide ability of sequential text writing (letter after letter)
*
*   WriteOut can be used like mostly like cout (but accepts only strings, use to_string(any type) to convert)
*   to write text letter after letter with specified time delay (default is 30)
*   Class should be used by calling "write" global object. Eg. write<<"Hello"; or write.setSleepTime(60);
*/
class WriteOut
{
  int sleep_time = 30; ///< How much delay in miliseconds should program wait between printing letters

public:
  /// \brief Sleep time setter
  /// \param sleep_time_ - time to wait between letters in miliseconds
  void setSleepTime(int sleep_time_);

  /// \brief Function cout's text letter by letter with delay of sleep_time
  /// \param text - string to print letter by letter
  void write(string text);

  /// \brief Overload of << operator to make write look like cout
  /// \param output - object (probably global - write) that will write out input
  /// \param input - sentence to write out
  /// \return returns reference to object that writes out, so function can be used like write<<"smth"<<smth else";
  friend WriteOut &operator<<(WriteOut &output, const string input);
};

/** \brief Only one existing WriteOut object, used to write out text letter by letter */
extern WriteOut write;

#endif
