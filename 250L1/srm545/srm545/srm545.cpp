// srm545.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class ANDEquation
{
public:
	int restoreY(vector<int> A);
};

int ANDEquation::restoreY(vector<int> A)
{
	int yis = -1;

	for (int i = 0; i < A.size(); ++i)
	{
		int ares = 1048575;
		for (int j = 0; j < A.size(); ++j)
		{
			if (j != i)
			{
				ares = ares&A[j];
			}
		}
		if (ares == A[i])
		{
			yis = A[i];
			break;
		}
	}

	return yis;
	
}


int main()
{
	ANDEquation ad;
	vector<int> vv = { 2, 3, 7, 19 };

	int ret = ad.restoreY(vv);
	return 0;
}

