// srm608.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

class OneDimensionalRobotEasy
{
public:
	int finalPosition(string commands, int A, int B);
};

int OneDimensionalRobotEasy::finalPosition(string commands, int A, int B)
{
	int lbord = -A;
	int rbord = B;
	int pos = 0;

	for (int i = 0; i < commands.length(); ++i)
	{
		switch (commands[i])
		{
		case 'L':
			if (pos > lbord)
				pos -= 1;
			break;
		case 'R':
			if (pos < rbord)
				pos += 1;
			break;
		default:
			break;
		}
	}

	return pos;
}


int main()
{
	OneDimensionalRobotEasy oned;
	int pos = oned.finalPosition("", 0,15);
	return 0;
}

