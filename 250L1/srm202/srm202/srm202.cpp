// srm202.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isUS(char c)
{
	if (c == '-')
		return true;
	else
		return false;
}

bool isnotdash(char c)
{
	if (c != '-')
		return true;
	else
		return false;
}

class LetterStrings
{

public:
	int sum(vector <string> s);
};


int LetterStrings::sum(vector <string> s)
{
	vector<string> scpy = s;

	int totlen = 0;
	for (int i = 0; i < s.size(); ++i)
	{
	
		//non-invasive
		int tmplen = count_if(scpy[i].begin(), scpy[i].end(), isnotdash);

		//invasive
		string::iterator sit = remove_if(scpy[i].begin(), scpy[i].end(), isUS);

		string tmp = string(scpy[i].begin(), sit);
		tmplen = tmp.length();
		totlen += tmplen;
	}

	return totlen;
}

int main()
{
	LetterStrings ls;
	vector<string> vf = { "-A-B-C-D", "--------EFGHI", "JKLMNOPQR", "---STU-VW-XYZ" };

	int totlen = ls.sum(vf);
	
	return 0;
}

