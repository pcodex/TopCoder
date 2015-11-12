// srm671.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class BearPaints
{
public:
	long long maxArea(int W, int H, long long M);
};

long long BearPaints::maxArea(int W, int H, long long M)
{	
	long long op = (long long)W * H;
	if (op <= M)
		return op;

	
	int maxwidth = W;
	int maxheight = M/maxwidth;

	op = (long long)maxwidth*maxheight;

	int h = maxheight;
	int w = maxwidth;
	
	long long currmax = 0;

	while (w > 0)
	{
		op = (long long)w*h;
		
		if (currmax < op && w<=W && h<=H)
			currmax = op;
		w -= 1;
		if (w == 0)
			break;

		h = M/w;
		
	}
	
	vector<long long> vres;
	vres.push_back(currmax);

	
	long long res = *max_element(vres.begin(), vres.end());

	return res;
}

int main()
{
	BearPaints bp;
	
	long long res = bp.maxArea(100, 80, 1999);
	//long long res = bp.maxArea(1000000, 1000000, 999999999999);
	return 0;
}

