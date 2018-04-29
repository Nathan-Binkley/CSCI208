#include "header.h"
using namespace std;
void nice_print()
{
	int indent, cnt;
	for(cnt=1;cnt<=5;cnt++)
	{
		for(indent=0; indent<cnt; indent++)
			cout << "\t";
		cout<<"hello\n";
	}

}
