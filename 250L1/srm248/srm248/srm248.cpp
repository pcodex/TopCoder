// srm248.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class SyllableCounter
{
public:
	int countSyllables(string word);
};

int SyllableCounter::countSyllables(string word)
{
	string vow = "AEIOU";
	int sylcnt = 0;
	size_t pos = 0;
	while ((pos = word.find_first_of(vow, pos)) != std::string::npos)
	{
		sylcnt++;

		size_t nxtpos = pos+1;
		while ((nxtpos = word.find_first_of(vow, nxtpos)) != std::string::npos)
		{
			if (nxtpos == pos + 1)
			{
				pos = nxtpos;
				nxtpos += 1;
				continue;
			}
			else
			{
				sylcnt++;
				pos = nxtpos;
				nxtpos += 1;
			}
		}

		if (nxtpos == std::string::npos)
			break;
	}

	return sylcnt;
}


int main()
{
	SyllableCounter sc;
	string w = "TELEVISION";
	int cnt = sc.countSyllables(w);
	return 0;
}

