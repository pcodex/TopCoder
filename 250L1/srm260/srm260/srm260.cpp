// srm260.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <stack>
#include <sstream>

using namespace std;

class IsingModel
{
public:
	int energy(vector <string> spins);
};

int IsingModel::energy(vector <string> spins)
{
	int sum = 0;
	for (int i = 0; i < spins.size(); ++i)
	{
		for (int j = 0; j < spins[i].length()-1; ++j)
		{
			if ((spins[i][j] == '+' && spins[i][j + 1] == '-') ||
				(spins[i][j] == '-' && spins[i][j + 1] == '+'))
			{
				sum += 1;
			}
			else
			{
				sum -= 1;
			}
		}
	}

	for (int i = 0; i < spins[0].length(); ++i)
	{
		for (int j = 0; j < spins.size() - 1; ++j)
		{
			if ((spins[j][i] == '+' && spins[j+1][i] == '-') ||
				(spins[j][i] == '-' && spins[j+1][i] == '+'))
			{
				sum += 1;
			}
			else
			{
				sum -= 1;
			}
		}
	}

	return sum;
}


int main()
{
	IsingModel ism;

	vector<string> sp = { "----",
		"---+",
		"-+++",
		"++++" };
	int out = ism.energy(sp);
	return 0;
}

