// srm227.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>

using namespace std;

class StringCompare
{
public:
	int simpleDifference(string a, string b);
};

int StringCompare::simpleDifference(string a, string b)
{
	string::iterator i1=a.begin(), i2=b.begin();
	int score = 0;
	while (i1!=a.end() && i2!=b.end())
	{
		if (*i1++ == *i2++)
			score++;		
	}

	return score;
}


int main()
{

	StringCompare sc;

	string a = "FANTASTIC", b = "ANTASTIC";
	int score = sc.simpleDifference(a, b);
	return 0;
}

