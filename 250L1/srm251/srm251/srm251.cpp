// srm251.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class Elections
{
public:
	int visit(vector <string> likelihoods);
};


int Elections::visit(vector <string> likelihoods)
{
	float themin = 101;
	int theidx = 51;

	for (int i = 0; i < likelihoods.size(); ++i)
	{
		int tmpmin = count(likelihoods[i].begin(), likelihoods[i].end(), '1');
		float percent = (tmpmin * 100) /(float)likelihoods[i].length();

		if (percent < themin)
		{
			themin = percent;
			theidx = i;
		}
	}

	return theidx;

}


int main()
{
	Elections eel;
	vector<string> ll = { "111212212221112122122222111212111211111111121121", "122121", "2122212222112", 
							"121221222122221112212211121222121222211222222221", "21221121111111221121211121112112221222", "1121221212", 
							"112122111", "21211121212222211222122211112212", "1", "1", 
							"211222111", "2211212111222112122111211122211221", "121211111121222111111212112221212212", 
							"12122212222112111", "2222221111111211212222121211111121111222112", 
							"222222221211221112122222221212112222", "2211122111211", 
							"2212222122111212112121121211222211221211211122", "212211211121112211", "12122111212112121111222112222121211211112", 
							"2112222111211211112221112221212" };
	
	int id = eel.visit(ll);
	return 0;
}

