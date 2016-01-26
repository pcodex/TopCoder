// srm540.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class RandomColoringDiv2
{
public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2);
};

int RandomColoringDiv2::getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
{
	if (d1 == 0)
		d1 = 1;
	
	
	int begR = startR;
	while (begR >= 0)
	{
		if (abs(begR - startR) <= d2)
			begR -= d1;
		else
			break;
	}

	int endR = startR;
	while (endR <= maxR)
	{
		if (abs(endR - startR) <= d2)
			endR += d1;
		else
			break;
	}

}

int main()
{
	return 0;
}

