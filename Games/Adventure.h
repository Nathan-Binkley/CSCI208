#ifndef Adventure_h
#define Adventure_h

#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;


//***************************************
// Class : Dice
// Input: none
// output: none
// Description: This class is for dice rolling
//*****************************************
class dice
{
public:

  int value;
  //***************************************
  // Function : roll
  // Input: none
  // output: random number between 1-100 inclusive
  // Description: Rolls a fake die
  //*****************************************
  int roll(){
    return (rand() % 100) + 1;
  }
  dice(){
    value = roll();
  }

};

//***************************************
// Class : Player
// Input: none
// output: none
// Description: This class is the parent
//           class to the player and enemies
//*****************************************

class player
{
private:
  string playerName;

protected:
  string weapon;  // The instructions say to make this private, but in order for
                  // children to set weapons, it's needed here
  int playerHealth = 0;
  int weaponStrength = 0;
  int accuracy = 0;
  int gold = 0;
  int level = 1;
  int experience = 0;
  int headDmg = 0;

public:
  //***************************************
  // Function : battleCry(int num)
  // Input: none
  // output: cout statement of various degrees
  //       depending on who is using it
  // Description: This virtual function states the
  //    "battle cry" of which ever child is
  //     calling it
  //*****************************************
  virtual int battleCry(int num){
    cout << "Let the Battle Begin" << endl;
  }

  player()
  {
    playerName = "Example Name";
    weapon = "Example Weapon";
    weaponStrength = 0;
    accuracy = 0;
    playerHealth = 100;
    level = 1;
    gold = 0;
    experience = 0;
    headDmg = 0;
  }
  //***************************************
  // Function : sayName()
  // Input: none
  // output: playerName of type String in current object
  // Description: This function presents the name
  //    of the player or object
  //*****************************************
  string sayName()
  {
    //cout << playerName << endl; //debugging
    return playerName;
  }

  //***************************************
  // Function : getWeapon
  // Input: none
  // output: weapon variable of type string
  // Description: This function presents the weapon
  //    variable on screen
  //*****************************************
  string getWeapon()
  {
    // cout << weapon << endl;
    //debugging
    return weapon;
  }

  //***************************************
  // Function : getHealth()
  // Input: none
  // output: playerHealth of type int
  // Description: This function presents the health
  //    of the player/enemy who calls it
  //*****************************************
  int getHealth()
  {
    //cout << playerHealth << endl;//debugging
    return playerHealth;
  }

  //***************************************
  // Function : getStrength()
  // Input: none
  // output: strength of type int
  // Description: This function presents the
  //    damage the child who calls it does
  //*****************************************
  int getStrength()
  {
    //cout << weaponStrength << endl; //debugging
    return weaponStrength;
  }

  //***************************************
  // Function : setName
  // Input: var of type string
  // output: none
  // Description: This function sets the name
  //    of an object to the input
  //*****************************************
  void setName(string name)
  {
    playerName = name;
  }

  //***************************************
  // Function : setWeapon
  // Input: var of type string
  // output: none
  // Description: This function sets the weapon
  //    of an object to the input
  //*****************************************
  void setWeapon(string weapons)
  {
    weapon = weapons;
  }

  //***************************************
  // Function : setHealth
  // Input: number of type int
  // output: none
  // Description: This function sets the health
  //    of an object to the input
  //*****************************************
  void setHealth(int num)
  {
    playerHealth = num;
  }

  //***************************************
  // Function : setStrength
  // Input: number of type int
  // output: none
  // Description: This function sets the strength/damage
  //    of an object to the input
  //*****************************************
  void setStrength(int num)
  {
    weaponStrength = num;
  }
  //***************************************
  // Function : getGold
  // Input: none
  // output: gold of type int
  // Description: returns amount of gold on player object
  //
  //*****************************************

