// srm600.cpp : Defines the entry point for the console application.
//

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

class SRMCards
{
public:
	int maxTurns(vector <int> cards);
};


int SRMCards::maxTurns(vector <int> cards)
{

	sort(cards.begin(), cards.end());
	int noofturns = 0;

	for (int i = 0; i < cards.size(); ++i)
	{
		int thenum = cards[i];
		

		if (thenum == -999)
			continue;
		else
		{
			noofturns++;
			cards[i] = -999;
			int thelft=0, thert=0;
			if (i > 0)
				thelft = cards[i - 1];
			if (i < cards.size()-1)
				thert = cards[i + 1];

			if ((thelft == thenum - 1) && (i > 0))
				cards[i - 1] = -999;
			
			if ((thert == thenum + 1) && (i < cards.size() - 1))
				cards[i + 1] = -999;
		}

	}

	return noofturns;
}


int main()
{
	SRMCards sc;
	vector<int> cds = { 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = sc.maxTurns(cds);
	return 0;
}

	