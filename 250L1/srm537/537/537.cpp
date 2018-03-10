// 537.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.  After several years of waiting, King Dengklek and the queen finally had a baby. Now he is looking for a name for the newborn baby. According to the private rule of Kingdom of Ducks, the name of each member of the royal family must be such that:
	It must consist of exactly eight letters. All letters must be lowercase ('a'-'z').
	It must have exactly two vowels and six consonants. (Vowels are the letters 'a', 'e', 'i', 'o', and 'u'; the rest are consonants.)
	The two vowels must be equal.
	For example, "dengklek" is a valid name because it consists of exactly eight letters: six consonants and two identical vowels, 'e'.  You are given a String name. Please help the kingdom determine whether name is valid. Return "YES" if it is a valid name for King Dengklek's newborn baby, or "NO" otherwise.
	Definition
	    
		Class:
		KingXNewBaby
		Method:
		isValid
		Parameters:
		string
		Returns:
		string
		Method signature:
		string isValid(string name)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Constraints
			-
			name will contain between 1 and 50 characters, inclusive.
			-
			Each character of name will be one of 'a'-'z'.
			Examples
			0)

			    
				"dengklek"
				Returns: "YES"

				1)

				    
					"gofushar"
					Returns: "NO"
					It has more than two vowels.
					2)

					    
						"dolphinigle"
						Returns: "NO"
						It has more than eight letters.
						3)

						    
							"mystictc"
							Returns: "NO"
							It has only one vowel.
							4)

							    
								"rngringo"
								Returns: "NO"
								It has exactly two vowels, but they are not equal.
								5)

								    
									"misof"
									Returns: "NO"
									It has less than eight letters.
									6)

									    
										"metelsky"
										Returns: "YES"

										This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/


#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class KingXNewBaby
{
public:
	string isValid(string name);
};


string KingXNewBaby::isValid(string name)
{
	bool valid = false;

	if (name.length() == 8)
	{
		int vcnt = 0;
		size_t pos = 0;
		vector<char> vpos;
		while (pos != std::string::npos)
		{
			pos = name.find_first_of("aeiou", pos);
			if (pos != std::string::npos) {
				vcnt++;
				if (vcnt <= 2)
					vpos.push_back(name[pos]);
				else
					break;

				pos += 1;				
			}
		}

		if (vcnt == 2) {
			if(vpos[0]==vpos[1])
			  valid = true;
		}
    }

	if (valid)
		return "YES";
	else
		return "NO";
	
}


int main()
{
	KingXNewBaby kb;
	string ans = kb.isValid("rngringo");
    return 0;
}

