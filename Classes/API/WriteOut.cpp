#include "WriteOut.h"
#include "windows.h"

using namespace std;

void WriteOut::setSleepTime(int sleep_time_)
{
  sleep_time = sleep_time_;
}

void WriteOut::write(string text)
{
  for(int i=0; i<text.size(); ++i)
  {
    cout<<text[i];
    Sleep(sleep_time);
  }
}

WriteOut &operator<<(WriteOut &output, const string input)
{
       output.write(input);
       return output;
}

WriteOut write;
