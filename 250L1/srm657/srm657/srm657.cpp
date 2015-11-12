#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class EightRooks
{
public:
	string isCorrect(vector <string> board);
};


string EightRooks::isCorrect(vector <string> board)
{
	bool incorrect = false;
	int totalrooks = 0;
	for (int i = 0; i < board.size(); ++i)
	{
		int rocnt = count(board[i].begin(), board[i].end(), 'R');
		if (rocnt <= 1)
		{
			if (rocnt == 1)
				totalrooks++;

			continue;
		}

		else
		{
			incorrect = true;
			break;
		}
	}

	if (incorrect)
		return "Incorrect";
	else if ((incorrect == false) && (totalrooks == 8))
		totalrooks = 0;
	else
		return "Incorrect";

	for (int j = 0; j < board[1].length(); ++j)
	{
		int colcnt = 0;
		for (int z = 0; z < board.size(); ++z)
		{
			if (board[z][j] == 'R')
			{
				colcnt++;
			}
		}
		if (colcnt <= 1)
		{
			if (colcnt == 1)
				totalrooks++;

			continue;
		}
		else
		{
			incorrect = true;
			break;
		}
	}

	if (incorrect)
		return "Incorrect";
	else if ((incorrect == false) && (totalrooks == 8))
		return "Correct";
	else
		return "Incorrect";

}


int main()
{
	EightRooks er;
	vector<string> vv = { "........",
		"........",
		"........",
		"........",
		"........",
		"........",
		"........",
		"........" };

	string res = er.isCorrect(vv);
	return 0;
}

