// srm667.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

class PointDistance
{
public:
	vector <int> findPoint(int x1, int y1, int x2, int y2);
	double getdist(int x1, int y1, int x2, int y2);
};

double PointDistance::getdist(int x1, int y1, int x2, int y2)
{
	double dist = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));

	return dist;
}

vector<int> PointDistance::findPoint(int x1, int y1, int x2, int y2)
{
	vector<int> votu;
	int x3=x2, y3=y2;

	if (x2 >= x1)
	{
		x3 = x2 + 1;
		y3 = y2;
	}
	else if (x2 < x1)
	{
		x3 = x2 - 1;
		y3 = y2;
	}
	
	
		
	double ac = getdist(x1, y1, x3, y3);
	double bc = getdist(x2, y2, x3, y3);

	

	votu.push_back(x3);
	votu.push_back(y3);

	return votu;

}

int main()
{
	PointDistance pd;
	vector<int> vd;
	int x1 = 0, y1 = 1, x2 = 2, y2 = 3;

	//int x1 = 1, y1 = 1, x2 = -1, y2 = -1;

	vd = pd.findPoint(x1,y1,x2,y2);
	
	return 0;
}

