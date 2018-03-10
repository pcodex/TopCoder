// 523.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	You are given a 2-dimensional matrix of characters represented by the vector <string> letterMaze. The i-th character of the j-th element of letterMaze represents the character at row i and column j. Each of the 26 letters from 'A' to 'Z' appears exactly once in letterMaze, the remaining characters are periods ('.').  An alphabet path is a sequence of 26 elements of the matrix such that:
	The first element contains the letter 'A'.
	The first element and the second element are (horizontally or vertically) adjacent.
	The second element contains the letter 'B'.
	The second element and the third element are (horizontally or vertically) adjacent.
	...
	The 25-th element and the 26-th element are (horizontally or vertically) adjacent.
	The last, 26-th element contains the letter 'Z'.
	Given letterMaze return string "YES" if the alphabet path exists in the matrix and "NO" otherwise.
	Definition
	    
		Class:
		AlphabetPath
		Method:
		doesItExist
		Parameters:
		vector <string>
		Returns:
		string
		Method signature:
		string doesItExist(vector <string> letterMaze)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			Formally, elements (x1,y1) and (x2,y2) are horizontally or vertically adjacent if and only if abs(x1 - x2) + abs(y1 - y2) = 1.
			Constraints
			-
			letterMaze will contain between 1 and 50 elements, inclusive.
			-
			Each element of letterMaze will contain between 1 and 50 characters, inclusive.
			-
			All the elements of letterMaze will contain the same number of characters.
			-
			Each element of letterMaze will only contain uppercase letters ('A'-'Z') and periods ('.').
			-
			Each uppercase letter from 'A' to 'Z' will appear exactly once in letterMaze.
			Examples
			0)

			    
				{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
				Returns: "YES"
				Simply go from left to right.
				1)

				    
					{"ADEHI..Z",
					"BCFGJK.Y",
					".PONML.X",
					".QRSTUVW"}
					Returns: "YES"

					2)

					    
						{"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}
						Returns: "NO"

						3)

						    
							{"ABC.......",
							"...DEFGHIJ",
							"TSRQPONMLK",
							"UVWXYZ...."}
							Returns: "NO"
							The cells marked with C and D are not adjacent, it is impossible to make an alphabet path in this case.
							4)

							    
								{"..............",
								"..............",
								"..............",
								"...DEFGHIJK...",
								"...C......L...",
								"...B......M...",
								"...A......N...",
								"..........O...",
								"..ZY..TSRQP...",
								"...XWVU.......",
								".............."}
								Returns: "YES"

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <math.h>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <sstream>
#include <cctype>

using namespace std;

class AlphabetPath
{
	vector<int> getPos(char c, vector<string> lm);
public:
	string doesItExist(vector <string> letterMaze);

};

string AlphabetPath::doesItExist(vector <string> letterMaze)
{
	bool yespath = true;
	char c = 'A';

	while (yespath && c<'Z')
	{
		vector<int> p1 = getPos(c,letterMaze);
		vector<int> p2 = getPos(c + 1, letterMaze);
		if (p1.size() > 0 && p2.size()>0)
		{
			if (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) == 1) {
				c += 1;
				continue;
			}
			else {
				yespath = false;
				break;
			}
		}
	}
	return (yespath ? "YES" : "NO");		
}

vector<int> AlphabetPath::getPos(char c, vector<string> lm)
{
	vector<int> lpos;

	for (int i = 0; i < lm.size(); ++i)
	{
		size_t pos = lm[i].find(c);
		if (pos != std::string::npos)
		{
			lpos.push_back(i);
			lpos.push_back(pos);
			break;
		}
	}
	return lpos;
}


int main()
{
	AlphabetPath apb;
	vector<string> lm = { "..............",
		"..............",
		"..............",
		"...DEFGHIJK...",
		"...C......L...",
		"...B......M...",
		"...A......N...",
		"..........O...",
		"..ZY..TSRQP...",
		"...XWVU.......",
		".............." };
	string out = apb.doesItExist(lm);
    return 0;
}

