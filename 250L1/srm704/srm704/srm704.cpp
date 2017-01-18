// srm704.cpp : Defines the entry point for the console application.
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


class SwapAndArithmetic
{
public:
	string able(vector <int> x);
};

string SwapAndArithmetic::able(vector <int> x)
{
	sort(x.begin(), x.end());

	if (x.size() > 1)
	{
		int diff = abs(x[0] - x[1]);

		bool poss = false;

		for (int i = 0; i < x.size() - 1; ++i)
		{
			if (abs(x[i] - x[i + 1]) == diff)
			{
				poss = true;
				continue;
			}
			else
			{
				poss = false;
				break;
			}
		}

		if (poss)
			return "Possible";
		else
			return "Impossible";
	}
	else if (x.size() == 1)
		return "Possible";
	else
		return "Impossible";
}

int main()
{
	SwapAndArithmetic sp;
	vector<int> v = { 1 };
	string pos = sp.able(v);
	return 0;
}

