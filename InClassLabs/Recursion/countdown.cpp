#include <iostream>
#include <string>
using namespace std;

void Reverse(string a){
// Base

if(a.size() == 1)
{
  cout << a << endl;
}
// General
else{
  cout << a[a.size()-1];
  string b = a.substr(0,a.size()-1);
  Reverse(b);

}
}

int Min(int in[], int end, int start = 0) //start position and end position
{
  int newmin = in[end];
  if(start == end)
  {
    return in[start];
  }

  else
  {
    newmin = Min(in, end-1);
    if(in[end] > newmin)
      return newmin;
    else
      return in[end];

  }
}

int power(int n, int p)
{
int number;
//Base Case
  if(p==0)
    return 1;
  if(p==1)
   return n;
  else
  {
    return n*power(n,p-1);
  }
}

int main()
{
  int f[]={2,15,6,33,23,8,1,17,43,2,5,3414,513,654,1};
  string a = "I DONT KNOW";
  cout << power(4, 2) << endl;
  Reverse(a);
  cout << Min(f,13) << endl;


  return 0;
}
