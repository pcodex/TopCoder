// srm273.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class AimToTen
{
public:
	int need(vector <int> marks);
};

int AimToTen::need(vector <int> marks)
{
	float currtot = accumulate(marks.begin(), marks.end(), 0);

	float curravg = currtot / marks.size();
	int cnt = 0;

	while (curravg < 9.5)
	{
		currtot += 10;
		cnt += 1;
		curravg = currtot / (marks.size() + cnt);
	}

	return cnt;
}

int main()
{
	AimToTen ta;
	vector<int> m = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	;
	int cnt = ta.need(m);
	return 0;
}

