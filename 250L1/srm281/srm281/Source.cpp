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

class RunLengthEncoding
{
public:
	string decode(string text);
};

string RunLengthEncoding::decode(string text)
{
	vector<int> num;
	vector<char> alp;
	bool numdone = false;

	for (int i = 0; i < text.length(); ++i)
	{
		if(!isalpha(text[i]))
		{
			string anum;
			while (isdigit(text[i]))
			{
				anum += text[i];
				i++;
				if (anum.length() > 2)
					return "TOO LONG";
			}

			stringstream ss;
			ss << anum;
			int thenum;
			ss >> thenum;
			if (thenum > 50)
				return "TOO LONG";

			num.push_back(thenum);
			i--;
			numdone = true;
			if (accumulate(num.begin(), num.end(), 0) > 50)
				return "TOO LONG";
		}
		else
		{
			if (!numdone)
			{
				num.push_back(1);
				if (accumulate(num.begin(), num.end(), 0) > 50)
					return "TOO LONG";
			}

			char alb;
			alb = text[i];
			alp.push_back(alb);
			numdone = false;
		}
	}

	string outp;
	for (int x = 0; x < alp.size(); ++x)
	{
		int len = num[x];
		outp += string(len,alp[x]);
	}

	return outp;

}


int main()
{
	RunLengthEncoding el;

	string out = el.decode("25A25BC");

	return 0;
}