// srm265.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <cctype>
#include <math.h>
#include <sstream>

using namespace std;

class FontSize
{
public:
	int getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase);
};

int FontSize::getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase)
{
	int widt = 0;
	for (int i = 0; i < sentence.length(); ++i)
	{
		if (isupper(sentence[i]))
		{
			widt  += uppercase[sentence[i]-65];
			if (i != (sentence.length()-1))
				widt += 1;
		}
		else if (islower(sentence[i]))
		{
			widt += lowercase[sentence[i] - 97];			
			
			if (i != (sentence.length() - 1))
				widt += 1;
			
		}
		else if (isspace(sentence[i]))
		{			
			widt += 3;
			if (i != (sentence.length() - 1))
				widt += 1;			
		}		
	}

	return widt;
}

int main()
{
	FontSize fs;
	string s = "ThE qUiCk BrOwN fOx JuMpEd OvEr ThE lAzY dOg";
	vector<int> u = { 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
	vector<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };

	int wid = fs.getPixelWidth(s, u, l);
	return 0;
}

