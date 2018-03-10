/*

Problem Statement
    
	Fox Jiro and Eel Saburo are good friends. One day Jiro received a letter from Saburo. The letter contains four integers representing an encrypted message. Please help Jiro to decrypt the message.

	You are given four ints: AminusB, BminusC, AplusB, and BplusC. Your task is to find three integers A, B, and C such that:
	AminusB = A - B
	BminusC = B - C
	AplusB = A + B
	BplusC = B + C
	There is always at most one triplet of integers A, B, C that satisfies all four equalities.

	If it exists, return a vector <int> with exactly three elements: { A, B, C }. If there are no such integers, return an empty vector <int> instead.
	Definition
	    
		Class:
		FoxAndIntegers
		Method:
		get
		Parameters:
		int, int, int, int
		Returns:
		vector <int>
		Method signature:
		vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Constraints
			-
			AminusB will be between -30 and 30, inclusive.
			-
			BminusC will be between -30 and 30, inclusive.
			-
			AplusB will be between -30 and 30, inclusive.
			-
			BplusC will be between -30 and 30. inclusive.
			Examples
			0)

			    
				1
				-2
				3
				4
				Returns: {2, 1, 3 }
				A - B = 2 - 1 = 1 B - C = 1 - 3 = -2 A + B = 2 + 1 = 3 B + C = 1 + 3 = 4
				1)

				    
					0
					0
					5
					5
					Returns: { }
					A = B = C = 2.5 satisfy all four equalities, but A, B, and C must all be integers.
					2)

					    
						10
						-23
						-10
						3
						Returns: {0, -10, 13 }
						A, B, and C may be negative or zero.
						3)

						    
							-27
							14
							13
							22
							Returns: { }

							4)

							    
								30
								30
								30
								-30
								Returns: {30, 0, -30 }

								This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
// 535.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#include <vector>

using namespace std;

class FoxAndIntegers
{
public:
	vector<int> get(int AminusB, int BminusC, int AplusB, int BplusC);
};


vector<int> FoxAndIntegers::get(int AminusB, int BminusC, int AplusB, int BplusC)
{
	int A = -31, B = -31, C = -31;
	bool done = false;

	if ((AplusB + AminusB) % 2 == 0)
	{
		A = (AplusB + AminusB) / 2;
		done = true;
	}
	
	if (done && ((BplusC + BminusC) % 2 == 0))
	{
		B = (BplusC + BminusC) / 2;
		C = BplusC - B;
		done = true;
	}
	
	
	vector<int> vans = {};

	if (done)
	{
		if (A + B == AplusB)
		{
			if (AminusB == A - B)
			{
				if (BplusC == B + C)
				{
					if(BminusC == B-C)
						vans = { A,B,C };
				}
			}
		}
	}
		
	
	return vans;
}


int main()
{
	FoxAndIntegers fs;
	vector<int> vs = fs.get(-27,14,13,22);

    return 0;
}

