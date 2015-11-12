// srm656.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class CorruptedMessage
{
public:
	string reconstructMessage(string s, int k);
};

string CorruptedMessage::reconstructMessage(string s, int k)
{
	
	sort(s.begin(), s.end());
	map<int, char> mm;

	for (int i = 0; i < s.length(); ++i)
	{
		int tmpcnt = count(s.begin(), s.end(), s[i]);

		mm[tmpcnt] = s[i];
	}

	string nws;
	for (map<int, char>::iterator it = mm.begin(); it != mm.end(); it++)
	{
	
		int cnt = it->first + k;
		if (cnt <= (s.length()))
		{
			nws = string(s.length(), it->second);
		}
	}

	if (k > 0 && (nws.length() == 0))
	{
		for (char cp = 'a'; cp <= 'z'; cp++)
		{
			size_t pos = s.find(cp);
			if (pos == std::string::npos)
			{
				nws = string(s.length(), cp);
				break;
			}
		}
	}

	return nws;

	
}


int main()
{
	CorruptedMessage cml;
	string s = "zoztxtoxytyt";
	int k = 10;

	string out = cml.reconstructMessage(s, k);

	return 0;
}

