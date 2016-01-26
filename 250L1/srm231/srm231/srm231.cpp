// srm231.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class GolfScore
{	
public:
	int tally(vector <int> parValues, vector <string> scoreSheet);
};


int GolfScore::tally(vector <int> parValues, vector <string> scoreSheet)
{
	int score = 0;
	for (int i = 0; i < parValues.size(); ++i)
	{
		if (scoreSheet[i].find("triple") != std::string::npos)
		{
			score += parValues[i] + 3;
		}
		else if (scoreSheet[i].find("double") != std::string::npos)
		{
			score += parValues[i] + 2;
		}
		else if (scoreSheet[i].find("bogey") != std::string::npos)
		{
			score += parValues[i] + 1;
		}
		else if (scoreSheet[i].find("par") != std::string::npos)
		{
			score += parValues[i];
		}
		else if (scoreSheet[i].find("birdie") != std::string::npos)
		{
			score += parValues[i] - 1;
		}
		else if (scoreSheet[i].find("eagle") != std::string::npos)
		{
			score += parValues[i] - 2;
		}
		else if (scoreSheet[i].find("alba") != std::string::npos)
		{
			score += parValues[i] - 3;
		}
		else if (scoreSheet[i].find("hole") != std::string::npos)
		{
			score += 1;
		}		
	}

	return score;
}


	int main()
{
	GolfScore gs;

	vector<int> p = { 3, 2, 4, 2, 2, 1,
		1, 1, 3, 2, 4, 4,
		4, 2, 3, 1, 3, 2 };

	vector<string> s = { "eagle", "birdie", "albatross", "birdie", "birdie", "par",
		"hole in one", "par", "eagle", "birdie", "albatross", "albatross",
		"albatross", "birdie", "eagle", "hole in one", "eagle", "birdie" };

	int score = gs.tally(p, s);
	return 0;
}

