#include "Util.h"

void checkN(int n)
{
	if (n <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}

void checkInput(int input, int n)
{
	if (input <= 0 || input > n)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}