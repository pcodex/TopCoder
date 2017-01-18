#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>
#include <numeric>

using namespace std;

class GameOfLifeDivTwo
{
public:
	string theSimulation(string init, int T);
};


string GameOfLifeDivTwo::theSimulation(string init, int T)
{
	string now = init;
	string prev = init;
	for (int i = 0; i < T; ++i)
	{		
		for (int j = 0; j < now.length(); ++j)
		{
			int bef = j - 1;
			if (bef < 0)
				bef = now.length() - 1;

			int aft = j + 1;
			if (aft == now.length())
				aft = 0;

			if (prev[j] == '1')
			{
				if (prev[bef] == '0' && prev[aft] == '0')
					now[j] = '0';
				else
					now[j] = '1';				
			}
			else if (prev[j] == '0')
			{
				if (prev[bef] == '1' && prev[aft] == '1')
					now[j] = '1';
				else
					now[j] = '0';
			}
		 }

		prev = now;
	}

	return now;
}

int main()
{
	GameOfLifeDivTwo gd;
	string ret = gd.theSimulation("111010", 58);
	return 0;
	
}