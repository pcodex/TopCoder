#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class Truckloads
{
public:
	int numTrucks(int numCrates, int loadSize);
};

int Truckloads::numTrucks(int numCrates, int loadSize)
{
	int noOfTrucks = 0;
	stack<int> ss;

	int sz1 = round(float(numCrates) / 2);
	if (sz1 <= loadSize)
		noOfTrucks++;
	else
		ss.push(sz1);

	int sz2 = numCrates - sz1;
	if (sz2 <= loadSize)
		noOfTrucks++;
	else
		ss.push(sz2);
	
		
	while (!ss.empty())
	{	
		int oldsz1 = ss.top();
		ss.pop();

		sz1 = round(float(oldsz1) / 2);
		if (sz1 <= loadSize)
			noOfTrucks++;
		else
			ss.push(sz1);
		
		sz2 = oldsz1 - sz1;
		if (sz2 <= loadSize)
			noOfTrucks++;
		else
			ss.push(sz2);
	}

	return noOfTrucks;
}

int main()
{
	Truckloads tl;
	int tr = tl.numTrucks(1024, 5);
	return 0;
}