// srm259.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class CompetitionStatistics
{
public:
	int consecutiveGrowth(vector <int> ratingChanges);
};

int CompetitionStatistics::consecutiveGrowth(vector <int> ratingChanges)
{
	int cnt = 0;
	int highRatChg = 0;
	//vector<int> chgs;

	for (int i = 0; i < ratingChanges.size(); ++i)
	{
		if (ratingChanges[i]>0)
			cnt++;
		else
		{
			if (cnt > highRatChg)
			{
				highRatChg = cnt;
			}
			cnt = 0;
		}
	}

	if (cnt > highRatChg)
		highRatChg = cnt;

	/*for (int i = 0; i < ratingChanges.size(); ++i)
	{
		if (ratingChanges[i]>0)
			cnt++;
		else
		{
			chgs.push_back(cnt);
			cnt = 0;
		}
	}

	if (cnt != 0)
		chgs.push_back(cnt);

	if (chgs.size() > 0){
		vector<int>::iterator it = max_element(chgs.begin(), chgs.end());
		highRatChg = *it;
	}*/

	return highRatChg;
}


int main()
{
	CompetitionStatistics csl;
	vector<int> rc = { 30, 5, -5, 3, 3, 1 };
	int ans = csl.consecutiveGrowth(rc);
	
	return 0;
}

