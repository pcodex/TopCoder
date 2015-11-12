// srm651.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class RobotOnMoonEasy
{
public:
	string isSafeCommand(vector <string> board, string S);
};

string RobotOnMoonEasy::isSafeCommand(vector<string> board, string S)
{
	bool found = false;
	string state = "Alive";

	int curri = 0, currj = 0;
	
	while (!found)
	{
		currj = board[curri].find('S');
		if (currj == std::string::npos)
			curri++;
		else
			found = true;
	}

	bool dead = false;
	for (int i = 0; i < S.length(); ++i)
	{
		switch (S[i])
		{
		case 'U':
		{
			if ((curri - 1) >= 0)
			{
				if (board[curri - 1][currj] == '.')
				{
					board[curri][currj] = '.';
					curri -= 1;
					board[curri][currj] = 'S';
				}
			}
			else
			{
				dead = true;				
			}
			break;
		}
		case 'D':
		{
			if ((curri + 1) <= board.size() - 1)
			{
				if (board[curri + 1][currj] == '.')
				{
					board[curri][currj] = '.';
					curri += 1;
					board[curri][currj] = 'S';
				}
			}
			else
			{
				dead = true;
			}
			break;
		}
		case 'L':
		{
			if ((currj - 1) >= 0)
			{
				if (board[curri][currj - 1] == '.')
				{
					board[curri][currj] = '.';
					currj -= 1;
					board[curri][currj] = 'S';
				}
			}
			else
			{
				dead = true;
			}
			break;
		}
		case 'R':
		{
			if (currj + 1 <= board[0].size()-1)
			{
				if (board[curri][currj + 1] == '.')
				{
					board[curri][currj] = '.';
					currj += 1;
					board[curri][currj] = 'S';
				}
			}
			else
			{
				dead = true;
			}
			break;
		}
		default:
			break;
		}
	}

	if (dead)
		state = "Dead";

	return state;
}

int main()
{
	RobotOnMoonEasy rbm;

	

	vector<string> brd = { ".....", "S.##." };

	string cmd = "RLL";

	string state = rbm.isSafeCommand(brd,cmd);
	return 0;
}

