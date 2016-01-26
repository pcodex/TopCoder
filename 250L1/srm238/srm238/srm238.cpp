// srm238.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <math.h>

using namespace std;

class ArrayHash
{
public:
	int getHash(vector <string> input);
};


int ArrayHash::getHash(vector <string> input)
{
	int hash = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		for (int j = 0; j < input[i].length(); ++j)
		{
			hash += (input[i][j] - 65)+i+j;			
		}
	}

	return hash;
}


	int main()
{
	ArrayHash ah;
	vector<string> in = { "CBA",
		"DDD" };

	int sc=ah.getHash(in);
	return 0;
}

