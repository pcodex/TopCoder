// srm666.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class DevuAndGame
{
public:
	string canWin(vector <int> nextLevel);
};

string DevuAndGame::canWin(vector <int> nextLevel)
{
	string op = "Lose";
	int cnt=0, maxcnt = nextLevel.size();
	int currlvl = 0;

	while (cnt<maxcnt)
	{		
		int nxtlvl = nextLevel[currlvl];

		if (nxtlvl == -1)
		{
			op = "Win";
			break;
		}
		else
		{
			currlvl = nxtlvl;
			cnt += 1;
		}
	}

	return op;
}


int main()
{
	DevuAndGame dg;
	//vector<int> vinp = { 0, 1, 2 };
	//vector<int> vinp = { 29, 33, 28, 16, -1, 11, 10, 14, 6, 31, 7, 35, 34, 8, 15, 17, 26, 12, 13, 22, 1, 20, 2, 21, -1, 5, 19, 9, 18, 4, 25, 32, 3, 30, 23, 10, 27 };
	//vector<int> vinp = { 3, 1, 1, 2, -1, 4 };
	vector<int> vinp = { 17, 43, 20, 41, 42, 15, 18, 35, -1, 31, 7, 33, 23, 33, -1, -1, 0, 33, 19, 12, 42, -1, -1, 9, 9, -1, 39, -1, 31, 46, -1, 20, 44, 41, -1, -1, 12, -1, 36, -1, -1, 6, 47, 10, 2, 4, 1, 29 };

	string op = dg.canWin(vinp);
	return 0;
}

