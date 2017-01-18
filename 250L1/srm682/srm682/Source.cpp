#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <set>
#include <functional>

using namespace std;

class DNASequence
{
public:
	int longestDNASequence(string sequence);
};


int DNASequence::longestDNASequence(string sequence)
{
	int prevcnt = 0, currcnt = 0;
	int i = 0;
	while(i < sequence.length())
	{		
		if (sequence[i] == 'A' || sequence[i] == 'T' || sequence[i] == 'G' || sequence[i] == 'C')
			currcnt++;
		else
		{	
		  currcnt = 0;
		}

		if (currcnt > prevcnt)
			prevcnt = currcnt;

		i += 1;
	}

	return prevcnt;
}

int main()
{
	DNASequence ssl;
	string sq = "GATTACA";
	int cnt = ssl.longestDNASequence(sq);


	return 0;
}