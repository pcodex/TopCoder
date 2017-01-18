// srm301.cpp : Defines the entry point for the console application.
//

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

class InsertionSortCount
{
public:
	int countMoves(vector <int> A);
};

int InsertionSortCount::countMoves(vector <int> A)
{	
	vector<int> srtd;

	srtd.push_back(A[0]);
	int cnt = 0;

	for (int i = 1; i < A.size(); ++i)
	{
		int j;
		for (j = 0; j < srtd.size(); ++j)
		{
			if (A[i]>srtd[j])
				continue;
			else
				break;
		}
		int currsz = srtd.size();
		
		if (j < currsz)
		{
			srtd.resize(currsz + 1);
			//int bb = 0;
			for (int z = currsz - 1; z >= j; z--)
			{
				srtd[z+1] = srtd[z];
				cnt++;
				//bb += 1;
			}


			srtd[j] = A[i];
		}
		else
			srtd.push_back(A[i]);
	}

	return cnt;
	
}

int main()
{
	InsertionSortCount is;
	vector<int> a = { -1000,0,1000 };

	int mv = is.countMoves(a);
	return 0;
}

