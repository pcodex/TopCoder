// 723.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	Did you know that "Buffalo buffalo Buffalo buffalo buffalo buffalo Buffalo buffalo." is a grammatically correct sentence in American English?  In this problem we call a string good if it satisfies the following constraints:
	The string contains one or more words.
	Each word in the string is "buffalo".
	Each pair of consecutive words is separated by exactly one space.
	There are no spaces at the beginning of the string.
	There are no spaces at the end of the string.
	For example, the strings "buffalo", "buffalo buffalo" and "buffalo buffalo buffalo" are good but " buffalo", "buffalobuffalo", "buff alo", and "cow" are not.  You are given a string s that consists of spaces and lowercase letters. Return "Good" if s is a good string. Otherwise, return "Not good". (Note that the return value is case-sensitive.)
	Definition
	    
		Class:
		BuffaloBuffalo
		Method:
		check
		Parameters:
		string
		Returns:
		string
		Method signature:
		string check(string s)
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
			s will contain between 1 and 1,000 characters, inclusive.
			-
			Each character in s will be a lowercase English letter ('a' - 'z') or a space (' ').
			Examples
			0)

			    
				"buffalo buffalo"
				Returns: "Good"
				This is a good sentence contains two 'buffalo'.
				1)

				    
					"buffalobuffalo"
					Returns: "Not good"
					There must be exactly one space between two words.
					2)

					    
						"buffalo buffalo buffalo"
						Returns: "Good"

						3)

						    
							"buf falo buffalo"
							Returns: "Not good"

							4)

							    
								"cow"
								Returns: "Not good"

								5)

								    
									"buffalo  buffalo"
									Returns: "Not good"

									This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
using namespace std;

class BuffaloBuffalo
{
public:
	string check(string s);
};


string BuffaloBuffalo::check(string s)
{
	bool good = false;
	if (s[0] != ' ' && s[s.length() - 1] != ' ' && s.length()>=7)
	{
		string scpy = s;
		for (int i = 0; i < scpy.length(); ++i)
		{
			scpy[i] = tolower(scpy[i]);
		}

		 
		size_t mypos = scpy.find_first_not_of("buffalo ");
		if (mypos != string::npos)
		  return "Not good";
		else
		{
			size_t pos = 0;
			while (pos != string::npos)
			{
				size_t nwpos = scpy.find("buffalo", pos);
				if (nwpos == pos && scpy[pos + 7] == ' ')
					pos += 8;
				else if ((nwpos == pos) && (pos+7>=scpy.length()))
				{
					good = true;
					break;
				}
				else {
					good = false;
					break;
				}
			}
			
		}
	}
	if (!good)
		return "Not good";
	else
		return "Good";
}


int main()
{
	BuffaloBuffalo bb;
	string ng = bb.check("buffalobuffalo");
	ng = bb.check("buffalo buffalo buffalo");
	ng = bb.check("buf falo buffalo");
	ng = bb.check("cow");
	ng = bb.check("buffalo  buffalo");

    return 0;
}

