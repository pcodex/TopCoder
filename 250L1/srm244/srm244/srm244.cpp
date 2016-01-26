// srm244.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;


class Grader
{
public:
	vector <int> grade(vector <int> predictedGrades, vector <int> actualGrades);
};


vector <int> Grader::grade(vector <int> predictedGrades, vector <int> actualGrades)
{
	map<int, int> diffcnt;

	for (int i = 0; i < predictedGrades.size(); ++i)
	{
		int thediff = abs(predictedGrades[i] - actualGrades[i]);
		diffcnt[thediff]++;
	}

	vector<int> percent;
	for (int i = 0; i < 7; ++i)
	{
		map<int,int>::iterator mit = diffcnt.find(i);
		if (mit != diffcnt.end())
		{
			int cnt = mit->second;
			int perc = (cnt * 100) / predictedGrades.size();
			percent.push_back(perc);
		}
		else
		{
			percent.push_back(0);
		}
	}

	return percent;
}

int main()
{
	Grader gl;
	vector<int> p = { 1, 5, 7, 3 };
	vector<int> a = { 3, 5, 4, 5 };
	vector<int> o = gl.grade(p, a);

	return 0;
}

