#include <iostream>
#include "date.h"
using namespace std;
// This program implements and tests a Date class that
// stores dates and displays them in various formats.

/*********************************************************
 *                    Date::Date                         *
 * This default constructor  sets date to Jan. 1, 2001.  *
 *********************************************************/
Date::Date()
{
	month = day = 1;
	year  = 2001;
	setName();
}

/**************************************************************
 *                         Date::Date                         *
 * This overloaded constructor calls the class "set" function *
 * to set the date to the month/day/year passed to it.        *
 **************************************************************/
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

/***************************************************************
 *                       Date::setMonth                        *
 * This member function validates that the month number        *
 * passed in is 1-12 and, if so, sets the month to that number.*
 * Otherwise a default value of 1 is used.                     *
 ***************************************************************/
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
	{	cout << m << " is not a valid value for the month.\n"
	              << "Using a default value of 1 (January). \n";
		month = 1;
	}
	setName();
}

/********************************************************
 *                 Date::setDay                         *
 * This member function validates that the day number   *
 * passed in is valid for the selected month. If so,    *
 * it sets the day to that number. Otherwise, a default *
 * value of 1 is used.                                  *
 ********************************************************/
void Date::setDay(int d)
{
	int daysInMonth;

	switch (month)
	{
		case 4: case 6: case 9: case 11:  // Apr., June, Sept. & Nov.
			daysInMonth = 30;
		    break;
		case 2:                           // Feb.
			daysInMonth = 29;             // Usually 28, but 29 is the max
			break;
		default:
			daysInMonth = 31;             // The rest of the months
	}

	if (d >= 1 && d <= daysInMonth)
		day = d;
	else
	{	cout << d << " is not a valid day in " << name <<". \n"
		          << "Using a default value of 1). \n";
		day = 1;
	}
}

/***************************************************************
 *                        Date::setYear                        *
 * This member function validates that the year number passed  *
 * in is valid, if so, it sets the year to that number.        *
 * Otherwise, a default value of 2001 is used.                 *
 * NOTE: The programming specs did not specify which dates     *
 *       were valid.                                           *
 ***************************************************************/
void Date::setYear(int y)
{
	if (y >= -1900 && y <= 4000)
		year = y;
	else
	{
		cout << y << " is not a valid value for the year.\n"
		          << "Using a default value of 2001. \n";
		year = 2001;   // Use default value
   }
}

/*********************************************************
 *                     Date::setName                     *
 * This member function sets the month name to match the *
 * month number.                                         *
 *********************************************************/
void Date::setName()
{
	switch (month)
	{
		case  1: name = "January";  break;
		case  2: name = "Febraury"; break;
		case  3: name = "March";    break;
		case  4: name = "April";    break;
		case  5: name = "May";      break;
		case  6: name = "June";     break;
		case  7: name = "July";     break;
		case  8: name = "August";   break;
		case  9: name = "September";break;
		case 10: name = "October";  break;
		case 11: name = "November"; break;
		case 12: name = "December";
	}
}
/*************************************************************
 *                        Date::getYear                      *
 *             This member function gets the year            *
 *************************************************************/
int Date::getYear(){
	return year;
}
/*************************************************************
 *                        Date::showDate1                    *
 * This member function displays the date in 3/15/13 format. *
 *************************************************************/
void Date::showDate1()
{
   int twoDigitYear;

   if (year >= 2000)
      twoDigitYear = year - 2000;
   else
      twoDigitYear = year - 1900;

	cout << month << '/' << day << '/' ;

	if (twoDigitYear < 10)
		cout << '0';
	cout << twoDigitYear << endl;
}

/********************************************************************
 *                          Date::showDate2                         *
 * This member function displays the date in March 15, 2013 format. *
 ********************************************************************/
void Date::showDate2()
{
	cout << name << " " << day << ", " << year << endl;
}

/********************************************************************
 *                          Date::showDate3                         *
 * This member function displays the date in 15 March 2013 format.  *
 ********************************************************************/
void Date::showDate3()
{
	cout << day << " " << name << " " << year << endl;
}

/********************************************************************
 *                          ostream& operator<<                     *
 * 									 	Overloads print date operator               	*
 ********************************************************************/
ostream& operator<<(ostream& os, const Date& dat)
{
	os << dat.month << '/' << dat.day << '/' << dat.year;
	return os;
}

Date operator+(int num, Date dt){
	Date tempD = dt;
	tempD.setYear(tempD.getYear() + num);
	return tempD;
}

Date operator+(Date dt, int num){
	Date tempD = dt;
	tempD.setYear(tempD.getYear() + num);
	return tempD;
}

Date& operator++(Date& dt){
	Date& tempD = dt;
	tempD.setYear(dt.getYear() + 1);
	return tempD;
}

Date& operator++(Date& dt, int x){
	Date& tempD = dt;
	x = dt.getYear();
	tempD.setYear(x + 1);
	return tempD;
}

/********************************************************************
 *                          Main                                    *
 * 										  Displays date															  *
 ********************************************************************/
int main()
{
	Date date3, date4, date1, date2;
			date3=date1+82;
			cout << date3;
			cout << endl;

			date4=6+date2;
			cout << date4;
			cout << endl;

			cout << date3 << endl; //2083
      date3++;
			cout << date3 << endl; //2084
      ++date3;
			cout << date3 << endl; //2085
}
