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

class RugSizes
{
public:
	int rugCount(int area);
};

int RugSizes::rugCount(int area)
{
	set<int> s;


	int hlf = round(float(area) / 2);

	for (int i = 1; i <= hlf; ++i)
	{
		if ((area%i) == 0)
		{
			int fac = area / i;

			if ((fac % 2 == 0) && (i % 2 == 0) && (fac != i))
				continue;
			else
			{
				s.insert(i);
				s.insert(fac);
				if (i == fac)
					s.insert(fac + 1);
			}			
		}
	}
	return s.size()/2;
}

int main()
{
	RugSizes r;

	int cnt = r.rugCount(1);
	return 0;
}