// srm268.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class CrossWordPuzzle
{
public:
	int countWords(vector <string> board, int size);
};

int CrossWordPuzzle::countWords(vector <string> board, int size)
{
	string tofind = string(size, '.');
	int cnt = 0;

	for (int i = 0; i < board.size(); ++i)
	{
		int pos = 0;
		while ((pos = board[i].find(tofind, pos)) != std::string::npos)
		{
			if (board[i][pos + size] != '.')
			{	
				cnt += 1;		
				pos += size;
			}
			else
			{
				pos += size;
				while (pos < board[i].length() && board[i][pos] == '.')
					pos += 1;
			}			
		}
	}

	return cnt;
}


int main()
{
	CrossWordPuzzle cp;
	vector<string> b = { ".....X....X....",
		".....X....X....",
		"..........X....",
		"....X....X.....",
		"...X....X....XX",
		"XXX...X....X...",
		".....X....X....",
		".......X.......",
		"....X....X.....",
		"...X....X...XXX",
		"XX....X....X...",
		".....X....X....",
		"....X..........",
		"....X....X.....",
		"....X....X....." };
	
	int s = 5;

	int cnt = cp.countWords(b, s);
	return 0;
}

