#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>
#include <functional>

using namespace std;

class Istr
{
public:
	int count(string s, int k);
};

int Istr::count(string s, int k)
{
	map<char, int> mc;

	for (int i = 0; i < s.length(); ++i)
	{
		mc[s[i]] += 1;
	}

	map<char, int>::iterator mit;
	vector<int> thescores;

	for (mit = mc.begin(); mit != mc.end(); mit++)
	{
		thescores.push_back(mit->second);
	}

	sort(thescores.begin(), thescores.end(),greater<int>());
	int thesum = 0;

	for (int i = 0; i < thescores.size(); ++i)
	{
		if (thescores[i] > 0 && k > 0)
		{
			thescores[i] -= 1;
			k -= 1;			
		}

		sort(thescores.begin(), thescores.end(), greater<int>());
		i = -1;

		if (k == 0)
			break;
	}

	for (int i = 0; i < thescores.size(); ++i)
	{
		thesum += (thescores[i] * thescores[i]);
	}
	
	return thesum;
	
}

int main()
{
	Istr o;
	int sc = o.count("wersrsresesrsesrawsdsw", 11);

	return 0;
}