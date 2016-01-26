// srm258.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <cctype>
#include <set>

using namespace std;

class ClassScores
{
public:
	vector <int> findMode(vector <int> scores);
};

vector <int> ClassScores::findMode(vector <int> scores)
{
	int maxcnt = 0;

	vector<int> out;

	for (int i = 0; i < scores.size(); ++i)
	{
		if (count(scores.begin(), scores.end(), scores[i]) > maxcnt)
			maxcnt = count(scores.begin(), scores.end(), scores[i]);
	}

	for (int i = 0; i < scores.size(); ++i)
	{
		if (count(scores.begin(), scores.end(), scores[i]) == maxcnt)
		{
			if (find(out.begin(), out.end(), scores[i]) == out.end())
				out.push_back(scores[i]);
		}
	}

	sort(out.begin(), out.end());

	return out;
}


	int main()
{
	ClassScores ss;

	vector<int> s = { 88, 70, 65, 70, 88 };
	vector<int> outp = ss.findMode(s);

	return 0;
}

