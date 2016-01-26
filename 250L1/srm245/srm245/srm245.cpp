// srm245.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <map>

using namespace std;

class Straights
{
public:
	int howMany(vector <int> hand, int k);
};


int Straights::howMany(vector <int> hand, int k)
{
	int stnum = 0;

	for (int i = 0; i < hand.size(); ++i)
	{		
		if ((i + k - 1) < hand.size())
		{
			int prod = 1;
			for (int j = i; j < (i + k); ++j)
			{
				prod *= hand[j];
			}
			stnum += prod;
		}
		else
			break;
	}

	return stnum;
}


int main()
{
	Straights sts;
	vector<int> h = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
	int k = 13;

	int out = sts.howMany(h, k);
	return 0;
}

