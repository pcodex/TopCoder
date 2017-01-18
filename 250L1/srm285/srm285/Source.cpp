#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class BasketsWithApples
{
public:
	int removeExcess(vector <int> apples);
};

int BasketsWithApples::removeExcess(vector <int> apples)
{	
	
	vector<int> rnd2 = apples;
	int avg = 0;

	int newtot = 0;
	while (rnd2.size() > 0)
	{
		avg = *(min_element(rnd2.begin(), rnd2.end()));

		if (avg*rnd2.size() > newtot)
			newtot = avg*rnd2.size();

		for (int i = 0; i < rnd2.size(); ++i)
		{
			if (rnd2[i] <= avg)
			{
				rnd2.erase(rnd2.begin() + i);
				i -= 1;
			}
		}
	}
	
	return newtot;
	
}


int main()
{
	BasketsWithApples ba;
	vector<int> a = { 34, 90, 39, 2, 75, 47, 57 };
	int ans = ba.removeExcess(a);

	return  0;
}