// srm266.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class SwimmersDelight
{
public:
	int longestJump(vector <int> x, vector <int> y);
};

int SwimmersDelight::longestJump(vector <int> x, vector <int> y)
{
	//closer of the 2 points
	int closex = 0,closey = 0;
	//further of the 2
	int point2x = 0,point2y = 0;

	if (x[0] < x[1])
	{
		closex = x[0];
		closey = y[0];
		
		point2x = x[1];
		point2y = y[1];
	}
	else
	{
		closex = x[1];
		closey = y[1];

		point2x = x[0];
		point2y = y[0];
	}

	//using closex,closey only
	int closexdist2shore = sqrt((closex - 10)*(closex - 10));
	int ljmp1 = max(closex, closexdist2shore);

	//using point2 only
	int point2xdist2shore = sqrt((point2x - 10)*(point2x - 10));
	int ljmp2 = max(point2x, point2xdist2shore);

	//using both points
	float distbwpts = round(sqrt((closex - point2x)*(closex - point2x) + (closey - point2y)*(closey - point2y)));
	int ljmp3 = distbwpts;
	if (closex > ljmp3)
		ljmp3 = closex;
	if (point2xdist2shore > ljmp3)
		ljmp3 = point2xdist2shore;

	int shortestljmp = ljmp1;

	if (ljmp2 < shortestljmp)
		shortestljmp = ljmp2;

	if (ljmp3 < shortestljmp)
		shortestljmp = ljmp3;
	
	return shortestljmp;

}


int main()
{
	SwimmersDelight sd;
	vector<int> x = { 3, 6 };
	vector<int> y = { 5, 2 };
	int rr = sd.longestJump(x, y);
	return 0;
}

