// 522.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	You are given a vector <int> y of length N. The values in y describe N points in the plane: for each x = 0, 1, ..., N - 1 there is a point at coordinates (x, y[x]).  Krolik is going to perform the following operation:
	Choose two of the given points, say A and B, with different y-coordinates.
	Consider the rectangle with sides parallel to coordinate axes and points A and B in two opposite corners.
	Erase all points strictly inside the rectangle.
	Return the maximum possible number of points Krolik can erase by a single operation.
	Definition
	    
		Class:
		PointErasingTwo
		Method:
		getMaximum
		Parameters:
		vector <int>
		Returns:
		int
		Method signature:
		int getMaximum(vector <int> y)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			A point is strictly inside a rectangle if it is inside the rectangle and does not lie on the border of the rectangle.
			Constraints
			-
			y will contain between 2 and 50 elements, inclusive.
			-
			Each element of y will be between 0 and 50, inclusive.
			-
			y will contain at least 2 distinct elements.
			Examples
			0)

			    
				{ 1, 2, 1, 1, 0, 4, 3 }
				Returns: 2
				If Krolik chooses A = (1, 2) and B = (4, 0), Krolik can erase two points: (2, 1) and (3, 1).
				1)

				    
					{ 0, 1 }
					Returns: 0

					2)

					    
						{ 0, 1, 2, 3, 4 }
						Returns: 3

						3)

						    
							{ 10, 19, 10, 19 }
							Returns: 0

							4)

							    
								{ 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 }
								Returns: 5

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;


class PointErasingTwo
{
	int countInnerPoints(int o1, int o2, vector<int> y);
	bool areOppo(int x1, int x2, vector<int> y);
public:
	int getMaximum(vector <int> y);
};

int PointErasingTwo::getMaximum(vector <int> y)
{
	int inner = 0;
	for (int i = 0; i < y.size(); ++i)
	{
		for (int j = i + 1; j < y.size(); ++j)
		{
			bool isOpp = areOppo(i, j, y);
			if (isOpp)
			{
				int tmpcnt = countInnerPoints(i, j, y);
				if (tmpcnt > inner)
					inner = tmpcnt;
			}
		}
	}

	return inner;
}

bool PointErasingTwo::areOppo(int x1, int x2, vector<int> y)
{
	bool areOpp = false;
	int y1 = y[x1];
	int y2 = y[x2];

	if (y1 != y2 && x1 != x2)
		areOpp = true;
	
	return areOpp;
}

int PointErasingTwo::countInnerPoints(int o1, int o2, vector<int> y)
{
	int x1 = o1, x2 = o2, y1 = y[o1], y2 = y[o2];
	int cnt = 0;

	for (int z = 0; z < y.size(); ++ z)
	{
		if (z == x1 || z == x2)
			continue;

		if ((z>x1 && z<x2) || (z>x2 && z<x1))
		{
			int yz = y[z];
			if ((yz > y1 && yz < y2) || (yz > y2&&yz < y1))
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	PointErasingTwo pt;
	vector<int> vv = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
	int cc = pt.getMaximum(vv);
    return 0;
}

