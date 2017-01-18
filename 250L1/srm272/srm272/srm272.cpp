// srm272.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class HammingDistance
{
public:
	int minDistance(vector <string> numbers);
};

int HammingDistance::minDistance(vector <string> numbers)
{
	int minhd = 51;

	for (int i = 0; i < numbers.size()-1; ++i)
	{		
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			int tmpdis = 0;
			for (int z = 0; z < numbers[i].length(); ++z)
			{
				if (numbers[i][z] != numbers[j][z])
					tmpdis++;
			}
			if (tmpdis < minhd)
				minhd = tmpdis;
		}
		
	}

	return minhd;
}


int main()
{
	HammingDistance hd;
	vector<string> n = { "000000", "000111", "111000", "111111" };
	int mindiff = hd.minDistance(n);
	return 0;
}

