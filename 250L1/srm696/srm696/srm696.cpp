// srm696.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;


class Ropestring
{
public:
	string makerope(string s);
};

string Ropestring::makerope(string s)
{
	int slen = 0;
	int dotcnt = count(s.begin(), s.end(), '.');
	map<int, int> mp;
	
	while (slen < s.length())
	{		
		int dashcnt = 0;
		while (s[slen] != '.' && slen < s.length())
		{
			dashcnt++;
			slen++;
		}
		if(dashcnt>0)
			mp[dashcnt] += 1;
		while (s[slen] != string::npos && s[slen]=='.')
			slen++;
	}

	map<int, int>::reverse_iterator rit;
	string sout = "";
	for (rit = mp.rbegin(); rit != mp.rend(); rit++)
	{
		if ((rit->first % 2) == 0)
		{
			for (int z = 0; z < rit->second; ++z)
			{
				for (int i = 0; i < rit->first; ++i)
					sout += '-';

				if (dotcnt-- != 0 && sout.length()>0)
					sout += '.';
			}
		}
	}

	for (rit = mp.rbegin(); rit != mp.rend(); rit++)
	{
		if ((rit->first % 2) != 0)
		{
			for (int z = 0; z < rit->second; ++z)
			{
				for (int i = 0; i < rit->first; ++i)
					sout += '-';

				if (dotcnt-- != 0 && sout.length()>0)
					sout += '.';
			}
		}
	}

	while (dotcnt-- > 0)
		sout += '.';

	return sout;
}

int main()
{
	Ropestring rs;

	string out = rs.makerope("...");
	return 0;
}

