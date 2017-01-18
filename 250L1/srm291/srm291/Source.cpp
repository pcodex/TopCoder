#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <functional>

using namespace std;


class FarFromPrimes
{
	bool isPrime(int n);
	bool isFar(int n);
public:
	int count(int A, int B);
};

bool FarFromPrimes::isPrime(int n)
{
	bool isP = true;
	for (int i = 2; i < n; ++i)
	{
		if ((n%i) == 0)
		{
			isP = false;
			break;
		}
	}
	return isP;
}

bool FarFromPrimes::isFar(int n)
{
	vector<int> nos;

	for (int i = n - 10; i <= n + 10; ++i)
	{
		nos.push_back(i);
	}

	bool isF = true;
	for (int j = 0; j < nos.size(); ++j)
	{
		if (isPrime(nos[j]))
		{
			isF = false;
			break;
		}
		else
		{
			continue;
		}
	}
	return isF;
}

int FarFromPrimes::count(int A, int B)
{
	int cnt = 0;

	for (int i = A; i <= B; ++i)
	{
		if (isFar(i))
			cnt++;
	}

	return cnt;
}

int main()
{
	FarFromPrimes fo;

	int c = fo.count(3328, 4100);
	return 0;
}