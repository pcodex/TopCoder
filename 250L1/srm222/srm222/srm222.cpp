// srm222.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class TextCompressor
{
public:
	string longestRepeat(string sourceText);
};

string TextCompressor::longestRepeat(string sourceText)
{

	string s2str = "";
	int mxlen = 0;
	string thebigstr = "";

	for (int j = 0; j < sourceText.length(); ++j)
	{
		for (int i = 1; i <= sourceText.length()-j; ++i)
		{
			s2str = string(sourceText, j, i);

			size_t pos1 = 0, pos2 = 0;

			pos1 = sourceText.find(s2str, pos1);

			pos2 = sourceText.find(s2str, pos1 + i);

			if (pos2 != std::string::npos)
			{
				//check for overlap
				if ((pos1 + i-1) < pos2)
				{
					//no overlap so capture length
					if (i>mxlen)
					{
						mxlen = i;
						thebigstr = s2str;
					}
				}
			}

		}
	}

	return thebigstr;
}


int main()
{

	TextCompressor txc;

	string src = "AAAA";

	string out = txc.longestRepeat(src);
	return 0;
}

