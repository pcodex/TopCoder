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


class CoinFlipsDiv2
{
public:
	int countCoins(string state);
};

int CoinFlipsDiv2::countCoins(string state)
{
	int diffcnt = 0;
	int sz = state.length();

	if (sz > 1)
	{

		for (int i = 0; i < state.length(); ++i)
		{
			if (i == 0)
			{
				if (state[i + 1] != state[i])
					diffcnt++;
			}
			else if (i == state.length() - 1)
			{
				if (state[sz - 1] != state[sz - 2])
					diffcnt++;
			}
			else
			{
				if ((state[i - 1] != state[i]) ||
					(state[i + 1] != state[i]))
				{
					diffcnt++;
				}
			}
		}
	}

	return diffcnt;
}


int main()
{
	CoinFlipsDiv2 cf;

	int cnt = cf.countCoins("HT");

	return 0;
}