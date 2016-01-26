// srm254.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>

using namespace std;

class BalancedGame
{
public:
	int result(vector <string> conflicts, int p, int q);
};

int BalancedGame::result(vector <string> conflicts, int p, int q)
{
	int num = conflicts.size();

	float win = ceil(float((num - 1)*p) / 100);
	float loss = ceil(float((num - 1)*q) / 100);
	int ret = -1;

	for (int i = 0; i < conflicts.size(); ++i)
	{
		int w = count(conflicts[i].begin(), conflicts[i].end(), 'W');
		int l = count(conflicts[i].begin(), conflicts[i].end(), 'L');
		
		if ((w >= win) && (l >= loss))
			continue;
		else
		{
			ret = i;
			break;
		}
	}

	return ret;
}


int main()
{
	BalancedGame bg;
	vector<string> c = { "TLLLLLTWWWWTLLWWWT",
		"WTTWTTLLWLLWWLTLWW",
		"WTTWWTLWTWLWWWWLTW",
		"WLLTLTWWWTWLWLLWLT",
		"WTLWTLWWWWLLWLLWTW",
		"WTTTWTWLLWTLLWWWLW",
		"TWWLLLTLLWTWWWLLWW",
		"LWLLLWWTWLLWWLLLWT",
		"LLTLLWWLTTWLTWTLWT",
		"LWLTLLLWTTTLLLLWTW",
		"LWWLWTTWLTTTLLWWLL",
		"TLLWWWLLWWTTLWTTLL",
		"WLLLLWLLTWWWTWLLWW",
		"WWLWWLLWLWWLLTTWLL",
		"LTLWWLWWTWLTWTTTWT",
		"LWWLLLWWWLLTWLTTLW",
		"LLTWTWLLLTWWLWLWTW",
		"TLLTLLLTTLWWLWTLLT" };

	int p = 18;
	int q = 6;
	int ret = bg.result(c, p, q);
	return 0;
}

