#ifndef WRITEOUT_H
#define WRITEOUT_H

#include <iostream>

using namespace std;

class WriteOut
{
  int sleep_time = 30;

public:
  void setSleepTime(int sleep_time_);

  void write(string text);

  friend WriteOut &operator<<(WriteOut &output, const string input);
};

extern WriteOut write;

#endif
