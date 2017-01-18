// srm263.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <math.h>
#include <numeric>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

class Party
{
public:
	double averageNames(int n, vector<int> personA, vector<int> personB);
};

double Party::averageNames(int n, vector<int> personA, vector<int> personB)
{
	map<int, set<int> > prsn;

	for (int i = 0; i < personA.size(); ++i)
	{
		int pers1 = personA[i];
		int pers2 = personB[i];

		//insert whom they already know into each other's sets
		set<int>::iterator sit;
		for (sit = prsn[pers2].begin(); sit != prsn[pers2].end(); sit++)
		{
			if (*sit != pers1)
				prsn[pers1].insert(*sit);
		}

		for (sit = prsn[pers1].begin(); sit != prsn[pers1].end(); sit++)
		{
			if (*sit != pers2)
				prsn[pers2].insert(*sit);
		}

		//insert each other into the friend set
		prsn[pers1].insert(pers2);
		prsn[pers2].insert(pers1);
	}

	/*vector<set<int> > prsn;	

	prsn.resize(100);

	for (int i = 0; i < personA.size(); ++i)
	{
		int pers1 = personA[i];
		int pers2 = personB[i];

		//insert whom they already know into each other's sets
		set<int>::iterator sit;
		for (sit = prsn[pers2].begin(); sit != prsn[pers2].end(); sit++)
		{
			if (*sit!=pers1)
				prsn[pers1].insert(*sit);
		}

		for (sit = prsn[pers1].begin(); sit != prsn[pers1].end(); sit++)
		{
			if (*sit != pers2)
				prsn[pers2].insert(*sit);
		}		

		//insert each other into the friend set
		prsn[pers1].insert(pers2);
		prsn[pers2].insert(pers1);
	}*/

	double tot = 0;

	for (int i = 0; i < prsn.size(); ++i)
	{
		int tmp = prsn[i].size();
		tot += tmp;
	}
	double avg = tot / n;

	return avg;
	
}

int main()
{
	Party ot;
	int n = 25;
	vector<int> pa = { 14, 14, 16, 4, 14, 16, 2, 16, 8, 15, 17, 17, 3, 3, 19, 17, 20, 4, 24, 8 };
	vector<int> pb = { 16, 2, 23, 16, 11, 8, 5, 19, 15, 20, 19, 18, 14, 12, 22, 9, 0, 7, 23, 10 };

	double av = ot.averageNames(n, pa, pb);
	return 0;
}

