// 725.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	You have an 8x8 chessboard. Each cell is either empty or contains a single rook. You are given a description of the chessboard in the vector <string> board. Empty cells are represented by '.' (period), rooks are represented by 'R'.
	You would like to know the maximum number of rooks that appear in the same row or in the same column. Return this count.
	Definition
	    
		Class:
		FiveRooksDiv2
		Method:
		findMax
		Parameters:
		vector <string>
		Returns:
		int
		Method signature:
		int findMax(vector <string> board)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			256
			Stack limit (MB):
			256
			Constraints
			-
			board will have exactly 8 elements.
			-
			Each element of board will have exactly 8 characters.
			-
			Each character of board will be '.' or 'R'.
			Examples
			0)

			    
				{
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR",
				"RRRRRRRR"
				}
				Returns: 8

				1)

				    
					{
					"R......R",
					".R....R.",
					"..R..R..",
					"...RR...",
					"...RR...",
					"..R..R..",
					".R....R.",
					"R......R"
					}
					Returns: 2

					2)

					    
						{
						"R.R.R.RR",
						"........",
						"R.R.R.RR",
						"........",
						"........",
						"........",
						"R.R.R.RR",
						"........"
						}


						Returns: 5

						3)

						    
							{
							"R.R.R.RR",
							"........",
							"R.R.R.RR",
							"R.R.R.RR",
							"R.R.R.RR",
							"R.R.R.RR",
							"R.R.R.RR",
							"........"
							}
							Returns: 6

							4)

							    
								{
								"........",
								"........",
								"........",
								"........",
								"........",
								"........",
								"........",
								"........"
								}
								Returns: 0

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class FiveRooksDiv2
{
public:
	int findMax(vector <string> board);
};

int FiveRooksDiv2::findMax(vector <string> board)
{
	int max = 0;

	for (int i = 0; i < board.size(); ++i)
	{
		int cnt = 0;
		if ((cnt = count(board[i].begin(), board[i].end(), 'R')) > max)
			max = cnt;
	}

	for (int col = 0; col < board[0].length(); ++col)
	{
		int vcnt = 0;
		for (int ro = 0; ro < board.size(); ++ro)
		{
			if (board[ro][col] == 'R')
				vcnt++;
		}
		if (vcnt > max)
			max = vcnt;
	}

	return max;
}


int main()
{
	FiveRooksDiv2 fs;
	vector<string> vs = {
		"R.R.R.RR",
		"........",
		"R.R.R.RR",
		"R.R.R.RR",
		"R.R.R.RR",
		"R.R.R.RR",
		"R.R.R.RR",
		"........"
	};

	int cnt = fs.findMax(vs);
    return 0;
}

