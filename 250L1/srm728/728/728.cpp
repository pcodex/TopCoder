// 728.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	Halving is an operation that takes a nonnegative integer X and transforms it into another nonnegative integer: the value X/2, rounded down if necessary. For example, halving 16 produces 8, and halving 21 gives the result 10.
	You are given a vector <int> S containing a collection of nonnegative integers. You are also given a target: the int T.
	Count the number of elements of S which can be transformed into T by halving them zero or more times. Return this count.
	Definition
	    
		Class:
		HalvingEasy
		Method:
		count
		Parameters:
		vector <int>, int
		Returns:
		int
		Method signature:
		int count(vector <int> S, int T)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			256
			Constraints
			-
			S will contain between 1 and 50 elements, inclusive.
			-
			Each element of S will be between 1 and 109, inclusive.
			-
			T will be between 1 and 109, inclusive.
			Examples
			0)

			    
				{6, 14, 11, 3, 1}
				3
				Returns: 3
				6 can be transformed into 3 by halving it once.
				14 can be transformed into 3 by halving it twice (14 halved is 7, and 7 halved is 3).
				3 can be transformed into 3 by halving it zero times.
				the other two elements of S (11 and 1) cannot be transformed into 3.
				1)

				    
					{42, 10, 10, 10, 11, 11, 20, 21, 39, 40, 42, 43, 44}
					10
					Returns: 9
					42, 10, 10, 10, 20, 21, 40, 42 and 43 can be transformed into 10. Note that all occurrences of 10 and 42 are counted towards the answer.
					2)

					    
						{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
						1
						Returns: 20
						Every positive integer can be transformed into 1 by halving zero or more times.
						3)

						    
							{987654321, 1000000000, 998244353, 123456789, 999999999}
							476
							Returns: 3

							4)

							    
								{987654321, 1000000000, 998244353, 123456789, 999999999}
								1000000000
								Returns: 1

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <vector>
#include <math.h>

using namespace std;


class HalvingEasy
{
public:
	int count(vector <int> S, int T)
	{
		int cnt = 0;
		for (auto val : S)
		{
			while ((double)val /(double)2 > T)
				val /= 2;

			if (val%T == 0)
				cnt += 1;
		}

		return cnt;
	}
};


int main()
{
	HalvingEasy he;
	vector<int> s = { 6, 14, 11, 3, 1 };
	int T = 3;

	int cnt = he.count(s, T);
    return 0;
}

