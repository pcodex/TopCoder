// srm672.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class SetPartialOrder
{
public:
	string compareSets(vector <int> a, vector <int> b);
};

string SetPartialOrder::compareSets(vector <int> a, vector <int> b)
{
	string res = "INCOMPARABLE";

	int sz = max(a.size(), b.size());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> v1(sz);
	vector<int>::iterator it1,it2;
	
	it1 = set_difference(a.begin(), a.end(), b.begin(), b.end(), v1.begin());

	v1.resize(it1 - v1.begin());

	if (v1.size() == 0)
	{
		if (a.size() == b.size())
			res = "EQUAL";
		else if (a.size() < b.size())
			res = "LESS";
	}
	else
	{
		if (a.size() - v1.size() == b.size())
		{
			res = "GREATER";
		}
	}

	if (v1.size() == a.size())
		res = "INCOMPARABLE";
	

	return res;

}


int main()
{
	SetPartialOrder sp;
	vector<int> v1 = { 2, 4, 6, 8, 10, 12, 14, 16 };
	vector<int> v2 = { 2, 4, 8, 16 };

	vector<int> v3 = { 2, 3, 5, 7 };
	vector<int> v4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	vector<int> v5 = { 42, 23, 17 };
	vector<int> v6 = { 15, 23, 31 };

	vector<int> v7 = { 1,2,3,5,8 };
	vector<int> v8 = { 8, 5, 1, 3, 2 };

	string resu = sp.compareSets(v7, v8);
	return 0;
}

