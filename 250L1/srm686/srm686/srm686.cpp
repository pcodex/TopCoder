// srm686.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class TreeAndVertex
{
public:
	int get(vector <int> tree);
};

int TreeAndVertex::get(vector <int> tree)
{
	map<int, int> mt;

	for (size_t i = 0; i < tree.size(); ++i)
	{
		mt[tree[i]] += 1;
		mt[i + 1] += 1;
	}

	int max = 0;
	for (size_t st = 0; st < mt.size(); ++st)
	{
		if (mt[st] > max)
			max = mt[st];
	}

	return max;
}


int main()
{
	TreeAndVertex tv;
	vector<int> t = { 0, 0, 2, 2 };
	int ret = tv.get(t);
	return 0;
}

