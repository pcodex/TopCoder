// 529.cpp : Defines the entry point for the console application.
//
/*

Problem Statement
    
	"Pairing pawns" is a game played on a strip of paper, divided into N cells. The cells are labeled 0 through N-1. Each cell may contain an arbitrary number of pawns.
	You are given a vector <int> start with N elements. For each i, element i of start is the initial number of pawns on cell i.
	The goal of the game is to bring as many pawns as possible to cell 0.
	The only valid move looks as follows:
	Find a pair of pawns that share the same cell X (other than cell 0).
	Remove the pair of pawns from cell X.
	Add a single new pawn into the cell X-1.
	You may make as many moves as you wish, in any order.
	Return the maximum number of pawns that can be in cell 0 at the end of the game.
	Definition
	    
		Class:
		PairingPawns
		Method:
		savedPawnCount
		Parameters:
		vector <int>
		Returns:
		int
		Method signature:
		int savedPawnCount(vector <int> start)
		(be sure your method is public)
		Limits
		    
			Time limit (s):
			2.000
			Memory limit (MB):
			64
			Notes
			-
			You may assume that the answer will always fit into an int.
			-
			Note that you are only given the vector <int> start. The number of cells N can be determined as the length of start.
			Constraints
			-
			start will contain between 1 and 20 elements, inclusive.
			-
			Each element of start will be between 0 and 1,000,000, inclusive.
			Examples
			0)

			    
				{0,2}
				Returns: 1
				There are two pawns on cell 1. You can remove them both and place a pawn onto cell 0.
				1)

				    
					{10,3}
					Returns: 11
					There are 10 pawns already on cell 0. You can add another one by removing two pawns from cell 1. Note that at the end of the game cell 1 will still contain one pawn that cannot be used anymore.
					2)

					    
						{0,0,0,8}
						Returns: 1
						After 7 moves you can get a single pawn to cell 0. The rest of the board will be empty.
						3)

						    
							{0,1,1,2}
							Returns: 1
							Again, a single pawn can reach the leftmost cell.
							4)

							    
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456}
								Returns: 0
								That's a lot of pawns! But they are too far away. In this case it is impossible for a pawn to reach cell 0.
								5)

								    
									{1000,2000,3000,4000,5000,6000,7000,8000}
									Returns: 3921

									This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <cctype>
#include <set>
#include <stack>
using namespace std;

class PairingPawns
{
public:
	int savedPawnCount(vector <int> start);
};

int PairingPawns::savedPawnCount(vector <int> start)
{
	for (int i = start.size() - 1; i > 0; --i)
	{		
		int tadd = start[i] / 2;
		int left = start[i] % 2;
		start[i] = left;
		start[i - 1] += tadd;
     }

	return start[0];
}

int main()
{

	PairingPawns pp;
	vector<int> stt = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123456 };
	int lft = pp.savedPawnCount(stt);
    return 0;
}

