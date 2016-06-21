#ifndef ASKPLAYER_H
#define ASKPLAYER_H

using namespace std;

class AskPlayer
{
  int state = 0;
public:
  void setState(int state_);

  void playerSay(string message);

  void say(string message);

  void narrate(string message);

  int askForInt(string message, string fail_message, int minimum, int maximum);

  double askForDouble(string message, string fail_message, double minimum, double maximum);

  string askForString(string message, string fail_message);
};

extern AskPlayer ask;

#endif
