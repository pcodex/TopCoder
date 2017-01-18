#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class BootsExchange
{
public:
	int leastAmount(vector<int> left, vector<int> right);
};

int BootsExchange::leastAmount(vector<int> left, vector<int> right)
{
	for (int i = 0; i < left.size(); ++i)
	{
		for (int k = 0; k < right.size(); ++k)
		{
			if (left[i] == right[k])
			{
				vector<int>::iterator it1, it2;
				it1 = find(left.begin(), left.end(), left[i]);
				it2 = find(right.begin(), right.end(), right[k]);
				if (it1 != left.end())
					left.erase(it1);
				if (it2 != right.end())
					right.erase(it2);

				i = -1;
				break;
			}
		}
	}

	return left.size();

}


int main()
{
	BootsExchange bex;
	vector<int> l = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> r = { 2, 4, 6, 1, 3, 7, 5 };

	int out = bex.leastAmount(l, r);

	return 0;
}