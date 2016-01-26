// srm211.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;

class grafixClick
{
public:
	vector <int> checkSaveButton(vector <int> mouseRows, vector <int> mouseCols);
};


vector <int> grafixClick::checkSaveButton(vector <int> mouseRows, vector <int> mouseCols)
{
	int romin = 20, romax = 39;
	int colmin = 50, colmax = 99;

	vector<int> clicks;

	for (int i = 0; i < mouseCols.size(); ++i)
	{
		int row = mouseRows[i];
		int col = mouseCols[i];

		if ((row >= romin) && (row <= romax) && (col >= colmin) && (col <= colmax))
			clicks.push_back(i);
	}
	return clicks;

}


int main()
{

	grafixClick gfc;

	vector<int> mr = { 20, 39, 100 };
	vector<int> mc = { 99, 50, 200 };

	vector<int> vc = gfc.checkSaveButton(mr, mc);
	return 0;
}

