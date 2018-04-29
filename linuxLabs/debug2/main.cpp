#include <iostream>
#include "Point23.h"

using namespace::std;

// main: testing the class Point23

int main()
{
// declaring two points:
   Point23 p1; 		// default: 2D point with coordinates 0, 0
   Point23 p2(5, 6);    // 2D point with coordinates 5, 6

   int x1, y1, x2, y2;  // declaring integers to store coordinates

   // printing p1, p2:
   cout << "After declaration: " << endl;

   // storing coordinates of p1 in x1, y1. Storing coordinates in separate
   // variables (rather than calling the get methods inside cout) is done
   // convenience of debugging.
   x1 = p1.get_x();
   y1 = p1.get_y();
   cout << "point p1: " << endl;
   cout << "x = " << x1 << " y = " << y1 << endl;

   x2 = p2.get_x();
   y2 = p2.get_y();
   cout << "point p2: " << endl;
   cout << "x = " << x2 << " y = " << y2 << endl;

   // make p1 equal to p2:
   p1 = p2;

   // printing p1, p2:
   cout << "After the assignment: " << endl;
   x1 = p1.get_x();
   y1 = p1.get_y();
   cout << "point p1: " << endl;
   cout << "x = " << x1 << " y = " << y1 << endl;

   x2 = p2.get_x();
   y2 = p2.get_y();
   cout << "point p2: " << endl;
   cout << "x = " << x2 << " y = " << y2 << endl;

   // changing x coordinate of p1 to 7:
   p1.set_x(7);
   // changing y coordinate of p1 to 10:
   p1.set_y(10);

   // printing p1, p2:
   cout << "After changing coordinates of p1 to (7, 10) " << endl;
   x1 = p1.get_x();
   y1 = p1.get_y();
   cout << "point p1: " << endl;
   cout << "x = " << x1 << " y = " << y1 << endl;

   x2 = p2.get_x();
   y2 = p2.get_y();
   cout << "point p2: " << endl;
   cout << "x = " << x2 << " y = " << y2 << endl;

   cout << "Coordinates of p2 have changed, too! Why?" << endl;


   return 0;
}
