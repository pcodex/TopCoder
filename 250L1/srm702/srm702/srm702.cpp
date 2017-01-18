// srm702.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;


class TestTaking
{
public:
	int findMax(int questions, int guessed, int actual);
};

int TestTaking::findMax(int questions, int guessed, int actual)
{
	int gt = guessed;
	int gf = questions - gt;
	int actf = questions - actual;

	int corrt = min(actual, gt);
	int corrf = min(actf, gf);

	return corrt + corrf;
}

int main()
{
	TestTaking ttk;

	int anmax = ttk.findMax(7, 0, 2);
	return 0;
}

