// srm514.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>
#include <numeric>

using namespace std;

class UpDownHiking
{
public:
	int maxHeight(int N, int A, int B);
};

int UpDownHiking::maxHeight(int N, int A, int B)
{
	int ascposs = 0;
	int descposs = (N-1)*B;

	if (A > descposs)
		return descposs;
	
	int daycnt = 1;
		
	while (ascposs < descposs)
	{
		descposs = (N - daycnt)*B;
		if (descposs > ascposs)
		{
			for (int i = 0; i < A; ++i)
			{
				ascposs += 1;
				if (ascposs >= descposs)
					break;
			}
		}
		daycnt++;
	}

	return ascposs;
}


int main()
{
	UpDownHiking udh;

	int res = udh.maxHeight(20, 7, 9);
	return 0;
}

