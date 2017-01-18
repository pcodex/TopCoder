#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <set>
#include <functional>

using namespace std;

class Segments
{
public:
	string intersection(vector <int> s1, vector <int> s2);
};


string Segments::intersection(vector <int> s1, vector <int> s2)
{
	int x1=s1[0], y1=s1[1], x2=s1[2], y2=s1[3];

	if (x2 < x1)
	{
		swap(x1, x2);
		swap(y1, y2);
	}


	int x3=s2[0], y3=s2[1], x4=s2[2], y4=s2[3];
	if (x4 < x3)
	{
		swap(x3, x4);
		swap(y3, y4);
	}
	
	bool pt = false;
	bool segm = false;

	/*float slp1=-1001,slp2=-1002;
	if (x2!=x1)
		slp1 = (y2 - y1) / (x2 - x1);

	if (x4 != x3)
		slp2 = (y4 - y3) / (x4 - x3);*/

	if (x1!=x2)
	{
		for (int i = x1; i <= x2; ++i)
		{
			if ((x3 == i) || (x4==i))
			{
				int ymin = min(y3, y4);
				int ymax = max(y3, y4);

				for (int j = ymin; j <= ymax; ++j)
				{
					if (y1 == j)
					{
						pt = true;
						break;
					}
				}
				if (pt)
					break;
			}
		}
	}
	else
	{
		int y1min = min(y1, y2);
		int y3min = min(y3, y4);
		int ymin, ymax;
		int yc1, yc2;

		if (y1min < y3min)
		{
			ymax = max(y1, y2);
			ymin = y1min;
			yc1 = y3;
			yc2 = y4;
		}
		else
		{
			ymax = max(y3, y4);
			ymin = y3min;
			yc1 = y1;
			yc2 = y2;
		}

		for (int k = ymin; k <= ymax; ++k)
		{
			if ((yc1 == k) || (yc2==k))
			{
				for (int l = x3; l <= x4; ++l)
				{
					if (x1 == l)
					{
						pt = true;
						break;
					}
				}
				if (pt)
					break;
			}
		}
	}
	

	//if (slp1 == slp2)
	//{
		if ((y3 == y1)&&(y2==y4))
		{
			if ((abs(x1 - x2) > 0) && (abs(x3 - x4) > 0))
			{
				if ((x3 > x1 && x3<x2) || (x4>x1 && x4 < x2))
				{
					pt = false;
					segm = true;
				}

				if ((x1 > x3 && x1<x4) || (x2>x3 && x2 < x4))
				{
					pt = false;
					segm = true;
				}

				if ((x1 == x3) && (x2 == x4))
				{
					pt = false;
					segm = true;
				}
			}
		}

		if ((x3 == x1) && (x2 == x4))
		{
			if ((abs(y1 - y2) > 0) && (abs(y3 - y4) > 0))
			{

				if ((y3 > min(y1, y2) && y3<max(y1, y2)) || (y4>min(y1, y2) && y4 < max(y1, y2)))
				{
					pt = false;
					segm = true;
				}

				if ((y1>min(y3, y4) && y1<max(y3, y4)) || (y2>min(y3, y4) && y2 < max(y3, y4)))
				{
					pt = false;
					segm = true;
				}

				if ((min(y1, y2) == min(y3, y4)) && (max(y1, y2) == max(y3, y4)))
				{
					pt = false;
					segm = true;
				}
			}
		}
	//}

	

	if (pt)
		return "POINT";
    if (segm)
		return "SEGMENT";
	
	return "NO";

}

int main()
{
	Segments sl;
	//{-778, -799, -600, -799}, {-778, -799, -600, -799}}

	vector<int> s1 = { 2, 2, 2, 2 };
	vector<int> s2 = { 2, 1, 2, 3 };

	string out = sl.intersection(s1, s2);

	return 0;
}