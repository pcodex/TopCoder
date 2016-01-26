// srm678.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <math.h>

using namespace std;

class ThePhantomMenace
{
public:
	int find(vector <int> doors, vector <int> droids);
};


int ThePhantomMenace::find(vector <int> doors, vector <int> droids)
{	
	vector<int> themins;
	
	for (int j = 0; j < doors.size();++j)
	{
		int min = 100;
		for (int i = 0; i < droids.size(); ++i)
		{
			int diff = abs(droids[i] - doors[j]);

			if (diff < min)
				min = diff;
		}
		themins.push_back(min);
	}

	vector<int>::iterator it = max_element(themins.begin(), themins.end());

	return *it;
}


	int main()
{
	ThePhantomMenace ph;
	vector<int> d = { 2, 1 };
	vector<int> dr = { 4, 3 };
	int ak = ph.find(d, dr);
	return 0;
}

