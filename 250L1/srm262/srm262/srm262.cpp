// srm262.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <set>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class DivToZero
{
public:
	string lastTwo(int num, int factor);
};

string DivToZero::lastTwo(int num, int factor)
{
	stringstream ss;

	ss << num;
	string numstr = ss.str();
	numstr[numstr.length() - 1] = '0';
	numstr[numstr.length() - 2] = '0';

	stringstream ss2(numstr);
	int stnum = 0;
	ss2 >> stnum;

	while (stnum%factor != 0)
	{
		stnum++;
	}

	stringstream ss3;
	ss3 << stnum;

	string finalno = ss3.str();
	string last2 = ""; 
	last2 += finalno[finalno.length() - 2];
	last2 += finalno[finalno.length() - 1];

	return last2;
}


int main()
{
	DivToZero sz;

	string no  = sz.lastTwo(1000, 3);
	return 0;
}

