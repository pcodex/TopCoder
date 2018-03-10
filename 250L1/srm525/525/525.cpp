// 525.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	Fox Ciel is going to take a path to meet her friends. The path is tiled with 1x1 square tiles. It is N tiles long and 2 tiles wide. If we imagine that the path is going from the left to the right, we can view it as a rectangle with 2 rows and N columns of tiles. The rows of the path are numbered 0 to 1 from top to bottom, and the columns of the path are numbered 0 to N-1 from left to right. Ciel starts at the tile in row 0, column 0. She has to reach the tile in row 0, column N-1.

	In each step, Ciel can move to an adjacent tile. Two tiles are adjacent if they share at least one point (a side or a corner).

	Because it rained yesterday, some tiles are covered by puddles of water. Ciel will not step on these tiles. You are given a vector <string> road. The j-th character of i-th element is 'W' if a tile at i-th row of j-th column is covered by water, and '.' otherwise.

	Return the string "YES" if she can move to her destination without entering a tile which is filled with water. Otherwise, return "NO".
	Definition
	    
		Class:
		RainyRoad
		Method:
		isReachable
		Parameters:
		vector <string>
		Returns:
		string
		Method signature:
		string isReachable(vector <string> road)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			The constraints guarantee that the starting tile and the destination tile are never covered by water.
			Constraints
			-
			road will contain exactly 2 elements.
			-
			Each elements of road will contain between 2 and 50 characters, inclusive.
			-
			All elements of road will contain the same number of characters.
			-
			Each character of road will be either '.' or 'W'.
			-
			The first character and the last character of 0-th element of road will be '.'.
			Examples
			0)

			    
				{".W.."
				,"...."}
				Returns: "YES"
				One of the possible ways is as follows. Here, 'F' is the tile occupied by Fox Ciel.
				"FW.."
				"...."

				".W.."
				"F..."

				".W.."
				".F.."

				".W.."
				"..F."

				".W.F"
				"...."
				1)

				    
					{".W.."
					,"..W."}
					Returns: "YES"

					2)

					    
						{".W..W.."
						,"...WWW."}
						Returns: "NO"

						3)

						    
							{".."
							,"WW"}
							Returns: "YES"

							4)

							    
								{".WWWW."
								,"WWWWWW"}
								Returns: "NO"

								5)

								    
									{".W.W.W."
									,"W.W.W.W"}
									Returns: "YES"

									6)

									    
										{".............................................W."
										,".............................................W."}
										Returns: "NO"

										This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class RainyRoad
{
public:
	string isReachable(vector <string> road);
};


string RainyRoad::isReachable(vector <string> road)
{
	bool poss = true;
	int i = 0, j = 0;
	int colmax = road[0].length();
		
	while (poss && i<2 && j<colmax)
	{
		if (i==0 && road[i][j] == '.')
		{
			if (j < colmax-1 && road[i][j + 1] == '.')
				j += 1;
			else if (road[i + 1][j] == '.')
				i += 1;
			else if (j < colmax-1 && road[i + 1][j + 1]=='.')
			{
				i += 1;
				j += 1;
			}
			else 
			{
				poss = false;
				break;
			}
		}
		else if (i == 1 && road[i][j] == '.')
		{
			if (j < colmax - 1 && road[i - 1][j + 1] == '.')
			{
				i -= 1;
				j += 1;
			}
			else if (j < colmax - 1 && road[i][j + 1] == '.')
			{
				j += 1;
			}
			else
			{
				poss = false;
				break;
			}
		}
		if (i == 0 && j == colmax - 1)
			break;
	}

	if (poss)
		return "YES";
	else
		return "NO";
}


int main()
{
	RainyRoad rdl;
	vector<string> rd = { ".............................................W."
		,".............................................W." };

	string out = rdl.isReachable(rd);

    return 0;
}

