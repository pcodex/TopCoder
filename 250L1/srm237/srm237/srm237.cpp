// srm237.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <numeric>

using namespace std;

class Cards
{
public:
	vector <string> deal(int numPlayers, string deck);
};

vector <string> Cards::deal(int numPlayers, string deck)
{

	int stksz = deck.length() / numPlayers;
	vector<string> out;

	for (int i = 0; i < numPlayers; ++i)
	{
		int cnt = i;
		string hand = "";
		int handsz = 0;
		while (cnt < deck.length() && handsz<stksz)
		{			
			hand += deck[cnt];
			cnt += numPlayers;
			handsz++;			
		}

		out.push_back(hand);
	}

	return out;
}


int main()
{
	Cards cc;
	int n = 2;
	string d = "";

	vector<string> ss = cc.deal(n, d);
	return 0;
}

