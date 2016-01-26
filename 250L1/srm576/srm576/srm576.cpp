// srm576.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class TheExperimentDiv2
{
public:
	vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd);
};

vector <int> TheExperimentDiv2::determineHumidity(vector <int> intensity, int L, vector <int> leftEnd)
{

	vector<int> spongeAbs;
	for (int i = 0; i < leftEnd.size(); ++i)
	{

		int startAt = leftEnd[i];
		int endAt = startAt + L;

		int absrbd = 0;

		for (int j = startAt; j < endAt; ++j)
		{
			if (j > (intensity.size() - 1))
				break;

			absrbd += intensity[j];			
			intensity[j] = 0;
		}

		spongeAbs.push_back(absrbd);
	}

	return spongeAbs;
}


int main()
{
	TheExperimentDiv2 tde;
	vector<int> intns = { 2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13 };
	vector<int> lend = { 1, 7, 4, 5, 8, 0 };
	int lgnt = 4;

	vector<int> res;

	res = tde.determineHumidity(intns, lgnt, lend);

	return 0;
}

