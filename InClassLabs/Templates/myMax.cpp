/****************************************************
 *
 *  FileName:    ~/domanm2/maxTemplate.cpp
 *  Purpose:     Demonstrate the use of function templates
 *
 ********************************************************/
#include <iostream>
#include <string>
using namespace std;

//Make a template out of the prototype
//int myMax(int one, int two);
//float myMax(float one, float two);
//string myMax(string one, string two);
//char myMax(char one, char two);
template <class t>
t myMax(t one, t two);

int main()
{

   cout<< " TEMPLATE LAB - FUNCTIONS " << endl;
   int i_one = 3, i_two = 5;
   cout << endl << "Test 1:  int" << endl;
   cout << "The max of " << i_one << " and " << i_two << " is " << myMax<int>(i_one, i_two) << endl;

   //Include code to test your template on float and string types
   float f_one = 3.54, f_two = 3.6423;
   cout << endl << "Test 2:  float" << endl;

   cout << "The max of " << f_one << " and " << f_two << " is " << myMax<float>(f_one, f_two)<< endl;

   string s_one = "SomeBoDY", s_two = "Some Body";
   cout << endl << "Test 3:  string" << endl;

   cout << "The max of " << s_one << " and " << s_two << " is " << myMax<string>(s_one, s_two) << endl;

   char c_one = 'D', c_two = 'S';
   cout << endl << "Test 4:  char" << endl;

   cout << "The max of " << c_one << " and " << c_two << " is " << myMax<char>(c_one, c_two) << endl;

   return 0;
}


//Template prototype
template <class t>
t myMax(t one, t two)
{
   t bigger;
   if (one < two)
   {
      bigger = two;
   }
   else
   {
      bigger = one;
   }
   return bigger;
}

//Make a template out of this function. Don't forget the return type.
/*
int myMax(int one, int two)
{
   int bigger;
   if (one < two)
   {
      bigger = two;
   }
   else
   {
      bigger = one;
   }
   return bigger;
}
float myMax(float one, float two)
{
   float bigger;
   if (one < two)
   {
      bigger = two;
   }
   else
   {
      bigger = one;
   }
   return bigger;
}
string myMax(string one, string two)
{
   string bigger;
   if (one < two)
   {
      bigger = two;
   }
   else
   {
      bigger = one;
   }
   return bigger;
}
char myMax(char one, char two)
{
   char bigger;
   if (one < two)
   {
      bigger = two;
   }
   else
   {
      bigger = one;
   }
   return bigger;
}
*/
