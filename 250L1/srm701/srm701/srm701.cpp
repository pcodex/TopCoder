// srm701.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

class SquareFreeString
{
public:
	string isSquareFree(string s);
};


string SquareFreeString::isSquareFree(string s)
{
	sort(s.begin(), s.end());
	bool sq = false;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == s[i + 1])
		{
			sq = true;
			break;
		}
	}
	if (sq)
		return "not square-free";
	else
	return "square-free";

}


int main()
{
	SquareFreeString sqs;

	string oout = sqs.isSquareFree("aydyamrbnauhftmphyrooyq");
	return 0;
}

