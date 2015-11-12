// srm653.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class CountryGroup
{
public:
	int solve(vector <int> a);
};

int CountryGroup::solve(vector <int> a)
{
	
	int countrycnt = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		int expcnt = 0, actcnt = 1;
				
		expcnt = a[i];

		for (int j = 0; j < a[i]-1; ++j)
		{
			if ((i + j + 1) < a.size())
			{
				if (a[i] == a[i+j+1])
				{
					//a[i] = -1;
					actcnt++;

					//if (actcnt == a[i+1])
					//a[i + 1] = -1;
				}
				else
				{
					return -1;
				}
			}
		}
		if (expcnt == actcnt)
		{
			countrycnt++;
			i = i + a[i]-1;
		}
		else
			return -1;
	}

	return countrycnt;
}

int main()
{
	CountryGroup cg;
	vector<int> v = { 2, 1, 2, 2, 1, 2 };

	int cc = cg.solve(v);

	return 0;
}

