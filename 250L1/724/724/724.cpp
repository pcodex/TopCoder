// 724.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	We have a rectangular board divided into unit square cells. The board is mounted on a wall, with rows going horizontally and columns vertically. Each cell contains at most one box. You are given the current state of the board in the vector <string> board. The elements of board describe the rows of the board from top to bottom. (I.e., board[0] describes the topmost row of the board, and so on.) The characters of board[r] describe the cells in row r from left to right, with '.' being an empty cell and '#' a cell with a box.  Due to gravity, each box will fall down: whenever a cell below a box is empty, the box can fall into that cell. Thus, if you have a column with k boxes, those will eventually occupy the bottommost k cells in that column.  Please return a vector <string> describing the state of the board after all boxes finish falling down.
	Definition
	    
		Class:
		GravityPuzzleEasy
		Method:
		solve
		Parameters:
		vector <string>
		Returns:
		vector <string>
		Method signature:
		vector <string> solve(vector <string> board)
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
			board will contain between 1 and 50 elements, inclusive.
			-
			Each element in board will contain between 1 and 50 characters, inclusive.
			-
			Each element in board will contain the same number of characters.
			-
			Each character in board will be '.' or '#'.
			Examples
			0)

			    
				{"#",
				".",
				"."}
				Returns: {".", ".", "#" }
				This box will fall to the bottom, so we get:
				.
				.
				#
				1)

				    
					{"##",
					".#",
					"#."}
					Returns: {"..", "##", "##" }
					This time we have 2 boxes in each column.
					2)

					    
						{"..#.#",
						"#.#..",
						"...##"}
						Returns: {".....", "..#.#", "#.###" }

						3)

						    
							{"#####",
							"#####",
							"#####",
							"#####"}
							Returns: {"#####", "#####", "#####", "#####" }

							4)

							    
								{"."}
								Returns: {"." }

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <set>

using namespace std;

class GravityPuzzleEasy
{
public:
	vector <string> solve(vector <string> board);
};

vector <string> GravityPuzzleEasy::solve(vector <string> board)
{	
		for (int i = 0; i < board[0].length(); ++i)
		{
			for (int j = 0; j < board.size(); ++j)
			{				
				
				if (board[j][i] == '#')
				{		
					int currz = j + 1;
					int prevz = j;
					while (currz < board.size())
					{						
						if (board[currz][i] == '.') {
							board[currz][i] = '#';
							board[prevz][i] = '.';
							prevz = currz;
						}
						
						currz++;						
					}
				}	
			}
		 }
	

	return board;
}


int main()
{
	GravityPuzzleEasy gp;
	vector<string> brd = { "..#.#",
		"#.#..",
		"...##" };
	vector<string> ap = gp.solve(brd);
    return 0;
}

