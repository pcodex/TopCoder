// srm406.cpp : Defines the entry point for the console application.
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


class HappyCells
{
	bool is1Happy(vector <string>, int, int);
	bool is2Happy(vector <string>,int, int);
	bool is3Happy(vector <string>,int, int);

public:
	vector <int> getHappy(vector <string> grid);
};

vector <int> HappyCells::getHappy(vector <string> grid)
{
	int happy1 = 0, happy2 = 0, happy3 = 0;

	for (int i = 0; i < grid.size(); ++i)
	{
		size_t pos = 0;
		while ((pos = grid[i].find(".",pos)) != std::string::npos)
		{
			if (pos != std::string::npos)
			{
				if (is1Happy(grid, i, pos))
					happy1++;
				if (is2Happy(grid, i, pos))
					happy2++;
				if (is3Happy(grid, i, pos))
					happy3++;
			}
			pos += 1;
		}
	}

vector<int> vhapp = { happy1, happy2, happy3 };
return vhapp;

}

bool HappyCells::is1Happy(vector <string> gd, int row, int col)
{
	if (gd[row][col] == '.')
	{
		bool orth1 = true, orth2 = true, orth3 = true, orth4 = true;
		//orth check
		if ((row - 1) >= 0)
		{
			if (gd[row - 1][col] == 'X')
				orth1 = true;
			else
				orth1 = false;

		}
		if ((col - 1) >= 0)
		{
			if (gd[row][col - 1] == 'X')
				orth2 = true;
			else
				orth2 = false;
		}

		if ((col + 1) < gd[0].length())
		{
			if (gd[row][col + 1] == 'X')
				orth3 = true;
			else
				orth3 = false;
		}

		if ((row + 1) < gd.size())
		{
			if (gd[row + 1][col] == 'X')
				orth4 = true;
			else
				orth4 = false;
		}

		if (orth1 && orth2 && orth3 && orth4)
		{
			//diag check
			bool diag1 = true, diag2 = true, diag3 = true, diag4 = true;
			if ((row - 1) >= 0)
			{
				if ((col - 1) >= 0)
				{
					if (gd[row - 1][col - 1] == 'X')
						diag1 = true;
					else
						diag1 = false;
				}

				if ((col + 1) < gd[0].length())
				{
					if (gd[row - 1][col + 1] == 'X')
						diag2 = true;
					else
						diag2 = false;
				}
			}

			if ((row + 1) < gd.size())
			{
				if ((col - 1) >= 0)
				{
					if (gd[row + 1][col - 1] == 'X')
						diag3 = true;
					else
						diag3 = false;
				}
				if ((col + 1) < gd[0].length())
				{
					if (gd[row + 1][col + 1] == 'X')
						diag4 = true;
					else
						diag4 = false;
				}
			}

			if (diag1 && diag2 && diag3 && diag4)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


bool HappyCells::is2Happy(vector <string> gd, int row, int col)
{
	bool ret = false;

	if (gd[row][col] == '.')
	{
		bool orth1 = true, orth2 = true, orth3 = true, orth4 = true;
		//orth check
		if ((row - 1) >= 0)
		{
			if (gd[row - 1][col] == 'X')
				orth1 = true;
			else
				orth1 = false;

		}
		if ((col - 1) >= 0)
		{
			if (gd[row][col - 1] == 'X')
				orth2 = true;
			else
				orth2 = false;
		}

		if ((col + 1) < gd[0].length())
		{
			if (gd[row][col + 1] == 'X')
				orth3 = true;
			else
				orth3 = false;
		}

		if ((row + 1) < gd.size())
		{
			if (gd[row + 1][col] == 'X')
				orth4 = true;
			else
				orth4 = false;
		}

		
		if (orth1 && orth2 && orth3 && orth4)//all orth occupied
		{
			//diag check
			int diagcnt = 0;
			if ((row - 1) >= 0)
			{
				if ((col - 1) >= 0)
				{
					if (gd[row - 1][col - 1] == '.')
						diagcnt++;					
				}
				if (diagcnt >= 1)
					ret=true;

				if ((col + 1) < gd[0].length())
				{
					if (gd[row - 1][col + 1] == '.')
						diagcnt++;					
				}
				if (diagcnt >= 1)
					ret=true;
			}

			if ((row + 1) < gd.size())
			{
				if ((col - 1) >= 0)
				{
					if (gd[row + 1][col - 1] == '.')
						diagcnt++;					
				}
				if (diagcnt >= 1)
					ret=true;
		
				if ((col + 1) < gd[0].length())
				{
					if (gd[row + 1][col + 1] == '.')
						diagcnt++;					
				}
				if (diagcnt >= 1)
					ret=true;
			}			
		}
		else
			ret=false;
	}
	else
		ret=false;

	return ret;
}

bool HappyCells::is3Happy(vector <string> gd, int row, int col)
{
	bool ret = false;

		if (gd[row][col] == '.')
		{
			//diag check
			bool diag1 = true, diag2 = true, diag3 = true, diag4 = true;
			if ((row - 1) >= 0)
			{
				if ((col - 1) >= 0)
				{
					if (gd[row - 1][col - 1] == 'X')
						diag1 = true;
					else
						diag1 = false;
				}

				if ((col + 1) < gd[0].length())
				{
					if (gd[row - 1][col + 1] == 'X')
						diag2 = true;
					else
						diag2 = false;
				}
			}

			if ((row + 1) < gd.size())
			{
				if ((col - 1) >= 0)
				{
					if (gd[row + 1][col - 1] == 'X')
						diag3 = true;
					else
						diag3 = false;
				}
				if ((col + 1) < gd[0].length())
				{
					if (gd[row + 1][col + 1] == 'X')
						diag4 = true;
					else
						diag4 = false;
				}
			}

			if (diag1 && diag2 && diag3 && diag4)
			{

				int orthcnt = 0;
				//orth check
				if ((row - 1) >= 0)
				{
					if (gd[row - 1][col] == '.')
						orthcnt++;
				}
				if (orthcnt >= 1)
					ret=true;

				if ((col - 1) >= 0)
				{
					if (gd[row][col - 1] == '.')
						orthcnt++;					
				}
				if (orthcnt >= 1)
					ret=true;

				if ((col + 1) < gd[0].length())
				{
					if (gd[row][col + 1] == '.')
						orthcnt++;					
				}
				if (orthcnt >= 1)
					ret=true;

				if ((row + 1) < gd.size())
				{
					if (gd[row + 1][col] == '.')
						orthcnt++;					
				}
				if (orthcnt >= 1)
					ret=true;
			}
			else
				ret=false;
		}
		else
			ret=false;	

		return ret;
}

int main()
{

	HappyCells hc;
	vector<int> vout;
	vector<string> vin = { "..." };

	vout = hc.getHappy(vin);
	return 0;
}

