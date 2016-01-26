// srm240.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <numeric>
#include <map>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

class Pronunciation
{
public:
	string canPronounce(vector<string> words);
};


string Pronunciation::canPronounce(vector<string> words)
{
	string vows = "aeiou";
	string cons = "bcdfghjklmnpqrstvqxyz";

	vector<string> origwords = words;

	for (int i = 0; i < words.size(); ++i)
		for (int j = 0; j < words[i].length();++j)
			words[i][j] = tolower(words[i][j]);
	
	bool unpron = false;

	for (int i = 0; i < words.size(); ++i)
	{
		size_t poscons = 0, prevposcons=0;
		poscons = words[i].find_first_of(cons, poscons);
		int conscnt = 0;
		if (poscons != std::string::npos)
			conscnt = 1;
		
		while (poscons != std::string::npos)
		{
			prevposcons = poscons;		

			poscons = words[i].find_first_of(cons, prevposcons + 1);
			if (poscons != std::string::npos && poscons == prevposcons + 1)
				conscnt += 1;
			else if (poscons != std::string::npos)
			{
				conscnt = 1;
				continue;
			}

			if (conscnt == 3)
			{
				unpron = true;
				break;
			}
		}

		if (unpron)
		{
			return origwords[i];
		}
	}

	//vowel check
	for (int i = 0; i < words.size(); ++i)
	{
		size_t posv = 0, prevposv = 0;
		posv = words[i].find_first_of(vows, posv);
		int vowscnt = 0;
		if (posv != std::string::npos)
			vowscnt = 1;

		while (posv != std::string::npos)
		{
			prevposv = posv;

			posv = words[i].find_first_of(vows, prevposv + 1);
			if (posv != std::string::npos && posv == prevposv + 1 && words[i][posv] != words[i][prevposv])
				vowscnt += 1;
			else if (posv != std::string::npos)
			{
				vowscnt = 1;
				continue;
			}

			if (vowscnt == 2)
			{
				unpron = true;
				break;
			}
		}

		if (unpron)
		{
			return origwords[i];
		}
	}

	return "";
}


int main()
{

	Pronunciation pp;
	vector<string> w = { "Aa" };

	string out = pp.canPronounce(w);
	return 0;
}

