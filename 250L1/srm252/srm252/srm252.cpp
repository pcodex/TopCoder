// srm252.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <stack>

using namespace std;


class WarCry
{
public:
	int alertTime(string outposts);
};

int WarCry::alertTime(string outposts)
{
	vector<int> posAl;
	vector<int> posX;
	int ret = 0;

	for (int i = 0; i < outposts.length(); ++i)
	{
		if (outposts[i] == 'x')
			posAl.push_back(i);
		else
			posX.push_back(i);
	}

	vector<int> times;
	for (int i = 0; i < posX.size(); ++i)
	{
		int themin = 51;
		for (int k = 0; k < posAl.size(); ++k)
		{
			int time = abs(posX[i] - posAl[k]);
			if (time < themin)
				themin = time;
		}
		times.push_back(themin);
	}

	vector<int>::iterator it;
	if (times.size() > 0){
		it = max_element(times.begin(), times.end());
		ret = *it;
	}

	return ret;

}


int main()
{
	WarCry wc;

	string out = "x";
	int max=wc.alertTime(out);
	return 0;
}

