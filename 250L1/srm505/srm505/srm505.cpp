#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

class SentenceCapitalizerInator
{
public:
	string fixCaps(string paragraph);
};

string SentenceCapitalizerInator::fixCaps(string paragraph)
{
	paragraph[0] = toupper(paragraph[0]);

	for (int i = 0; i < paragraph.length(); ++i)
	{
		if (i - 1 >= 0)
		{
			if (isspace(paragraph[i]) && paragraph[i - 1] == '.')
				paragraph[i+1]=toupper(paragraph[i + 1]);
		}
	}

	return paragraph;
}


int main()
{
	SentenceCapitalizerInator ssl;
	string  inp = "example four. the long fourth example. a. b. c. d.";
	string outp = ssl.fixCaps(inp);

	return 0;
}