// 533.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	Pikachu is a well-known character in the Pokemon anime series. Pikachu can speak, but only 3 syllables: "pi", "ka", and "chu". Therefore Pikachu can only pronounce strings that can be created as a concatenation of one or more syllables he can pronounce. For example, he can pronounce the words "pikapi" and "pikachu".   You are given a string word. Your task is to check whether Pikachu can pronounce the string. If the string can be produced by concatenating copies of the strings "pi", "ka", and "chu", return "YES" (quotes for clarity). Otherwise, return "NO".
	Definition
	    
		Class:
		PikachuEasy
		Method:
		check
		Parameters:
		string
		Returns:
		string
		Method signature:
		string check(string word)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Constraints
			-
			word will contain between 1 and 50 characters, inclusive.
			-
			Each character of word will be a lowercase letter ('a'-'z').
			Examples
			0)

			    
				"pikapi"
				Returns: "YES"
				"pikapi" = "pi" + "ka" + "pi", so Pikachu can say it.
				1)

				    
					"pipikachu"
					Returns: "YES"
					This time we have "pipikachu" = "pi" + "pi" + "ka" + "chu", so Pikachu can say it as well.
					2)

					    
						"pikaqiu"
						Returns: "NO"
						Pikachu can't say "pikaqiu" since 'q' does not appear in "pi", "ka", or "chu".
						3)

						    
							"topcoder"
							Returns: "NO"

							4)

							    
								"piika"
								Returns: "NO"

								5)

								    
									"chupikachupipichu"
									Returns: "YES"

									6)

									    
										"pikapipachu"
										Returns: "NO"

										This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#include <vector>

using namespace std;

class PikachuEasy
{
public:
	string check(string word);
};

string PikachuEasy::check(string word)
{	
	bool good = false;
	for (int i = 0; i < word.length(); i += 2)
	{
		string tb = word.substr(i, 2);
		if (tb.length() >= 2)
		{
			if (tb == "pi" || tb == "ka")
				good = true;
			else {
				string tb = word.substr(i, 3);
				if (tb == "chu") {
					good = true;
					i += 1;
				}
				else {
					good = false;
					break;
				}
			}
	    }
		else
		{
			good = false;
			break;
		}
	}
		
	if (good)
		return "YES";
	else
		return "NO";
}


int main()
{
	PikachuEasy pke;
	string out = pke.check("pip");
    return 0;
}

