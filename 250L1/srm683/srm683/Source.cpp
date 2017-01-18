#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>

using namespace std;

class EqualSubstrings2
{
public:
	int get(string s);
};


int EqualSubstrings2::get(string s)
{
	int cnt = 0;
	for (int start = 0; start < s.length(); ++start)
	{
		for (int sz = 1; (start+sz) <= s.length(); ++sz)
		{
			string str_src = string(s, start, sz);
			for (int destpos = start + sz; (destpos + sz-1) < s.length(); ++destpos)
			{
				string str_dest = string(s, destpos, sz);
				if (str_src == str_dest)
					cnt++;
			}
		}
	}

	return cnt;
}


int main()
{
	EqualSubstrings2 s;

	int cc = s.get("onetwothreeonetwothree");
	return 0;
}