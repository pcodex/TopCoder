// srm243.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <math.h>

using namespace std;

class ComputationalComplexity
{
public:
	int fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N);
};

int ComputationalComplexity::fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N)
{
	vector<float> op;

	for (int i = 0; i < power.size(); ++i)
	{
		float val = constant[i] * (pow(N, power[i]));

		float logval=1;

		for (int j = 0; j < logPower[i]; ++j)
		{
			logval *= log(N);
		}

		val *= logval;
		op.push_back(val);
	}

	vector<float>::iterator it = min_element(op.begin(), op.end());
	int idx = distance(op.begin(), it);

	return idx;
}


int main()
{
	ComputationalComplexity cc;
	vector<int> co = { 32, 33, 58, 93, 8, 27, 43, 69, 95, 77,
		57, 73, 87, 87, 50, 92, 67, 20, 2, 46,
		73, 48, 25, 90, 48, 18, 28, 26, 20, 33,
		59, 48, 69, 4, 19, 13, 10, 78, 55, 90 };
	vector<int> po = { 5, 0, 1, 4, 0, 3, 5, 4, 3, 3,
		0, 5, 0, 5, 5, 3, 0, 4, 1, 1,
		4, 0, 2, 4, 0, 0, 3, 2, 0, 0,
		4, 3, 5, 0, 2, 4, 3, 4, 3, 0 };

	vector<int> lop = { 2, 2, 2, 0, 4, 5, 2, 3, 4, 5,
		0, 0, 1, 4, 2, 5, 2, 4, 5, 0,
		5, 4, 3, 0, 4, 1, 1, 3, 3, 0,
		1, 5, 2, 1, 1, 4, 0, 0, 2, 3 };
	int n = 1000;
	int out = cc.fastestAlgo(co, po, lop, n);
	return 0;
}

