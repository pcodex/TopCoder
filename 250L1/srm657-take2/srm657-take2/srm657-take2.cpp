// srm657-take2.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <numeric>
#include <set>

using namespace std;

class EightRooks
{
public:
	string isCorrect(vector <string> board);
};

string EightRooks::isCorrect(vector <string> board)
{
	int row, col;
	set<int> rows;
	set<int> cols;
	string isCorr = "Incorrect";
	bool tooMany = false;
	
	for (int i = 0; i < board.size(); ++i)
	{
		size_t pos = 0;
		while ((pos = board[i].find('R',pos)) != std::string::npos)
		{
			if (pos != std::string::npos)
			{
				row = i;
				col = pos;

				pair<set<int>::iterator,bool> p1 = rows.insert(row);
				if (p1.second == false)
				{
					tooMany = true;
					break;
				}
				
				pair<set<int>::iterator, bool> p2 = cols.insert(col);
				if (p2.second == false)
				{
					tooMany = true;
					break;
				}
			}			
			pos = pos + 1;		
		}
		if (tooMany == true)
			break;
	}

	if (rows.size() == 8)
	{
		if ((cols.size() == 8) && 
			tooMany==false)
		{
			isCorr = "Correct";
		}
	}

	return isCorr;
}

int main()
{
	EightRooks e;
	vector<string> brd = { "RR......", 
						   ".R......", 
						   "..R.....", 
						   "...R....", 
						   "....R...", 
						   ".....R..", 
						   "......R.", 
						   ".......R" };
		
	string op = e.isCorrect(brd);

	return 0;
}

