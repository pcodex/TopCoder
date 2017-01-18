// srm276.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class TestCurve
{
public:
	vector <int> determineGrades(vector <int> scores);
};

vector <int> TestCurve::determineGrades(vector <int> scores)
{
	vector<int> out;

	int max = *(max_element(scores.begin(), scores.end()));

	for (int i = 0; i < scores.size(); ++i)
	{
		int perc = (double(scores[i]) / max) * 100;

		out.push_back(perc);
	}

	return out;

}

int main()
{
	TestCurve tc;
	vector<int> s = { 1234, 3483, 234, 5738, 3421, 5832, 4433 };
	vector<int> v = tc.determineGrades(s);
	return 0;
}

