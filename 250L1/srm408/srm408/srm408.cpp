// srm408.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class TournamentJudging
{
public:
	int getPoints(vector <int> rawScores, vector <int> conversionFactor);
};

int TournamentJudging::getPoints(vector <int> rawScores, vector <int> conversionFactor)
{
	int res = 0;

	for (int i = 0; i < rawScores.size(); ++i)
	{
		float ftres = (float)rawScores[i] / conversionFactor[i];
		int intres = rawScores[i] / conversionFactor[i];

		/*if (abs(ftres - intres) >= 0.5)
			ftres = ftres + 0.5;
		else if (abs(ftres - intres) > 0)
			ftres = ftres - 0.5;*/

		ftres = roundf(ftres);
		res += ftres;
	}

	
	return res;
}

int main()
{
	TournamentJudging tj;
	vector<int> v1 = { 47, 42, 37, 30, 27, 21, 18 };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6, 7 };

	int res = tj.getPoints(v1, v2);
	return 0;
}

