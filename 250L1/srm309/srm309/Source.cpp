#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class ContestCoordinator
{
public:
	double bestAverage(vector<int> scores);
};

double ContestCoordinator::bestAverage(vector<int> scores)
{
	vector<double> avgs;
	int sz = scores.size();
	sort(scores.begin(), scores.end());
	
	for (int k = 0; k <= sz / 2; ++k)
	{
		double sum = 0;
		for (int i = k; i < sz - k; ++i)
		{
			sum += scores[i];
		}
		avgs.push_back(sum / (sz - (2*k)));
	}

	if (avgs.size() > 0)
		return *max_element(avgs.begin(), avgs.end());
	else
		return scores[0];
}

int main()
{
	ContestCoordinator cc;
	vector<int> sc = { 1, 4, 1, 1, 2, 10, 6, 4, 8, 6, 6, 3, 3, 9, 2, 2, 5, 3, 4, 9, 9, 10, 9, 4, 7, 7, 4, 10, 10, 9, 9, 6, 4, 5, 3, 10, 8, 9, 9, 9, 4, 5, 1 };
	double bes = cc.bestAverage(sc);
	return 0;
}
