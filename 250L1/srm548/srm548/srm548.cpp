// srm548.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class KingdomAndDucks
{
public:
	int minDucks(vector <int> duckTypes);
};

int KingdomAndDucks::minDucks(vector <int> duckTypes)
{
	map<int, int> typcnt;

	for (int i = 0; i < duckTypes.size(); ++i)
	{
		typcnt[duckTypes[i]] += 1;
	}

	map<int, int>::iterator mit;

	int maxcnt = 0;
	for (mit = typcnt.begin(); mit != typcnt.end(); mit++)
	{
		if (mit->second > maxcnt)
			maxcnt = mit->second;
	}

	int noOfTypes = typcnt.size();

	return (maxcnt*noOfTypes);

}


int main()
{
	KingdomAndDucks kd;
	vector<int> vs = { 4, 7, 4, 7, 4 };
	int totalducks = kd.minDucks(vs);
	return 0;
}

