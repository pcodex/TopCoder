// srm407.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class SpiralWalking
{
public:
	int totalPoints(vector <string> levelMap);
};

int SpiralWalking::totalPoints(vector <string> levelMap)
{
	int score = 0;

	bool done = false;
	int rowlo = 0, rowhi = levelMap.size() - 1;
	int collo = 0, colhi = levelMap[0].length()-1;

	int rowidx = rowlo, colidx = collo;

	while (!done)
	{
		//L->R
		while (colidx <= colhi)
		{			
			if (colidx != colhi)
			{
				score += (levelMap[rowidx][colidx]-'0');				
				levelMap[rowidx][colidx] = 'x';				
			}			
			colidx++;
		}		
		colidx -= 1;
		rowidx += 1;
		if (levelMap[rowidx][colidx] == 'x')
		{
			done = true;
			score += (levelMap[rowidx - 1][colidx]-'0');
			break;
		}		
		rowlo = rowlo + 1;
		
		//T->B
		while (rowidx <= rowhi)
		{
			if (rowidx != rowhi)
			{
				score += (levelMap[rowidx][colidx]-'0');				
				levelMap[rowidx][colidx] = 'x';				
			}			
			rowidx++;
		}

		rowidx -= 1;
		colidx -= 1;
		if (levelMap[rowidx][colidx] == 'x')
		{
			done = true;
			score += (levelMap[rowidx][colidx + 1]-'0');
			break;
		}
		colhi = colhi - 1;

		//R->L
		while (colidx >= collo)
		{
			if (colidx != collo)
			{
				score += (levelMap[rowidx][colidx]-'0');
				levelMap[rowidx][colidx] = 'x';				
			}			
			colidx--;
		}

		colidx += 1;
		rowidx -= 1;
		if (levelMap[rowidx][colidx] == 'x')
		{
			done = true;
			score += (levelMap[rowidx + 1][colidx]-'0');
			break;
		}
		
		rowhi = rowhi - 1;


		//B->T
		while (rowidx >= rowlo)
		{
			if (rowidx != rowlo)
			{
				score += (levelMap[rowidx][colidx]-'0');				
				levelMap[rowidx][colidx] = 'x';				
			}			
			rowidx--;
		}

		rowidx += 1;
		colidx += 1;
		if (levelMap[rowidx][colidx] == 'x')
		{
			done = true;
			score += (levelMap[rowidx][colidx - 1]-'0');
			break;
		}
		
		collo = collo + 1;
		rowidx = rowlo, colidx = collo;

		if (levelMap[rowidx][colidx] == 'x')
		{
			done = true;
			break;
		}
	}
	return score;
}


int main()
{
	SpiralWalking wp;
	vector<string> vn = { "86850",
		"76439",
		"15863",
		"24568",
		"45679",
		"71452",
		"05483" };

	int res = wp.totalPoints(vn);
	return 0;
}

