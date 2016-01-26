// srm256.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class GridGenerator
{
public:
	int generate(vector <int> row, vector <int> col);
};

int GridGenerator::generate(vector <int> row, vector <int> col)
{
	vector< vector<int> > out(row.size(),vector<int>(col.size()));	

	for (int i = 0; i < row.size(); ++i)
	{
		for (int k = 0; k < col.size(); ++k)
		{
			if (i == 0)
				out[i][k] = row[k];
			else if (k == 0)
				out[i][k] = col[i];
			else
			{
				out[i][k] = out[i][k - 1] + out[i - 1][k] + out[i - 1][k - 1];
			}
		}
	}

	return out[row.size() - 1][col.size() - 1];
}


int main()
{
	GridGenerator gg;
	vector<int> r = { 1, 0, 3, 4, 1 };
	vector<int> c = { 1, 4, 1, 0, 3 };
	int fg = gg.generate(r, c);
	return 0;
}

