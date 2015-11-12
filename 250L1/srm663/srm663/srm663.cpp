// srm663.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;


class ChessFloor
{
public:
	int minimumChanges(vector <string> floor);
};

int ChessFloor::minimumChanges(vector <string> floor)
{
	map<char,int> mm;

	vector<string> origfloor = floor;

	for (int i = 0; i < floor.size(); i++)
	{
		for (int j = 0; j < floor[i].length(); ++j)
		{
			mm[floor[i][j]] += 1;
		}
	}
	
	

	int max1 = 0, max2 = 0;
	char maxc1='a',maxc2='a';

	map<char, int>::iterator nit;
	for (nit = mm.begin(); nit != mm.end();nit++)
	{
		if (max1 < nit->second)
		{
			max2 = max1;
			maxc2 = maxc1;
			max1 = nit->second;
			maxc1 = nit->first;
		}
	}
	
	char startrow,next;
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < floor.size(); i++)
	{		
		if (i % 2 == 0)
		{
			startrow = maxc1;
			next = maxc2;
		}
		else
		{
			startrow = maxc2;
			next = maxc1;
		}

		for (int j = 0; j < floor[i].length(); ++j)
		{			
			if (j % 2 == 0)
			{
				if (floor[i][j] == startrow)
					continue;
				else{
					floor[i][j] = startrow;
					cnt1++;
				}
			}
			else
			{
				if (floor[i][j] == next)
					continue;
				else{
					floor[i][j] = next;
					cnt1++;
				}
			}
		}
	}

	floor = origfloor;

	for (int i = 0; i < floor.size(); i++)
	{
		if (i % 2 == 0)
		{
			startrow = 'o';
			next = 'd';
		}
		else
		{
			startrow = 'd';
			next = 'o';
		}

		for (int j = 0; j < floor[i].length(); ++j)
		{
			if (j % 2 == 0)
			{
				if (floor[i][j] == startrow)
					continue;
				else{
					floor[i][j] = startrow;
					cnt2++;
				}
			}
			else
			{
				if (floor[i][j] == next)
					continue;
				else{
					floor[i][j] = next;
					cnt2++;
				}
			}
		}
	}

	return min(cnt1,cnt2);
}

int main()
{
	vector<string> vv = { "helloand",
		"welcomet",
		"osingler",
		"oundmatc",
		"hsixhund",
		"redandsi",
		"xtythree",
		"goodluck" };

	ChessFloor cf;
	int mini = cf.minimumChanges(vv);

	return 0;
}

