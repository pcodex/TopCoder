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

class TheAlmostLuckyNumbersDivTwo
{
public:
	int find(int a, int b);
};

int TheAlmostLuckyNumbersDivTwo::find(int a, int b)
{
	int lmostlck = 0;
	for (int i = a; i <= b; ++i)
	{
		stringstream snum;
		snum << i;
		string num = snum.str();

		int cnt4 = count(num.begin(), num.end(), '4');
		int cnt7 = count(num.begin(), num.end(), '7');
		int luckcnt = cnt4 + cnt7;

		if ((luckcnt == num.length()) ||
			(luckcnt == num.length() - 1))
		{
			lmostlck++;
		}
	}

	return lmostlck;
}

int main()
{
	TheAlmostLuckyNumbersDivTwo pl;
	int res = pl.find(1234, 4321);

	return 0;
}