// srm212.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

class YahtzeeScore
{
public:
	int maxPoints(vector <int> toss);
};


int YahtzeeScore::maxPoints(vector <int> toss)
{
	map<int, int> mscore;

	

	for (int i = 0; i < toss.size(); ++i)
	{
		mscore[toss[i]] += 1;
	}

	vector<int> cumuScore;
	for (map<int,int>::iterator it = mscore.begin(); it != mscore.end(); it++)
	{
		int val = (it->first)*(it->second);
		cumuScore.push_back(val);
	}

	sort(cumuScore.begin(), cumuScore.end());

	return cumuScore[cumuScore.size() - 1];
}


int main()
{
	YahtzeeScore ys;

	vector<int> t = { 5, 3, 5, 3, 3 };

	int score = ys.maxPoints(t);
	return 0;
}

