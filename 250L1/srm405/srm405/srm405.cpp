// srm405.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class FallingFactorialPower
{
public:
	double compute(int n, int k);
};

double FallingFactorialPower::compute(int n, int k)
{
	double ans = 1.0;

	if (k == 0)
		return 1.0;
	else if (k > 0)
	{
		for (int i = 0; i < k; ++i)
		{
			ans = ans*n;
			n = n - 1;
		}
	}
	else
	{
		double start = n + 1;
		double k1 = -k;

		for (int i = start; i <= n + k1; ++i)
		{
			ans = ans*i;
		}
		
		ans = 1 / ans;
	}
	return ans;

}

int main()
{
	FallingFactorialPower fp;
	double res = fp.compute(2, -3);
	return 0;
}

