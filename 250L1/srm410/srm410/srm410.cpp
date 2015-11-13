// srm410.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class ContiguousCacheEasy
{
public:
	int bytesRead(int n, int k, vector <int> addresses);
};

int ContiguousCacheEasy::bytesRead(int n, int k, vector <int> addresses)
{
	int begin = 0;
	int end = begin + k-1;

	int bytcnt = 0;
	for (int i = 0; i < addresses.size(); ++i)
	{
		if (addresses[i] <= end && addresses[i]>=begin)
			continue;		
		else
		{
			int newend = 0;
			int newbegin = 0;

			if (addresses[i] <= (k - 1))
			{				
				newbegin = 0;
				newend = k - 1;
			}
			else
			{			

				if (addresses[i] < begin)
				{					
					newbegin = addresses[i];
					newend = newbegin + k - 1;
				}
				else if (addresses[i] > end)
				{
					newend = addresses[i];
					newbegin = newend - k + 1;
				}	
				
			}

			if (abs(newend - end) >= k &&
				abs(newbegin - begin) >= k
				)
				bytcnt += k;
			else
				bytcnt += abs(newend - end);

			end = newend;
			begin = end - k + 1;
		}
	}

	return bytcnt;
}

int main()
{
	ContiguousCacheEasy cge;
	//int n = 100;
	//int k = 4;
	//vector<int> addresses = { 0, 4, 9, 6, 3 };

	/*int n = 1000;
	int k = 999;
	vector<int> addresses = { 0, 4, 123, 987, 999, 500, 0 };*/

	int n = 100;
	int k = 4;
	vector<int> addresses = { 0, 4, 8, 6, 9, 13,8,4 };

	int btcnt = cge.bytesRead(n, k, addresses);
	return 0;
}

