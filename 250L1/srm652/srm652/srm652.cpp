// srm652.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class ValueOfString
{
public:
	int findValue(string s);
};

int ValueOfString::findValue(string s)
{
	string mycpy = s;

	int totcnt = 0;

	map<char, int> mpltr, mpltrless;

	for (int i = 0; i < mycpy.length(); ++i)
	{
		mpltr[mycpy[i]] += 1;
	}

	mpltrless = mpltr;

	
	for (map<char, int>::iterator it = mpltrless.begin(); it != mpltrless.end(); it++)
	{
			for (int j = 0; j < mycpy.length(); ++j)
			{
				if (mycpy[j] < it->first)
					mpltrless[it->first] += 1;
			}
	}
	
	for (map<char, int>::iterator sz = mpltr.begin(); sz != mpltr.end(); sz++)
	{
		int cval = (int)sz->first-96;

		totcnt += cval * mpltrless[sz->first] * mpltr[sz->first];
	}

	return totcnt;
}

int main()
{
	ValueOfString vs;

	int cnt = vs.findValue("zyxwvutsrqponmlkjihgfedcba");
	return 0;
}

