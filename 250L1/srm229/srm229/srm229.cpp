// srm229.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>


using namespace std;

class Highscore
{
public:
	int getRank(vector <int> scores, int newscore, int places);
};

int Highscore::getRank(vector <int> scores, int newscore, int places)
{
	if (scores.size() < places)
	{
		vector<int>::iterator it = scores.begin();

		while ((it != scores.end()) && ((*it)>newscore))
		{
			it++;			
		}
		scores.insert(it, newscore);
	}
	else if (scores.size() == places)
	{
		vector<int>::iterator it = scores.begin();

		while ((it != scores.end()) && ((*it) >= newscore))
		{
			it++;
		}

		if (it == scores.end())
			return -1;

		if ((newscore <= (*it)) && (it == scores.end()-1))
			return -1;
		
		if (newscore >= (*it))
		{
			it = scores.insert(it, newscore);
			scores.erase(scores.end() - 1);
		}
	}

	//new rank

	vector<int>::iterator nit;

	//nit = unique(scores.begin(), scores.end());
	nit = find(scores.begin(), scores.end(), newscore);

	int nwrnk = distance(scores.begin(), nit)+1;
	return nwrnk;

}


int main()
{
	Highscore hs;

	//{{2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000}, 2000000000, 10}

	vector<int> s = { 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000, 2000000000 };
	int n = 2000000000;
	int p = 10;

	int rk = hs.getRank(s, n, p);
	return 0;
}

