// srm275.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class HingedDoor
{
public:
	int numSwings(int initialAngle, int reduction);
};

int HingedDoor::numSwings(int initialAngle, int reduction)
{
	float redAng = initialAngle;
	int cnt = 0;

	while (redAng > 5)
	{
		cnt += 1;
		redAng /= reduction;
		
	}
	return cnt;
}

int main()
{
	HingedDoor gd;

	int swin = gd.numSwings(50, 2);

	return 0;
}

