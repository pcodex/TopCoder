// srm655.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BichromeBoard
{
public:
	string ableToDraw(vector <string> board);
};


string BichromeBoard::ableToDraw(vector <string> board)
{
	bool notp = false;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j != board[i].length(); j++)
		{
			if (i == 0)
			{
				if ((j + 1) != board[i].length())
				{
					if (board[i][j] == 'W' && board[i][j + 1] == 'W')
					{
						notp = true;
						break;
					}
					if (board[i][j] == 'W' && board[i][j + 1] == '?')
					{
						board[i][j + 1] = 'B';
					}
					if (board[i][j] == 'B' && board[i][j + 1] == 'B')
					{
						notp = true;
						break;
					}
					if (board[i][j] == 'B' && board[i][j + 1] == '?')
					{
						board[i][j + 1] = 'W';
					}
					if (board[i][j] == '?' && board[i][j + 1] == 'W')
					{
						board[i][j] = 'B';
					}
					if (board[i][j] == '?' && board[i][j + 1] == 'B')
					{
						board[i][j] = 'W';
					}
				}
			}
			else
			{
				if (board[i - 1][j] == 'B')
				{
					if (board[i][j] == 'B')
					{
						notp = true;
						break;
					}
					if (board[i][j] == '?')
					{
						board[i][j] = 'W';
					}

					if ((j + 1) != board[i].length())
					{
						if (board[i][j] == 'W' && board[i][j + 1] == 'W')
						{
							notp = true;
							break;
						}
						if (board[i][j] == 'W' && board[i][j + 1] == '?')
						{
							board[i][j + 1] = 'B';
						}
					}
				}
				else if (board[i - 1][j] == 'W')
				{
					if (board[i][j] == 'W')
					{
						notp = true;
						break;
					}
					if (board[i][j] == '?')
					{
						board[i][j] = 'B';
					}

					if ((j + 1) != board[i].length())
					{
						
						if (board[i][j] == 'B' && board[i][j + 1] == 'B')
						{
							notp = true;
							break;
						}
						if (board[i][j] == 'B' && board[i][j + 1] == '?')
						{
							board[i][j + 1] = 'W';
						}
					}
				}
			}
		}
		if (notp)
			break;
	}
	
	if (notp)
		return "Impossible";
	else
		return "Possible";

}



int main()
{
	BichromeBoard bbr;

	vector<string> ss = { "B" };


	string sol = bbr.ableToDraw(ss);

	return 0;
}

