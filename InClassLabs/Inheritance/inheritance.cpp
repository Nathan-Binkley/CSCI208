/************
 Copyright: Department of Computer Science, University of Regina.
   File name: overriding.cpp
   Purpose:   Demonstrate a gotcha with overriding

   Overriding is not the same as overloading.
   When you override one member function you hide
   all other overloaded member functions of that name
   that should be inherited from the parent class.

   As provided this program should not compile.
   Comment out the call to the hidden setX(string)
   member function to compile and run.
**************/

#include <iostream>
#include <cmath>
using namespace std;

class twoD
{
   protected:
   	double x, y; // x and y  coordinates
   public:

        // inline implementation of constructor
        twoD():x(3),y(2){
          cout << " Comment from within the twoD default constructor" << endl;
        }
	      twoD(double i, double j):x(i), y(j){
          cout << " Comment from within the twoD parametrized constructor" << endl;
        }

	// inline implementation of member functions
        void setX(string bad)
             {cout << "Strings are not valid 3D parameters"
                   << endl;}

	void setX(double NewX){x = NewX;}
	void setY(double NewY){y = NewY;}
	double getX() const {return x;}
	double getY() const {return y;}
};


class threeD:public twoD
{
   private:
        double z;
   public:

        // Inline implemenation of constructor.
	// Constructor of the base class is not inherited.
	// The following constructor of threeD class reuses the
	// constructor of the twoD class and the only way values
	// can be passed to the twoD constructor is via the use
	// of a member initialization list.
         threeD():twoD(8,7){z=0; cout << 	" Comment from within the threeD default constructor" << endl;}
	       threeD(double i, double j, double k):twoD(i,j){z = k; cout << 	" Comment from within the threeD parametrized constructor " << endl; }

	       void setZ(double NewZ){z = NewZ;}
	       double getZ() {return z;}
};

int main()
{
  twoD Obj1;
  cout << " End Obj 1" << endl;
	twoD Obj2(1, 1);
  cout << " End Obj 2" << endl;
  threeD Obj3;
  cout << " End Obj 3" << endl;
	threeD Obj4(1, 2, 3);
  cout << " End Obj 4" << endl;

  cout << "Coordinates for the 2d object are: " << endl;
	cout << Obj1.getX() << ", " << Obj1.getY() << endl;

  cout << "Coordinates for the 2d object are: " << endl;
  cout << Obj2.getX() << ", " << Obj2.getY() << endl;

  cout << "Coordinates for the 3d object are: " << endl;
  cout << Obj3.getX() << ", " << Obj3.getY() << ", " << Obj3.getZ() << endl;

  cout << "Coordinates for the 3d object are: " << endl;
	cout << Obj4.getX() << ", " << Obj4.getY() << ", " << Obj4.getZ() << endl;

  Obj2.setX("foo");
	Obj3.setX(2);
  Obj3.setY(3);
  Obj3.setZ(1);
  cout << "The distance between obj3 and obj4: " << sqrt(pow(Obj3.getX()-Obj4.getX(),2)+pow(Obj3.getY()-Obj4.getY(),2)+pow(Obj3.getZ()-Obj4.getZ(),2)) << endl;


	return 0;
}
