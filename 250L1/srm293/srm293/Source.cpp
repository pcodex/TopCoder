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

class Aquarium
{
public:
	int peaceful(int minSize, int maxSize, vector <int> fishSizes);
};

int Aquarium::peaceful(int minSize, int maxSize, vector <int> fishSizes)
{
	int cnt = 0;

	for (int j = minSize; j <= maxSize; ++j)
	{
		bool suited = false;
		for (int i = 0; i < fishSizes.size(); ++i)
		{	
			//Bob smaller
			if (fishSizes[i]>j)
			{
				float min = 2*j;
				float max = 10*j;

				if ((fishSizes[i]<min) || (fishSizes[i]>max))
					suited = true;
				else
				{
					suited = false;
					break;
				}
			}
			//Bob bigger
			else if (j > fishSizes[i])
			{
				float min = 2 * fishSizes[i];
				float max = 10 * fishSizes[i];
				if ((j<min) ||
					(j>max))
				{
					suited = true;
				}
				else
				{
					suited = false;
					break;
				}
			}
			else
			{
				suited = true;
			}
		}
		if (suited)
			cnt++;
	}

	return cnt;
}

int main()
{
	Aquarium a;
	int mn = 1;
	int mx = 791;
		vector<int> f = { 1, 4, 12, 25, 79, 556, 625, 800, 801, 950, 952, 954, 956, 958, 980, 1000 };

	int ret = a.peaceful(mn, mx, f);
	return 0;
}