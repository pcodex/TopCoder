// srm703.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;


class AlternatingString
{
public:
	int maxLength(string s)
	{
		int slen = 0;
		int maxl = slen;
		if (s.length() > 0)
		{			
			for (int i = 0; i < s.length()-1; ++i)
			{
				if (s[i] != s[i + 1])
					slen++;
				else
				{
					if (slen > maxl)
						maxl = slen;

					slen = 0;
				}
			}
			 
			if (slen > maxl)
				maxl = slen;
		}

		return maxl+1;
	}
};


int main()
{
	AlternatingString as;
	string instr = "1010101";

	int te = as.maxLength(instr);
	
	return 0;
}