  int getGold()
  {
    return gold;
  }
  //***************************************
  // Function : setGold
  // Input: number of type int
  // output: none
  // Description: sets gold to input for select
  //            player object
  //*****************************************
  void setGold(int num)
  {
    gold = num;
  }
  //***************************************
  // Function : getAccuracy
  // Input: none
  // output: accuracy of type int
  // Description: returns the accuracy of the player object
  //
  //*****************************************
  int getAccuracy()
  {
    return accuracy;
  }
  //***************************************
  // Function : setAccuracy
  // Input: num of type int
  // output: none
  // Description: sets accuracy of player object
  //                    to the input
  //*****************************************
  void setAccuracy(int num)
  {
    accuracy = num;
  }
  //***************************************
  // Function : setLevel
  // Input: number of type int
  // output: none
  // Description: sets level of player object to the input
  //
  //*****************************************
  void setLevel(int num)
  {
    level = num;
  }
  //***************************************
  // Function : getLevel
  // Input: none
  // output: level of type int
  // Description: returns the level of the player object
  //
  //*****************************************
  int getLevel()
  {
    return level;
  }
  //***************************************
  // Function : battle
  // Input: player pointers A and B, int values aNum and bNum
  // output: number determining the results of a battle
  // Description: using the output from battleCry and the input of aNum and bNum
  //          determines who did damage in the battle as well as sending it to the
  //          logic section in menu.cpp
  //
  //*****************************************
  static int battle(player* a, player* b, int aNum, int bNum)
  {
    int x = a->battleCry(aNum); // goes to battle cry to get hit or miss
    int y = b->battleCry(bNum);

    cout << "Player hit: " << x << " Enemy hit: " << y << endl;

    if(x > y) // b takes damage but a does not
    {
      return 1;
    }
    else if (x < y) // a takes damage but B does not
    {
      return 2;
    }
    else if (x == y && x == 1) // both hit
    {
      return 3;
    }
    else if (x == y && x == 0) // both miss
    {
      return 4;
    }
    else
    {
      cout << "Something went wrong" << endl; // should never happen
      return 5;
    }

  }
  //***************************************
  // Function :getHeadDmg
  // Input: none
  // output:  headDmg of type int
  // Description: returns the amount of damage the head does
  //          on a specific player object
  //*****************************************
  int getHeadDmg() // gets head damage as return value for a string
  {
    return headDmg;
  }

};

//***************************************
// Class : Player
// Input: none
// output: none
// Description: This child class, derived from
//    player, initializes a new object of type hero
//*****************************************
class hero: public player
{
public:
  hero()
  {
    weapon = "Wooden Sword";
    weaponStrength = 6;
    playerHealth = 12;
    gold = 100;
    accuracy = 70;
    experience = 0;
    headDmg = 0;
    level = 1;
  }

  int battleCry(int num) { // gets accuracy
    cout << "I smite you with my mighty sword!" << endl;
    if(num > accuracy)
    {
      cout << "... But it missed!" << endl;
      return 0; // miss
    }
    return 1; // hit
  }

  //***************************************
  // Function : motto
  // Input: none
  // output: none
  // Description: This function presents motto
  //    of the hero in game.
  //*****************************************
  void motto()
  {
    cout << "My motto is Neigh, like a horse" << endl;
  }

};

//***************************************
// Class : troll
// Input: none
// output: none
// Description: This class is derived from class player
//*****************************************
class troll: public player
{
public:
  troll()
  {
    playerHealth = 3;
    weapon = "Club";
    weaponStrength = 1;
    accuracy = 30;
    experience = 10;
    gold = 20;
    level = 1;
    headDmg = 2;
  }

  int battleCry(int num) // get hit or not
  {
    cout << "Bwahhhhhh" << endl;

    if(num > accuracy)
    {
      cout << "... But it missed!" << endl;
      return 0; // miss
    }
    return 1; // hit
  }
};

//***************************************
// Class : dragon
// Input: none
// output: none
// Description: This class is derived from class player
//*****************************************
class dragon: public player
{
public:
  dragon()
  {
    playerHealth = 4;
    weapon = "Fire Breath";
    weaponStrength = 3;
    accuracy = 90;
    experience = 50;
    gold = 90;
    level = 1;
    headDmg = 4;
  }

  int battleCry(int num) // get hit or not
  {
    cout << "Dragon is breathing fire" << endl;
    if(num > accuracy)
    {
      cout << "... But it missed!" << endl;
      return 1; // hit
    }
    return 0; // miss
  }
};

//***************************************
// Class : nightKing
// Input: none
// output: none
// Description: This class is derived from class player
//*****************************************
class nightKing: public player
{
public:
  nightKing()
  {
    playerHealth = 6;
    weapon = "Club";
    weaponStrength = 5;
    accuracy = 80;
    experience = 100;
    gold = 200;
    level = 1;
    headDmg = 7;
  }

  int battleCry(int num) // get hit or not
  {
    cout << "The Night King attacks" << endl;
    if(num > accuracy)
    {
      cout << "... But it missed!" << endl;
      return 0; // miss
    }
    return 1; // hit
  }
};

class newell : public player
{
public:
  newell()
  {
    level = 1;
    playerHealth = 20;
    weapon = "Sales";
    weaponStrength = 2;
    accuracy = 90;
    experience = 200;
    gold = 300 + (rand() % 200);
    headDmg = 10;
  }

  int battleCry(int num) // get accuracy or not
  {
    cout << "Gabe Newell attacks you with his Summer Sale" << endl;
    if(num > accuracy)
    {
      cout << "... But it missed!" << endl;
      return 0; // miss
    }
    return 1; // hit
  }
};

#endif
/*
int main()
{

  ninja n1;
  monster m1;
  enemy* enemy1 = &n1;
  enemy* enemy2 = &m1;
  m1.attack();
  n1.attack();

  n1.setAttackPower(60);
  m1.setAttackPower(65);
  m1.attack();
  n1.attack();
  enemy1->setAttackPower(20);
  enemy2->setAttackPower(32);
  n1.attack();
  m1.attack();
  enemy1->attack();// calls from enemy class
  enemy2->attack();
}
*/
