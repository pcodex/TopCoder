// srm401.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class DreamingAboutCarrots
{
public:
	int carrotsBetweenCarrots(int x1, int y1, int x2, int y2);
};

int DreamingAboutCarrots::carrotsBetweenCarrots(int x1, int y1, int x2, int y2)
{
	float slope = abs(float(y2) - y1) / abs(x2 - x1);

	int ptcnter = 0;

	int X1 = x1;
	int X2 = x2;
	if (x1 > x2){
		X1 = x2;
		X2 = x1;
	}
	int Y1 = y1;
	int Y2 = y2;
	if (y1 > y2){
		Y1 = y2;
		Y2 = y1;
	}


	for (int i = X1,j=Y1; i < X2,j<Y2; ++i,++j)
	{
		int YH = j + 1, YL=j;
		int XH = i + 1, XL = i;
		int SLP = (YH - YL) / (XH - XL);

		if (SLP == slope)
			ptcnter++;
	}
	return ptcnter-1;
}


	int main()
{
	DreamingAboutCarrots dc;
	int cnt = dc.carrotsBetweenCarrots(50, 48, 0, 0);
	return 0;
}

