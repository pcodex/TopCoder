// srm253.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <cctype>

using namespace std;

class ObjectPacking
{
public:
	int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength);
};

int ObjectPacking::smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength)
{
	vector<int> cands;
	bool pushed = false;

	for (int i = 0; i < boxLength.size(); ++i)
	{
		if (objLength <= boxLength[i])
		{
			if (objWidth <= boxWidth[i])
			{
				cands.push_back(boxWidth[i] * boxLength[i]);
				pushed = true;
			}
		}		
		if (objLength <= boxWidth[i])
		{
			if (objWidth <= boxLength[i])
			{
				if (pushed == false){
					cands.push_back(boxWidth[i] * boxLength[i]);
					pushed = true;
				}
			}
		}
		pushed = false;
	}

	int area = -1;
	if (cands.size()>0)
	{
		vector<int>::iterator it = min_element(cands.begin(), cands.end());
		area = *it;
	}

	return area;
}


	int main()
{
	ObjectPacking op;
	int ow = 1;
	int ol = 10;
	vector<int> bw = { 9, 1, 10 }, bl = { 10, 6, 4 };
	int ar = op.smallBox(ow, ol, bw, bl);
	return 0;
}

