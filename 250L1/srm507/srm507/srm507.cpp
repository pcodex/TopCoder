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


class CubeAnts
{
public:
	int getMinimumSteps(vector <int> pos);
};

int CubeAnts::getMinimumSteps(vector <int> pos)
{
	int max = 0;
	for (int i = 0; i < pos.size(); ++i)
	{
		int tmp = 0;
		if (pos[i] == 1 || pos[i] == 3 || pos[i] == 4)
			tmp = 1;
		else if (pos[i] == 5 || pos[i] == 7 || pos[i]==2)
			tmp = 2;
		else if (pos[i]==6)
			tmp = 3;

		if (tmp > max)
			max = tmp;
	}
	return max;
}

int main()
{
	return 0;
}