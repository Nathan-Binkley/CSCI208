#include<iostream>
using namespace std;

class enemy{
protected:
 int attackPower;
public:
  virtual void attack()
  {cout << "Whatever" << endl;} //virtual = anyone inherits from me MUST have this funciton
 void setAttackPower(int a)
 {attackPower = a;}

};

class ninja : public enemy {
private:

public:
  ninja()
  {
    attackPower = 29;
  }
  ninja(int a)
  {
    attackPower = a;
  }
  virtual void attack() // virtual not necessary except for user interpretation and clarity -- reminds user the function is virtual
 { cout << "I am a ninja with " << attackPower << " attack power" << endl; }
};

class monster : public enemy {
private:

public:
  monster()
  {
    attackPower = 21;
  }
  monster(int a)
  {
    attackPower = a;
  }
  virtual void attack() // virtual not necessary except for user interpretation and clarity -- reminds user the function is virtual
 { cout << "I am a monster with " << attackPower << " attack power" << endl; }
};

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
