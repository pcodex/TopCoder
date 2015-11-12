// srm670.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>

using namespace std;

class Cdgame
{
public:
	int rescount(vector <int> a, vector <int> b);
};

int Cdgame::rescount(vector <int> a, vector <int> b)
{	
	vector<int> acopy = a, bcopy = b;
	set<int> msum;
	

	for (int i = 0; i < a.size(); ++i)
	{		
		for (int j = 0; j < b.size(); ++j)
		{
			bcopy = b;
			acopy = a;

			int tmp = bcopy[j];
			bcopy[j] = acopy[i];
			acopy[i] = tmp;		

			msum.insert((accumulate(acopy.begin(), acopy.end(), 0))*(accumulate(bcopy.begin(), bcopy.end(), 0)));
		}
	}


	return msum.size();
}

int main()
{
	vector<int> v1 = { 31, 34, 55, 56, 57 };
	vector<int> v2 = { 1, 2, 3, 4, 5 };

	Cdgame c;
	int out = c.rescount(v1, v2);
			
	return 0;
}

