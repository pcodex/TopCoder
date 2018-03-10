// 528.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	A palindrome is a string that reads the same from left to right as it does from right to left.

	You are given a string s. The length of s is even. Each character of s is either 'o', 'x', or '?' Your task in this problem is to replace each occurrence of '?' in s with either 'o' or 'x' so that s becomes a palindrome. You are also given ints oCost and xCost. Replacing '?' with 'o' costs oCost, and replacing '?' with 'x' costs xCost.

	Return the minimum cost of replacing '?'s by 'x's and 'o's that turns s into a palindrome. If it is impossible to obtain a palindrome, return -1 instead.
	Definition
	    
		Class:
		MinCostPalindrome
		Method:
		getMinimum
		Parameters:
		string, int, int
		Returns:
		int
		Method signature:
		int getMinimum(string s, int oCost, int xCost)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			You are not allowed to change an 'x' into an 'o' or vice versa.
			Constraints
			-
			s will contain between 2 and 20 characters, inclusive.
			-
			The length of s will be even.
			-
			Each character of s will be either 'o' or 'x' or '?'.
			-
			oCost will be between 1 and 50, inclusive.
			-
			xCost will be between 1 and 50, inclusive.
			Examples
			0)

			    
				"oxo?xox?"
				3
				5
				Returns: 8
				The only way to produce a palindrome is to replace s[3] with 'x' and s[7] with 'o'. The first replacement costs 5, the second costs 3, so the total cost is 3+5=8.
				1)

				    
					"x??x"
					9
					4
					Returns: 8
					There are two ways to produce a palindrome here. The cheaper one is to change both '?'s to 'x's. This costs 4+4=8. Note that you are required to replace all '?'s.
					2)

					    
						"ooooxxxx"
						12
						34
						Returns: -1
						There is no '?' character, and s is not a palindrome. We have no way to change it into a palindrome.
						3)

						    
							"oxoxooxxxxooxoxo"
							7
							4
							Returns: 0
							There is no '?' character, and s is already a palindrome. Making no replacements does not cost anything.
							4)

							    
								"?o"
								6
								2
								Returns: 6

								5)

								    
									"????????????????????"
									50
									49
									Returns: 980

									6)

									    
										"o??oxxo?xoox?ox??x??"
										3
										10
										Returns: 38

										This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>
#include <sstream>
#include <math.h>
using namespace std;

class MinCostPalindrome
{
public:
	int getMinimum(string s, int oCost, int xCost);
};

int MinCostPalindrome::getMinimum(string s, int oCost, int xCost)
{
	int tcst = 0;
	for (int i = 0; i < s.length() / 2; ++i)
	{
		if ((s[i] == s[s.length() - i-1]) && (s[i]  == '?'))
		{
			if (oCost < xCost) {
				s[i] = 'o';
				s[s.length() - i - 1] = 'o';
				tcst += (2*oCost);
			}
			else
			{
				s[i] = 'x';
				s[s.length() - i - 1] = 'x';
				tcst += (2*xCost);
			}
		}
		else if (s[i] != s[s.length() - i - 1])
		{
			if (s[i] == '?')
			{
				s[i] = s[s.length() - i - 1];				
				if (s[i] == 'o')
					tcst += oCost;
				else
					tcst += xCost;
			}
			else if (s[s.length() - 1 - i] == '?')
			{
				s[s.length() - i - 1] = s[i];
				if (s[i] == 'o')
					tcst += oCost;
				else
					tcst += xCost;
			}			
		}
	}

	string p1 = s.substr(0, s.length() / 2);
	string p2 = s.substr(s.length() / 2, s.length() / 2);
	reverse(p2.begin(), p2.end());

	if (p1 != p2)
		tcst = -1;

	return tcst;
}


int main()
{

	MinCostPalindrome mcp;
	int cost = mcp.getMinimum("o??oxxo?xoox?ox??x??", 3, 10);
    return 0;
}

