// srm234.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

class ComboLength
{
public:
	int howLong(string moves);
};

int ComboLength::howLong(string moves)
{
	size_t maxalen = 0,apos=0;
	size_t maxblen = 0,bpos=0;

	while ((apos = moves.find("A",apos)) != std::string::npos)
	{
		size_t alen = 0;
		while (moves[apos] == 'A')
		{
			alen++;
			apos += 1;
		}
		if (alen > maxalen)
			maxalen = alen;
	}

	while ((bpos = moves.find("B", bpos)) != std::string::npos)
	{
		size_t blen = 0;
		while (moves[bpos] == 'B')
		{
			blen++;
			bpos += 1;
		}
		if (blen > maxblen)
			maxblen = blen;
	}

	return max(maxalen, maxblen);
}


int main()
{
	ComboLength cmbl;

	int siz = cmbl.howLong("AAABBBBAA");
	return 0;
}

