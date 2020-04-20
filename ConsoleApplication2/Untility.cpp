#include "Untility.h"
#include <iostream>

using std::cout;
using std::endl;

bool IsPrime(int x)
{
	bool prime = true;
	for (int i = 2; i < x/i; i++)
	{
		int factor = x / i;
		if (factor*i == x)
		{
			cout << "factor found: " << factor << endl;
			prime = false;
			break;	
		}
	}
	return prime;
}