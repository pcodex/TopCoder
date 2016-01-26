// srm679.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <numeric>

using namespace std;

class ListeningSongs
{
public:
	int listen(vector <int> durations1, vector <int> durations2, int minutes, int T);
};


int ListeningSongs::listen(vector <int> durations1, vector <int> durations2, int minutes, int T)
{

	int tGiven = minutes * 60;
	int cnt = 0;
	int totDur = 0;

	sort(durations1.begin(), durations1.end());
	sort(durations2.begin(), durations2.end());

	for (int i = 0; i < T; ++i)
	{
		if (i < durations1.size())
		{
			totDur += durations1[i];
			durations1[i]=0;
			cnt += 1;
		}
		else
			return -1;
		
		if (i < durations2.size())
		{
			totDur += durations2[i];
			durations2[i]=0;
			cnt += 1;
		}
		else
			return -1;
	}

	if (totDur > tGiven)
		return -1;

	sort(durations1.begin(), durations1.end());
	sort(durations2.begin(), durations2.end());
	vector<int> vcmb;
	for (int i = 0; i < durations1.size(); ++i)
	{
		if (durations1[i] != 0)
			vcmb.push_back(durations1[i]);
	}
	for (int i = 0; i < durations2.size(); ++i)
	{
		if (durations2[i] != 0)
			vcmb.push_back(durations2[i]);
	}

	sort(vcmb.begin(), vcmb.end());

	int incr = 0;
	while(totDur <= tGiven && incr<vcmb.size())
	{
		totDur += vcmb[incr];
		
		if (totDur > tGiven)
			break;

		incr++;
		cnt++;
	}
	
	return cnt;

}

int main()
{

	//{300, 200, 100}, {100, 500, 600}, 20, 2

	ListeningSongs ls;
	vector<int> d1 = {1117, 3332, 3314, 1808, 146, 1570, 3390, 3580, 1479, 2261, 402, 1441, 2192, 3369, 1165, 2453, 2316, 3073, 2486, 2587, 2902, 166, 3563, 2653, 189, 1675, 917, 2271, 955, 372, 319, 306, 1938, 1867, 2054, 2025, 1671, 1843, 298, 3090, 2338, 640, 2765, 2765, 2244, 329, 3452, 959, 1637, 2337, 1781, 938, 2444, 1743, 1825, 867, 3358, 976, 3078, 712, 1289, 3337, 2794, 1461, 3438, 1247, 1720, 1508, 1325, 253, 2832, 62, 833, 1997, 1061, 1311, 560, 913, 505, 431, 3190, 2226, 1309, 327};
	vector<int> d2 = {2203, 3075, 1134, 1960, 450, 612, 906, 3514, 2183, 99, 3210, 2021, 3122, 1329, 1763, 2681, 1522, 995, 977, 590, 1226, 1979, 135, 3561, 2832, 2415, 392, 715, 2875, 3476, 983, 1477, 1244, 2057, 1671, 3470, 903, 2518, 3383, 3027, 851, 1286, 3282, 2207, 850, 3279, 1287, 606, 2508, 2205, 2971, 133, 2418, 3047, 1929, 1649, 155, 2261, 598, 2971, 2136, 1521, 847, 3321, 1813, 2459, 1484, 950, 3211, 3101, 2211, 2296, 787, 1892, 903, 1577, 3406, 424, 2123, 2313, 2569, 3329, 2387, 3221, 2775, 2550, 3104};
		int m = 7857;
	int t = 44;

	/*vector<int> d1 = { 300, 200, 100 };
	vector<int> d2 = { 100, 500, 600 };
	int m = 20;
	int t = 2;*/

	int p = ls.listen(d1, d2, m, t);
	return 0;
}

