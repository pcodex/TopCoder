// srm661.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class FallingSand
{
public:
	vector <string> simulate(vector <string> board);
};

vector <string> FallingSand::simulate(vector <string> board)
{
	int brdsz = board.size();
	int rowsz = board[0].length();

	for (int i = brdsz - 2; i >= 0; i--)
	{
		for (int j = 0; j < rowsz; j++)
		{
			int cnt = i;
			while ((cnt + 1) <= (brdsz - 1))
			{
				if (board[cnt][j] == 'o')
				{
					if (board[cnt + 1][j] == '.')
					{
						board[cnt + 1][j] = 'o';
						board[cnt][j] = '.';
					}
					if (board[cnt + 1][j] == 'x')
						break;
					
					cnt = cnt + 1;
				}
				else
					break;
			}
		}
	}

	return board;

}

int main()
{
	FallingSand fs;
	vector<string> vs = { "ooooo",
		"..x..",
		"....x",
		".....",
		"....o" };
	vector<string> vop;

	vop = fs.simulate(vs);
	
	return 0;
}

