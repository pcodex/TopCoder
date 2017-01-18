#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <functional>

using namespace std;


class FowlRoad
{
public:
	int crossings(int roadY, vector <int> bobX, vector <int> bobY);
};

int FowlRoad::crossings(int roadY, vector <int> bobX, vector <int> bobY)
{
	int noc = 0;
	bool below = false;

	if (bobY[0] < roadY)
		below = true;
	
	for (int i = 1; i < bobX.size(); ++i)
	{
		if (bobY[i]>roadY) 
		{
			if (below == true)
			{
				noc++;
				below = false;
			}
			else
			{
				below = false;
			}
		}
		else if (bobY[i] < roadY)
		{
			if (below == true)
			{
				below = true;
			}
			else
			{
				noc++;
				below = true;
			}
		}
		else if (bobY[i] == roadY)
		{
			continue;
		}
	}

	return noc;
}

int main()
{
	FowlRoad f;
	vector<int> bx = { 3, 2, 5, 6, 9 };
	vector<int> by = { -2, 0, 0, 2, -88 };
		int r = 0;

	int xs = f.crossings(r, bx, by);
	return 0;
}
