// srm680.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class BearPair
{
public:
	int bigDistance(string s);
};

int BearPair::bigDistance(string s)
{
	string stmp = s;

	sort(stmp.begin(), stmp.end());
	int maxdiff = -1;

	for (int i = 0; i < stmp.length(); ++i)
	{
		for (int j = stmp.length()-1; j >= 0; --j)
		{
			if (stmp[i] == stmp[j])
				continue;

			int pos1 = s.find(stmp[i]);
			int prevpos2 = 0, pos2 = 0;
			while ((pos2 = s.find(stmp[j], pos2)) != std::string::npos)
			{
				prevpos2 = pos2;
				pos2 = prevpos2+1;
			}

			if (abs(pos1 - prevpos2) > maxdiff)
				maxdiff = abs(pos1 - prevpos2);
		}
	}

	return maxdiff;
}


int main()
{
	BearPair bp;

	int dis = bp.bigDistance("xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx");
	return 0;
}

