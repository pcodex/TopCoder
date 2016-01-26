// srm230.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <math.h>

using namespace std;

class InequalityChecker
{
public:
	vector <int> getDifferences(int n);
};


vector <int> InequalityChecker::getDifferences(int n)
{
	//s = upto pow(n-1)
	vector<int> v;

	int s = 0;
	int cnt = 1;
	//calculate s
	while (cnt < n)
	{
		s += pow(cnt, 3);
		cnt++;
	}

	//calc n3
	int n3 = n*n*n;

	//calc n4
	int n4 = n3*n;

	int numer = (4 * s) + (2 * n3) - (n4);
	int denom = 4;

	if ((numer%denom) == 0)
	{
		numer = numer / 4;
		denom = 1;
	}

	else if (numer % 2 == 0)
	{
		numer = numer / 2;
		denom = 2;
	}

	v.push_back(numer);
	v.push_back(denom);

	return v;
}



int main()
{
	InequalityChecker ina;

	vector<int> v;

	v = ina.getDifferences(100);
	return 0;
}

