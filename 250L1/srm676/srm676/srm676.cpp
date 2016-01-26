// srm676.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;


class FarmvilleDiv2
{
public:
	int minTime(vector <int> time, vector <int> cost, int budget);
};


int FarmvilleDiv2::minTime(vector <int> time, vector <int> cost, int budget)
{
	vector<int> tCpy = time;
	vector<int> cCpy = cost;
	int bCpy = budget;

	vector<int>::iterator maxit;
	int res1 = 0, res2 = 0;

	for (int i = 0; i < tCpy.size(); i++)
	{
		maxit = max_element(tCpy.begin(), tCpy.end());
		int idx = distance(tCpy.begin(), maxit);

		while (tCpy[idx]>0 && budget > 0)
		{
			if (bCpy >= cCpy[idx])
			{
				tCpy[idx] = tCpy[idx] - 1;
				bCpy = bCpy - cCpy[idx];
			}
			else
				break;
		}		
	}

	res1 = accumulate(tCpy.begin(), tCpy.end(), 0);
	tCpy = time;
	cCpy = cost;
	bCpy = budget;

	for (int i = 0; i < tCpy.size(); i++)
	{
		maxit = min_element(cCpy.begin(), cCpy.end());
		int idx = distance(cCpy.begin(), maxit);

		while (tCpy[idx]>0 && bCpy > 0)
		{
			if (bCpy >= cCpy[idx])
			{
				tCpy[idx] = tCpy[idx] - 1;
				bCpy = bCpy - cCpy[idx];
			}
			else
				break;
		}
		cCpy[idx] = 9999;
	}

	res2 = accumulate(tCpy.begin(), tCpy.end(), 0);

	

	return min(res1, res2);
}

int main()
{
	FarmvilleDiv2 fd;
	vector<int> time = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };
	vector<int> cost = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int budget = 5000;
	int et = fd.minTime(time,cost,budget);
	return 0;
}

