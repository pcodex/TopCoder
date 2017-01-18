// srm279.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class DancingSentence
{
public:
	string makeDancing(string sentence);
};

string DancingSentence::makeDancing(string sentence)
{
	string out = sentence;
	bool prevUp = false;

	for (int i = 0; i < sentence.length(); ++i)
	{
		if (isspace(out[i]))
			continue;
		else if (!prevUp)
		{
			out[i]=toupper(out[i]);
			prevUp = true;
		}
		else
		{
			out[i]=tolower(out[i]);
			prevUp = false;
		}
	}

	return out;
}


int main()
{
	DancingSentence ds;
	string ou = ds.makeDancing(" This   is         a  dancing   sentence  ");
	return 0;
}

