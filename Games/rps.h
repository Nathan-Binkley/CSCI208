#ifndef rps_h
#define rps_h

#include <iostream>
#include <string>
using namespace std;

class tool
{
protected:
  string type;
public:
  // Method: getType()
  // Objective: Returns type of object as a string
  string getType()
  {
    return type;
  }

  //Constructor
  tool()
  {
    type = " ";
    //cout << "Tool constructor " <<endl; //debugging
  }

  //Method: fight()
  //Input: tool pointer of name thing
  //Output: int to declare who won
  //Other Comments: Virtual so is necessary
  //  in other functions that inherit class tool
  virtual int fight(tool* thing) = 0;
};

//Classes: rock, paper, scissors
//Inheritance: Yes. Class tool
//Methods: Constructor and fight
//Other
class rock : public tool
{
public:
  rock()
  {
    type = "rock";
    //cout << "Rock Constructor " << endl; // debugging
  }
  int fight(tool* thing)
  {
    if(thing->getType() == "paper")
      return 2; // AI won
    else if(thing->getType() == "scissors")
      return 1; // This object won
    else if(thing->getType() == "rock")
      return 0; // tie
    else
      cout << "Invalid input, something went wrong 001 - R" << endl; // debugging
    return 999;
  }
};

class paper : public tool
{
public:
  paper()
  {
    type = "paper";
    //cout << "paper Constructor " << endl; // debugging
  }
  int fight(tool* thing)
  {
    if(thing->getType() == "paper")
      return 0; // tie
    else if(thing->getType() == "scissors")
      return 2; // AI won
    else if(thing->getType() == "rock")
      return 1; // This object won
    else
      cout << "Invalid input, something went wrong 002 - P" << endl;
    return 999;
  }
};


class scissors : public tool
{
public:
  scissors()
  {
    type = "scissors";
    //cout << "scissors Constructor " << endl; // debugging
  }
  int fight(tool* thing)
  {
    if(thing->getType() == "paper")
      return 1; // This object won
    else if(thing->getType() == "scissors")
      return 0; // tie
    else if(thing->getType() == "rock")
      return 2; // AI won
    else
      cout << "Invalid input, something went wrong 003 - S" << endl;
    return 999;
  }
};


#endif
