#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

class MakingPairs
{
public:
	int get(vector <int> card);
};

int MakingPairs::get(vector <int> card)
{
	int pairs = 0;

	for (int i = 0; i < card.size(); ++i)
	{
		pairs += card[i] / 2;
	}

	return pairs;
}

int main()
{
	MakingPairs ml;
	vector<int> pp = { 43, 23, 10, 39, 39, 22, 22, 0, 3, 4, 3, 2 };
	int res = ml.get(pp);

	return 0;
}