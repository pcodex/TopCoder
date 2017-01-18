// srm691.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Plusonegame
{
public:
	string getorder(string s);
};


string Plusonegame::getorder(string s)
{
	map<char, int> mp;

	for (int i = 0; i < s.length(); ++i)
	{
		mp[s[i]] += 1;
	}

	string out = "";
	int pluscnt = mp['+'];

	for (int z = 0; z < mp['0']; ++z)
		out += '0';

	int cnter = 0;
	
	while (pluscnt > 0)
	{
		out += '+';
		cnter += 1;
		char thenum = '0' + cnter;		

		if (mp[thenum]>0)
		{
			for (int hh = 0; hh < mp[thenum]; ++hh)
				out += thenum;
		}

		pluscnt--;	
	}

	cnter += 1;
	for (cnter; cnter <= 9; ++cnter)
	{
		char thenum = '0' + cnter;
		if (mp[thenum]>0)
		{
			for (int hh = 0; hh < mp[thenum]; ++hh)
				out += thenum;
		}
	}

	return out;
}

int main()
{
	Plusonegame ppg;

	string res = ppg.getorder("++11199999");
	return 0;
}

