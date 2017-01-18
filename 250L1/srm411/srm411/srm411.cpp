// srm411.cpp : Defines the entry point for the console application.
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

class MaximumScoredNumber
{
public:
	int getNumber(int lowerBound, int upperBound);
};

int MaximumScoredNumber::getNumber(int lowerBound, int upperBound)
{
	int maxscore = 0;
	int maxscorer = lowerBound;

	for (int i = lowerBound; i <= upperBound; ++i)
	{
		vector<int> sqs;
		for (int j = 0; (j*j) <= i; ++j)
			sqs.push_back(j*j);

		sort(sqs.begin(), sqs.end());

		int target = i;
		int score = 0;
		for (int a = 0; a < sqs.size(); ++a)
		{
			for (int b = a; b < sqs.size(); ++b)
			{
				if (sqs[a] + sqs[b] == target)
					score += 1;
			}
		}

		if (score >= maxscore)
		{
			maxscore = score;
			maxscorer = target;
		}
	}

	return maxscorer;
}


int main()
{
	MaximumScoredNumber msdl;
	int sc = msdl.getNumber(0, 30);

	return 0;
}

