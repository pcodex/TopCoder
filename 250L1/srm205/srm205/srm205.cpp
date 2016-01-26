// srm205.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <algorithm>

using namespace std;

class Average
{
public:
	int belowAvg(vector <int> math, vector <int> verbal);
};

int Average::belowAvg(vector <int> math, vector <int> verbal)
{
	float compAvg = 0;
	int mv = 0;

	for (int i = 0; i < math.size(); ++i)
	{
		mv += math[i] + verbal[i];
	}

	compAvg = float(mv) / math.size();

	int cnt = 0;

	for (int i = 0; i < math.size(); ++i)
	{
		if ((math[i] + verbal[i]) < compAvg)
			cnt++;
	}

	return cnt;
}

int main()
{
	Average avg;

	vector<int> m = { 400, 400, 400, 400, 400, 400, 401 }, v = { 400, 400, 400, 400, 400, 400, 400 };
	int noOfChi = avg.belowAvg(m, v);

	return 0;
}

