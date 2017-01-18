// srm502.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

class TheProgrammingContestDivTwo
{
public:
	vector <int> find(int T, vector <int> requiredTime);
};


vector <int> TheProgrammingContestDivTwo::find(int T, vector <int> requiredTime)
{
	sort(requiredTime.begin(), requiredTime.end());
	int pen = 0;
	int out = 0;
	int sc = 0;
	for (int i = 0; i < requiredTime.size(); ++i)
	{
		pen += requiredTime[i];
		sc += 1;
		if (pen > T)
		{
			sc -= 1;
			break;
		}
		out += pen;
	}

	vector<int> res;
	res.push_back(sc);
	res.push_back(out);

	return res;
}



int main()
{
	TheProgrammingContestDivTwo ot;
	int tt = 74;
	vector<int> vv = { 47 };
	vector<int> op = ot.find(tt, vv);
	return 0;
}

