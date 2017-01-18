// srm644.cpp : Defines the entry point for the console application.
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

class OkonomiyakiShop
{
public:
	int count(vector <int> osize, int K);
};

int OkonomiyakiShop::count(vector <int> osize, int K)
{
	int cnter = 0;
	sort(osize.begin(), osize.end());
	for (int i = 0; i < osize.size(); ++i)
	{
		for (int j = i + 1; j < osize.size(); ++j)
		{
			if (abs(osize[i] - osize[j]) <= K)
				cnter++;
			else
				break;
		}
	}

	return cnter;
}


	int main()
{
	OkonomiyakiShop sks; 
	vector<int> vc = { 1, 4, 6, 7, 9 };
	int k = 3;
	int noofmeals = sks.count(vc, k);
	return 0;
}

