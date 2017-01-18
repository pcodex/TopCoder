// srm277.cpp : Defines the entry point for the console application.
//

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

class SandwichBar
{
public:
	int whichOrder(vector <string> available, vector <string> orders);
};


int SandwichBar::whichOrder(vector <string> available, vector <string> orders)
{
	
	for (int i = 0; i < orders.size(); ++i)
	{
		stringstream ss(orders[i]);

		string myings;
		vector<string> needed;
	
		while (ss >> myings)
		{
			needed.push_back(myings);
		}

		for (int j = 0; j < needed.size(); ++j)
		{
			for (int k = 0; k < available.size(); ++k)
			{
				if (needed[j] == available[k])
				{
					needed.erase(needed.begin() + j);
					j -= 1;
					break;
				}

				if (needed.size() == 0)
					break;
			}

			if (needed.size() == 0)
				break;
		}
		if (needed.size() == 0)
			return i;
	}

	return -1;

	


}


int main()
{
	SandwichBar sb;

	vector<string> a = { "foo", "bar", "baz", "gazonk", "quux", "bat", "xyzzy",
		"shme", "hukarz", "grault", "waldo", "bleh" };
	vector<string> o = { "kalatehas", "spam eggs", "needle haystack", "bleh blarg", "plugh",
		"the best sandwich in the universe" };
	int idx = sb.whichOrder(a, o);
	return 0;
}

