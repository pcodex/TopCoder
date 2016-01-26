// srm677.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <sstream>
//#include <iostream>

using namespace std;

class PalindromePrime
{
public:
	int count(int L, int R);
};

int PalindromePrime::count(int L, int R)
{
	int PalPrimeCnt = 0;	

	for (int i = L; i <= R; ++i)
	{
		if ((i == 2) || (i == 3) || (i == 5) || (i == 7) || (i == 11))
		{			
			PalPrimeCnt++;
	//		cout << i << endl;
		}
		else
		{
			int divcnt = 0;
			if (i < 101)
				continue;

			for (int j = 2; j < i; ++j)
			{
				if (i%j == 0)
				{		
					divcnt++;
					break;
				}				
			}

			if (divcnt == 0)
			{
				//check for palin

				stringstream snum;
				snum << i;
				string num = snum.str();
				string revnum = num;
				reverse(revnum.begin(), revnum.end());
				if (num == revnum)
				{					
					PalPrimeCnt++;
		//			cout << i << endl;
				}
			}
		}
	}

	return PalPrimeCnt;
}


int main()
{
	PalindromePrime pp;

	int PalPrcnt = pp.count(100, 150);
	return 0;
}

