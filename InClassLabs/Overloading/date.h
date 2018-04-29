#ifndef _DATE_H
#define _DATE_H
// This program implements and tests a Date class that
// stores dates and displays them in various formats.
#include <iostream>
#include <string>
using namespace std;

class Date
{
  private:
	int month;        // Holds the month number
	int day;          // Holds the day
	int year;         // Holds the 4 digit year
	string name;      // Holds the month name

	void setName();   // Private mutator sets month name

  public:
	// Constructors
	Date();
	Date(int m, int d, int y);

	// Mutators that set member data values
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	// Accessors that use member data to display dates
	void showDate1();
	void showDate2();
	void showDate3();

  //also a getter function because there wasNT ONE
  int getYear();

  //Amigos
  friend ostream& operator<<(ostream& os, const Date& dt);
  friend Date operator+(int num, Date dt);
  friend Date operator+(Date dt, int num);
  friend Date& operator++(Date& dt);
  friend Date& operator++(Date& dt, int);

};


#endif
