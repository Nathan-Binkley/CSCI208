#include <iostream>
#include "Point23.h"

using namespace::std;

// default class constructor creates a 2-dimensional point with
// coordinates x = 0, y = 0.
Point23::Point23()
{
  size = 2;

  // allocate memory for an array of two integers
  dataPtr = new int [2];

  //initialize the coordinates to 0s:
  dataPtr[0] = 0;
  dataPtr[1] = 0;

}

// class constructor creates a 2-dimensional point with
// coordinates xval, yval.

Point23::Point23(int xval, int yval)
{
  size = 2;

  //allocate memory for an array of two integers
  dataPtr = new int [2];

  //initialize the coordinates to xval and yval
  dataPtr[0] = xval;
  dataPtr[1] = yval;

}

// class constructor creates a 3-dimensional point with
// coordinates xval, yval, and zval

Point23::Point23(int xval, int yval, int zval)
{
  size = 3;

  //allocate memory for an array of three integers
  dataPtr = new int [3];

  //initialize the coordinates to xval, yval, and zval
  dataPtr[0] = xval;
  dataPtr[1] = yval;
  dataPtr[2] = zval;

}

// class destructor deallocates all memory allocated for an object of the
// class
Point23::~Point23()
{
  //deallocate memory for the array of coordinates
  delete [] dataPtr;

}

int Point23::get_x() const
{
  // every point has an x coordinate
  return dataPtr[0];
}

int Point23::get_y() const
{
  // every point has a y coordinate
  return dataPtr[1];
}

int Point23::get_z() const
{
  // check if the point has a z coordinate:
  if (size == 3)
     return dataPtr[2];
  else {
     cerr << "attempt to return a third coordinate of a 2D point" << endl;
     return 1;
   }
}

int Point23::get_size() const
{
  // return the size of the point

  return size;
}

void Point23::set_x(int xval)
{
  dataPtr[0] = xval;
}

void Point23::set_y(int yval)
{
  dataPtr[1] = yval;
}

void Point23::set_z(int zval)
{
  // check if the point has a z coordinate:
  if (size == 3)
     dataPtr[2] = zval;
  else {
     cerr << "attempt to return a third coordinate of a 2D point" << endl;
     return ;
   }
}
