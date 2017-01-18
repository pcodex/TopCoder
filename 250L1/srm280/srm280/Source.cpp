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

class UniqueDigits
{
public:
	int count(int n);
};

int UniqueDigits::count(int n)
{
	int cnt = 0;
	if (n < 100)
	{
		for (int i = 1; i < n; ++i)
		{
			if (i % 11 != 0)
				cnt++;
		}
		return cnt;
	}

	for (int i = 1; i < 100; ++i)
	{
		if (i % 11 != 0)
			cnt++;
	}	

	

	for (int i = 100; i < n; ++i)
	{
		vector<int> digs;
		int num = i;

		while (num != 0)
		{
			int orignum = num;
			num = num / 10;
			int dig = orignum - (num * 10);
			digs.push_back(dig);
		}

		int sz = digs.size();
		sort(digs.begin(), digs.end());
		vector<int>::iterator it = unique(digs.begin(), digs.end());
		vector<int> newv = vector<int>(digs.begin(), it);
		int newsz = newv.size();
		if (sz == newsz)
			cnt++;
	}

	return cnt;

}

int main()
{
	UniqueDigits ud;
	int c = ud.count(1001);
	return 0;
}