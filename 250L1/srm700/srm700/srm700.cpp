// srm700.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

class Xylophone
{
public:
	int countKeys(vector <int> keys);
};

int Xylophone::countKeys(vector <int> keys)
{
	set<int> ss;
	for (int i = 0; i < keys.size(); ++i)
	{
		ss.insert(keys[i] % 7);
	}

	return ss.size();
}


int main()
{
	Xylophone xp;

	vector<int> k = { 50, 10, 20, 30, 11, 30, 24, 38, 5, 2, 9 };
	int out = xp.countKeys(k);
	return 0;
}

