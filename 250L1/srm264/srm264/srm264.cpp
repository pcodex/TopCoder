// srm264.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class GradingSystem
{
public:
	int fairness(vector <int> scores, vector <int> grades);
};

int GradingSystem::fairness(vector <int> scores, vector <int> grades)
{
	//vector<int> wrkgrades = grades;
	vector<int> s1grad = grades;

	//scheme 1
	for (int i = 0; i < scores.size(); ++i)
	{
		for (int j = 0; j < scores.size(); ++j)
		{
			if (i == j)
				continue;

			if (scores[j] >= scores[i])
			{
				if (s1grad[j] >= s1grad[i])
					continue;
				else
				{
					s1grad[j] = s1grad[i];
					//wrkgrades = s1grad;
				}
			}
		}
	}

	vector<int> s2grad = grades;
	//wrkgrades = grades;

	//scheme 2
	for (int i = 0; i < scores.size(); ++i)
	{
		for (int j = 0; j < scores.size(); ++j)
		{
			if (i == j)
				continue;

			if (scores[j] <= scores[i])
			{
				if (s2grad[j] > s2grad[i])
				{
					s2grad[j] = s2grad[i];
					//wrkgrades = s2grad;
				}
				else
					continue;
			}
		}
	}

	//sum the diff
	int sum = 0;
	for (int i = 0; i < s1grad.size(); ++i)
	{
		sum += abs(s1grad[i] - s2grad[i]);
	}

	return sum;
}


int main()
{
	GradingSystem gs;

	vector<int> s = { 0, 25, 50, 75, 100 };
	vector<int> g = { 0, 1, 3, 6, 8 };
	int diff = gs.fairness(s, g);
	return 0;
}

