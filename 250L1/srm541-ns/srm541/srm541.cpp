// srm541.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class AkariDaisukiDiv2
{
public:
	int countTuples(string S);
};

int AkariDaisukiDiv2::countTuples(string S)
{
	map<char, int> ltrcnt;
	int cnt = 0;

	for (int i = 1; i < S.length()-1; i++)
	{
		if (ltrcnt[S[i]] == 0)
		{
			int lcnt = count(S.begin()+1, S.end()-1, S[i]);

			if (lcnt >= 2)
				ltrcnt[S[i]] += lcnt;
		}
	}

	for (int j = 0; j < ltrcnt.size(); ++j)
	{
		if (ltrcnt[j] >= 2)
			cnt++;
	}
	return cnt;
}


int main()
{
	AkariDaisukiDiv2 ck;
	string ss = "waaiusushioakariusushiodaisuki";

	int ret = ck.countTuples(ss);
	
	return 0;
}

