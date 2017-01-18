// srm685.cpp : Defines the entry point for the console application.
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

class MultiplicationTable2Easy
{
public:
	string isGoodSet(vector <int> table, vector <int> t);
};


string MultiplicationTable2Easy::isGoodSet(vector <int> table, vector <int> t)
{
	string sout = "Good";
	int n = sqrt(table.size());

	for (size_t i = 0; i < t.size(); ++i)
	{
		for (size_t j = 0; j < t.size(); ++j)
		{
			int val = table[(t[i] * n) + t[j]];
			vector<int>::iterator it = find(t.begin(), t.end(), val);
			if (it == t.end())
			{
				sout = "Not Good";
				return sout;
			}
		}
	}

	return sout;
}


int main()
{

	MultiplicationTable2Easy mt;
	vector<int> tb = { 1, 1, 2, 3,
		1, 0, 2, 3,
		3, 3, 0, 3,
		2, 2, 2, 0 };

	vector<int> t = { 1, 0 };

	string out = mt.isGoodSet(tb, t);
	return 0;
}

