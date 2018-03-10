// 538.cpp : Defines the entry point for the console application.
//
/*


Problem Statement
    
	The Very Heterogeneous State of Feudalia's army is designing a new spy robot. Currently, the robot can only accept two commands: L and R. L moves the robot one unit of distance to the left, and R moves the robot one unit to the right. A program for the robot is a sequence of commands. For a given program, its reach is the distance between the starting point and the farthest point visited during the execution of the program. For example, the reach of the program "LLLR" is 3, because after the first three steps we reach a location 3 units away from the starting point.  Unfortunately, Feudalia is world famous for the ineptitude of its public officials. Some coffee was spilled all over the program before it could be installed to the robot. Therefore, some of the commands may now be illegible. Your task is to repair the program by replacing each illegible command with an L or an R. If there are multiple ways to repair the program, you have to pick one that maximizes its reach.  You are given a string program which describes the program in its current state. The i-th character in program represents the i-th command that is executed and will be 'L', 'R' or '?' (quotes for clarity). 'L' represents a legible move left, 'R' a legible move right and '?' a command that is illegible so you can choose 'L' or 'R' in its place. Return the largest reach a repaired program can have.
	Definition
	    
		Class:
		LeftOrRight
		Method:
		maxDistance
		Parameters:
		string
		Returns:
		int
		Method signature:
		int maxDistance(string program)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Constraints
			-
			program will contain between 1 and 50 characters, inclusive.
			-
			Each character of program will be 'L', 'R' or '?' (quotes for clarity).
			Examples
			0)

			    
				"LLLRLRRR"
				Returns: 3
				All commands are legible. The reach of this program is 3: both after three steps and after five steps we are 3 units to the left of the starting location.
				1)

				    
					"R???L"
					Returns: 4
					We can replace all of the question marks with a right command.
					2)

					    
						"??????"
						Returns: 6

						3)

						    
							"LL???RRRRRRR???"
							Returns: 11

							4)

							    
								"L?L?"
								Returns: 4

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctype.h>

using namespace std;

class LeftOrRight
{
public:
	int maxDistance(string program);
};

int LeftOrRight::maxDistance(string program)
{	
	int ans = 0;

	string newl = program, newr = program;
	replace(newl.begin(), newl.end(), '?', 'L');
	replace(newr.begin(), newr.end(), '?', 'R');

	int maxl = 0, tmp = 0;
	for (int i = 0; i < newl.length(); ++i)
	{
				if (newl[i] == 'L')
					tmp--;
				else
					tmp++;

				if (abs(tmp) > maxl)
					maxl = abs(tmp);
	}

	tmp = 0;
	int maxr = 0; 
	for (int i = 0; i < newr.length(); ++i)
	{
				if (newr[i] == 'R')
					tmp++;
				else
					tmp--;

				if (abs(tmp) > maxr)
					maxr = abs(tmp);
	}
			
	ans = maxr > maxl ? maxr : maxl;			
	
	return ans;
	
}


int main()
{
	LeftOrRight lr;
	int ans = lr.maxDistance("L??RL?LR?LRL?RLLL?L?L??RLR?R");
    return 0;
}

