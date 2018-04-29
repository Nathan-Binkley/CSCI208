#ifndef marble_h
#define marble_h

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

class Marble
{
private:
  string color;

public:
  Marble();
  Marble(string newName);

  void setColor(string newColor);
  string getColor();
  string toString();
};

#endif
