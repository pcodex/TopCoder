// srm239.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <numeric>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

class Barbecue
{
public:
	int eliminate(int n, vector <int> voter, vector <int> excluded);
};

int Barbecue::eliminate(int n, vector <int> voter, vector <int> excluded)
{
	map<int,int> votcnt;

	if (voter.size() == 0 || excluded.size() == 0)
		return 0;

	for (int i = 0; i < voter.size(); ++i)
	{
		votcnt[excluded[i]] += 1;
	}
	
	map<int, int>::iterator mit;
	int highestvote = -1;
	int selectedcand = -1;

	for (mit = votcnt.begin(); mit != votcnt.end(); mit++)
	{
		if (mit->second > highestvote)
		{			
			highestvote = mit->second;
			selectedcand = mit->first;
		}
	}

	vector<int> thetiedcands;
	//identify the tied candidates
	for (mit = votcnt.begin(); mit != votcnt.end(); mit++)
	{
		if (mit->second == highestvote)
			thetiedcands.push_back(mit->first);
	}


	if (thetiedcands.size() == 1)
		return selectedcand;
	else
	{
		//from tied cands select the one who voted the most
		int votedmostcnt = -1;
		int votedmostcand = -1;

		for (int i = 0; i < thetiedcands.size(); ++i)
		{
			if (count(voter.begin(), voter.end(), thetiedcands[i]) > votedmostcnt)
			{
				votedmostcnt = count(voter.begin(), voter.end(), thetiedcands[i]);
				votedmostcand = thetiedcands[i];
			}
		}
				
		vector<int> votedmostcands;

		for (int i = 0; i < thetiedcands.size(); ++i)
		{
			if (count(voter.begin(), voter.end(), thetiedcands[i]) == votedmostcnt)
				votedmostcands.push_back(thetiedcands[i]);
		}

		if (votedmostcands.size() == 1)
			selectedcand = votedmostcand;
		else //too many votedmost candidates. select the lowest index
		{
			selectedcand = votedmostcands[0];
			for (int i = 0; i < votedmostcands.size(); ++i)
			{
				if (votedmostcands[i] < selectedcand)
					selectedcand = votedmostcands[i];
			}
		}

	}
		
	return selectedcand;
}


	int main()
{
	Barbecue bb;
	int n = 5;
	vector<int> v = {};
	vector<int> e = {};
	int o = bb.eliminate(n, v, e);
	return 0;
}

