// srm547.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;



class MinimalTriangle
{
public:
	double maximalArea(int length);
};

double MinimalTriangle::maximalArea(int length)
{
	//

	const float PI = 3.1415926535897932384;

	double sinval = sin(120*(PI/180));
	double sin2 = 0.5*(sqrt(3));
	
	//double area3 = 0.5*(length*length)*(sin(120*(PI/180)));
	double area3 = 0.5*(length*length)*sin2;
	
	
	

	return area3;

	//return sqrt(3.0)/4.0*length*length;
}


int main()
{

	MinimalTriangle mt;

	double opmax = mt.maximalArea(100000);
	return 0;
}

