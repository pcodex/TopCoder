// srm218.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

class AccessLevel
{
public:
	string canAccess(vector <int> rights, int minPermission);
};


string AccessLevel::canAccess(vector <int> rights, int minPermission)
{
	string canAcc = "";

	for (int i = 0; i < rights.size(); ++i)
	{
		if (rights[i] >= minPermission)
			canAcc += "A";
		else
			canAcc += "D";
	}

	return canAcc;
}



int main()
{
	AccessLevel al;

	vector<int> r = { 34, 78, 9, 52, 11, 1 };
	int mp = 49;
	string op = al.canAccess(r, mp);
	
	return 0;
}

