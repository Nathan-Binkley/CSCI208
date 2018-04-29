#include <iostream>
#include <string>
using namespace std;

const int MAXROWS=2;
const int MAXCOLS=3;

/*************************************************************************
 * Class: Matrix
 *

 *************************************************************************/
template <class t>
class Matrix
{
  private:
   t doubleArray[MAXROWS][MAXCOLS];
   int rows;
   int cols;

  public:
   //Constructor
   Matrix();  //Set rows to MAXROWS and cols to MAXCOLS
	      //Initialize all the values of doubleArray to zero

   //Getter Functions
   void printMatrix();

   //Setter Functions
   void setMatrix(t [MAXROWS][MAXCOLS]); //set the doubleArray to what is sent
   void addMatrix(t [MAXROWS][MAXCOLS]); //add an array to doubleArray
   void addMatrix(Matrix otherMatrix);

   //No destructor needed
};

/*************************************************************************
/* Class: Matrix
/* Function: Constructor  - Default
/*************************************************************************/
template <class t>
Matrix<t>::Matrix()
{
   rows = MAXROWS;
   cols = MAXCOLS;
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 doubleArray[i][j] = '\0';
      }
   }
}

/*************************************************************************
/* Class: Matrix
/* Function: printMatrix
/*   Make sure the output is readable. You can format it with setw
/*************************************************************************/
template <class t>
void Matrix<t>::printMatrix()
{
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 cout << doubleArray[i][j] << "   ";
      }
      cout << endl;
   }
}

/*************************************************************************
/* Class: Matrix
/* Function: setMatrix
/*************************************************************************/
template <class t>
void Matrix<t>::setMatrix(t otherArray[MAXROWS][MAXCOLS])
{
   for (int i=0; i< rows; i++)
   {
      for(int j=0; j< cols; j++)
      {
	 doubleArray[i][j] = otherArray[i][j];
      }
   }
}

/*************************************************************************
/* Class: Matrix
/* Member Function: addMatrix
/*   This  member function takes an array and adds it to the matrix
/*************************************************************************/
template <class t>
void Matrix<t>::addMatrix(t otherArray[MAXROWS][MAXCOLS])
{
   for (int i=0; i < rows; i++)
   {
      for(int j=0; j < cols; j++)
      {
	 doubleArray[i][j] += otherArray[i][j];
      }
   }
}

/*************************************************************************
/* Class: Matrix
/* Member Function: addMatrix
/*   This  member function takes a matrix and adds it to the matrix
/*   this is done by using the matrix data represented in the variable : doubleArray
/*************************************************************************/
template <class t>
void Matrix<t>::addMatrix(Matrix<t> otherMatrix)
{
   addMatrix(otherMatrix.doubleArray);
}




/*************************************************************************
/* Test Program
/* This program is already formatted for use of a template.
/*************************************************************************/

template <class t>
void demoTemplate(Matrix<t>& M, t array1[MAXROWS][MAXCOLS], t array2[MAXROWS][MAXCOLS]);

int main()
{
  Matrix<int> mat;
  int Num1[MAXROWS][MAXCOLS] =
     {
  {1,2,3},
  {4,5,6}
     };
  int Num2[MAXROWS][MAXCOLS] =
     {
  {6,5,4},
  {3,2,1}
     };
  demoTemplate(mat, Num1, Num2);

  Matrix<string> sat;
  string s1[MAXROWS][MAXCOLS] =
     {
  {"And","Jariel","is"},
  {"A","ok","Programmer"}
     };
  string s2[MAXROWS][MAXCOLS] =
     {
  {"Don't","Worry","Though"},
  {"Nathan","Can","Fix it"}
     };
  demoTemplate(sat, s1, s2);

  Matrix<float> bat;
  float f1[MAXROWS][MAXCOLS] =
     {
  {1.3,2.8,3.6},
  {4.9,5.6,6.4}
     };
  float f2[MAXROWS][MAXCOLS] =
     {
  {6.1,5.2,4.3},
  {3.4,2.5,1.6}
     };
  demoTemplate(bat, f1, f2);


    cout << "\n" << endl;
    return 0;
}

template <class t>
void demoTemplate(Matrix<t>& M, t array1[MAXROWS][MAXCOLS], t array2[MAXROWS][MAXCOLS])
{
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();

    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
