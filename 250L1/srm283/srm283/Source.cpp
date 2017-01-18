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

class DiagonalDisproportion
{
public:
	int getDisproportion(vector <string> matrix);
};


int DiagonalDisproportion::getDisproportion(vector <string> matrix)
{
	int maind = 0;
	int colld = 0;

	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].length(); ++j)
		{
			if (i == j)
				maind += matrix[i][j]-'0';
			if (j == matrix[i].length() - 1 - i)
				colld += matrix[i][j]-'0';			
		}
	}

	return maind - colld;
}


int main()
{
	DiagonalDisproportion dd;
	vector<string> m = { "190", 
						 "828",
						 "373" };
	int ans = dd.getDisproportion(m);
	return 0;
}