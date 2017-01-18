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

class ThreeCardMonte
{
public:
	string position(string swaps);
};

string ThreeCardMonte::position(string swaps)
{
	string init = "JAJ";

	for (int i = 0; i < swaps.size(); ++i)
	{
		if (swaps[i] == 'L')
		{
			char tmp = init[0];
			init[0] = init[1];
			init[1] = tmp;
		}
		else if (swaps[i] == 'R')
		{
			char tmp = init[1];
			init[1] = init[2];
			init[2] = tmp;
		}
		else if (swaps[i] == 'E')
		{
			char tmp = init[2];
			init[2] = init[0];
			init[0] = tmp;
		}
		else
		{
			continue;
		}
	}

	size_t pos = init.find("A");
	if (pos == 0)
		return "L";
	else if (pos == 1)
		return "M";
	else
		return "R";
}

int main()
{
	ThreeCardMonte tm;

	string op = tm.position("FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL");
	return 0;
}

