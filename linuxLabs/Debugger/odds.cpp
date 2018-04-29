#include <iostream>
//using namespace std;

int SumOfOdds( int N );

int main()
{
        int N = 10;
        int sum = SumOfOdds( N );

        cout << "The sum of the first "
                << N << " odd numbers is "
                << sum << "." << endl;

        return( 0 );
}


// Returns the sum of the first N odd
// numbers.

int SumOfOdds( int N )
{
        int odd = 1;
        int sum = 0;

        while( N > 0 )
        {
                sum = sum + odd;
                odd = odd + 2;
                N--;
        }

        return( sum );
}
