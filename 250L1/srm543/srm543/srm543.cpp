// srm545.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class EllysTSP
{
public:
	int getMax(string places);
};

int EllysTSP::getMax(string places)
{
	int vcnt = count(places.begin(), places.end(), 'V');
	int ccnt = count(places.begin(), places.end(), 'C');

	if ((vcnt == 0 && ccnt!=0)
		|| (ccnt==0 && vcnt!=0))
	{
		return 1;
	}

	int total = 0;
	if ((vcnt != 0 && ccnt != 0) &&
		(vcnt != ccnt))
	{
		int themin = min(vcnt, ccnt);

		total = (2 * themin) + 1;
	}
	else if (vcnt == ccnt)
	{
		total = vcnt + ccnt;
	}

	return total;
}


int main()
{
	EllysTSP esp;
	string ss = "V";

	int re = esp.getMax(ss);
	return 0;
}

