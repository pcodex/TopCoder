// srm656-take2.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

class CorruptedMessage
{
public:
	string reconstructMessage(string s, int k);
};


string CorruptedMessage::reconstructMessage(string s, int k)
{
	string origmsg = s;

	set<char> msgchars;

	for (int i = 0; i < s.length(); ++i)
	{
		msgchars.insert(s[i]);
	}

	string thechars(msgchars.begin(), msgchars.end());

	int origmsglen = s.length();
	int padlength = k;
	sort(origmsg.begin(), origmsg.end());


	for (int j = 0; j < thechars.size(); ++j)
	{		
		char cmpchar = thechars[j];
		for (int k = 0; k < origmsglen&&padlength>0; ++k)
		{
				if (cmpchar == origmsg[k])
					continue;
				else
				{
					origmsg[k] = cmpchar;
					padlength -= 1;					
				}
		}		

		if (count(origmsg.begin(), origmsg.end(), cmpchar) == s.size() && 
			padlength==0)
		{
			return origmsg;
		}
		else
		{
			origmsg = s;
			sort(origmsg.begin(), origmsg.end());
			padlength = k;
			continue;
		}
	}

	if (padlength > 0)
	{
		char usethis = 'a';
		while (thechars.find(usethis) != std::string::npos)
			usethis += 1;

		origmsg = string(s.size(), usethis);
		return origmsg;
	}

}

int main()
{
	CorruptedMessage cmg;
	string s = "exwtxfhylzwdvxkrnyommyxktqrfpyhvwkagjas";
	int k = 38;

	string ans = cmg.reconstructMessage(s, k);

	return 0;
}

