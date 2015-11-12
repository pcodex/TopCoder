// srm542.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class WorkingRabbits
{
public:
	double getEfficiency(vector <string> profit);
};


double WorkingRabbits::getEfficiency(vector <string> profit)
{
	int q = 0;
	double p = 0.0;
	for (int i = 0; i < profit.size(); ++i)
	{
		for (int j = i; j < profit[i].length(); ++j)
		{
			if (i == j)
				continue;
			else
			{
				p += (profit[i][j] - '0');
				q++;
			}
		}
	}

	return p / q;
}