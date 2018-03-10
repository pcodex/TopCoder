// 527.cpp : Defines the entry point for the console application.
//

/*

Problem Statement
    
	NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

	You are given two vector <string>s original and target, which are two rectangular matrices with the same dimensions. Each character in the matrices will be either '0' or '1'. You want to transform original into target. You are only allowed to use one type of operations: Pick either a single row or a single column, and permute all its characters arbitrarily. You may use as many operations as you want to, one after another.

	Is it possible to transform original into target by using the allowed operations only? Return "YES" if it's possible, "NO" otherwise (quotes for clarity).
	Definition
	    
		Class:
		P8XMatrixTransformation
		Method:
		solve
		Parameters:
		vector <string>, vector <string>
		Returns:
		string
		Method signature:
		string solve(vector <string> original, vector <string> target)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			Permuting the characters means rearranging them into a new order.
			Constraints
			-
			original will contain between 1 and 50 elements, inclusive.
			-
			Each element of original will contain between 1 and 50 characters, inclusive.
			-
			All the elements of original will contain the same number of characters.
			-
			Each character in each element of original will be either '0' or '1'.
			-
			target will contain exactly R elements, where R is the number of elements in original.
			-
			Each element of target will contain exactly C characters, where C is the number of characters in original[0].
			-
			Each character in each element of target will be either '0' or '1'.
			Examples
			0)

			    
				{"01"
				,"11"}
				{"11"
				,"10"}
				Returns: "YES"
				For example, you can apply the following operations:     That is, you can first permute the first row and then the second column in the way shown above.
				1)

				    
					{"0111"
					,"0011"}
					{"1011"
					,"1100"}
					Returns: "YES"

					2)

					    
						{"0"}
						{"1"}
						Returns: "NO"

						3)

						    
							{"1111"
							,"1111"
							,"0000"
							,"0000"}
							{"1111"
							,"1111"
							,"0000"
							,"0000"}
							Returns: "YES"

							4)

							    
								{"0110"
								,"1001"
								,"0110"}
								{"1111"
								,"0110"
								,"0000"}
								Returns: "YES"

								5)

								    
									{"0000"
									,"1111"
									,"0000"}
									{"1111"
									,"0000"
									,"1111"}
									Returns: "NO"

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

class P8XMatrixTransformation
{
public:
	string solve(vector <string> original, vector <string> target);
};

string P8XMatrixTransformation::solve(vector <string> original, vector <string> target)
{
	int scnt0 = 0, scnt1 = 0, tcnt0 = 0, tcnt1 = 0;
	string poss = "NO";

	for (size_t i = 0; i < original.size(); ++i)
	{
		scnt0 += count(original[i].begin(), original[i].end(), '0');
		scnt1 += count(original[i].begin(), original[i].end(), '1');
	}

	for (size_t i = 0; i < target.size(); ++i)
	{
		tcnt0 += count(target[i].begin(), target[i].end(), '0');
		tcnt1 += count(target[i].begin(), target[i].end(), '1');
	}

	if ((tcnt0 == scnt0) && (tcnt1 == scnt1))
	{
		poss = "YES";
	}

	return poss;
}


int main()
{
	P8XMatrixTransformation pmt;
	vector<string> or = { "0111"
		,"0011" };
	vector<string> tr = { "1011"
		,"1100" };
	string out = pmt.solve(or , tr);
    return 0;
}

