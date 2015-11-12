// srm550.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class EasyConversionMachine
{
public:
	string isItPossible(string originalWord, string finalWord, int k);
};

string EasyConversionMachine::isItPossible(string originalWord, string finalWord, int k)
{
	
	bool isPoss = false;
	
	int cnt = 0;

	
		for (int i = 0; i < finalWord.size(); ++i)
		{			
				if (originalWord[i] != finalWord[i])
				{
					originalWord[i] = finalWord[i];
					cnt++;
				}
				if (cnt > k)
				{
					isPoss = false;
					break;
				}					
		}	

	if (cnt == k)
		isPoss = true;
	else if (cnt < k)
	{
		if (originalWord == finalWord)
		{
			int movesleft = k - cnt;
			
			if ((movesleft % 2)==0)
				isPoss = true;
		}
	}

	if (isPoss)
		return "POSSIBLE";
	else
		return "IMPOSSIBLE";
}

int main()
{
	EasyConversionMachine ec;
	string or = "aaa", fi = "bab";
	//"aababbabaa"
	//"abbbbaabab"
	
	int k = 4;
		
	string res = ec.isItPossible(or, fi, k);
	return 0;
}

