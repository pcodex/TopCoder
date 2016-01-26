// srm242.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

class TeamSplit
{
	bool myfunc(int i, int j)
	{
		return (i > j);
	}

public:
	int difference(vector <int> strengths);
};

int TeamSplit::difference(vector <int> strengths)
{
	sort(strengths.begin(), strengths.end());

	int team1 = 0, team2 = 0;
	for (int i = 0; i < strengths.size(); i += 2)
	{
		team1 += strengths[i];
	}

	for (int j = 1; j < strengths.size(); j += 2)
	{
		team2 += strengths[j];
	}

	return abs(team1 - team2);

}


int main()
{
	TeamSplit ts;
	vector<int> st = { 5, 7, 8, 4, 2 };
	int diff = ts.difference(st);
	return 0;
}
