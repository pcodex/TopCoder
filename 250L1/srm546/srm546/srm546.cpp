// srm546.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class ContestWinner
{
public:
	int getWinner(vector <int> events);
};

int ContestWinner::getWinner(vector <int> events)
{
	map<int, int> contestant;

	for (int i = 0; i < events.size(); ++i)
	{
		contestant[events[i]] += 1;
	}

	map<int, int>::iterator mit;

	int max = 0;

	for (mit = contestant.begin(); mit != contestant.end(); mit++)
	{
		if (mit->second > max)
			max = mit->second;
	}

	map<int, int> cntagain;
	int thewinner;
	for (int i = 0; i < events.size(); ++i)
	{
		cntagain[events[i]] += 1;

		int thecnt = cntagain[events[i]];

		if (thecnt == max)
		{
			thewinner = events[i];
			break;
		}
	}

	return thewinner;

}


int main()
{
	ContestWinner cw;
	vector<int> vs = { 123, 123, 456, 456, 456, 123 };

	int win = cw.getWinner(vs);

	return 0;
}

