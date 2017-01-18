// srm688.cpp : Defines the entry point for the console application.
//

// srm687.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class ParenthesesDiv2Easy
{
public:
	int getDepth(string s);
};


int ParenthesesDiv2Easy::getDepth(string s)
{
	int maxcnt = 0;	
	unsigned pos = 0;

	while (true)
	{
		int cnt = 0;
		while (s[pos] != ')' && pos < s.length())
		{
			cnt++;
			pos++;
		}
		if (cnt > maxcnt)
			maxcnt = cnt;

		pos += 1;

		if (pos >= s.length())
			break;
	}

	return maxcnt;
}



int main()
{
	ParenthesesDiv2Easy pt;
	string inp = "()";
	int de = pt.getDepth(inp);
	return 0;
}

