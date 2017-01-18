// srm412.cpp : Defines the entry point for the console application.
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

class TrueSpace
{
public:
	long long calculateSpace(vector <int> sizes, int clusterSize);
};

long long TrueSpace::calculateSpace(vector <int> sizes, int clusterSize)
{
	long long clustot = 0;

	for (int i = 0; i < sizes.size(); ++i)
	{
		long long rawnum = sizes[i] / clusterSize;
		long long leftover = sizes[i] % clusterSize;

		clustot += (rawnum*clusterSize);
		if (leftover > 0)
			clustot += clusterSize;
	}

	return clustot;
}


int main()
{
	TrueSpace tsp;
	vector<int> sz = { 4096, 33792, 76800 };
	int cs = 1024;
	long long totsx = tsp.calculateSpace(sz, cs);
	return 0;
}

