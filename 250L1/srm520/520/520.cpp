// 520.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class SRMRoomAssignmentPhase
{
public:
	int countCompetitors(vector <int> ratings, int K);
};

int SRMRoomAssignmentPhase::countCompetitors(vector <int> ratings, int K)
{
	int myrat = ratings[0];
	sort(ratings.begin(), ratings.end());
	reverse(ratings.begin(), ratings.end());

	vector<int>::iterator pos = find(ratings.begin(), ratings.end(),myrat);
	int mypos = distance(ratings.begin(), pos);

	vector< vector<int> > vr(K);
	int noofpred = 0;

	for (int i = 0; i < ratings.size(); ++i)
	{	
		if (i == mypos && ratings[i] == myrat)
		{
			noofpred = vr[i%K].size();
			break;
		}
		vr[i%K].push_back(ratings[i]);		
			
	}

	return noofpred;

}

int main()
{
	SRMRoomAssignmentPhase sa;
	vector<int> r = { 1197, 1198, 1196, 1195, 1199 };
	int K = 1;
	int ans = sa.countCompetitors(r, K);
    return 0;
}

