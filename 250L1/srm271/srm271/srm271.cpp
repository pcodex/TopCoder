// srm271.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <numeric>
#include <math.h>
#include <stack>
#include <cctype>

using namespace std;

class CheckFunction
{
public:
	int newFunction(string code);
};

int CheckFunction::newFunction(string code)
{
	int outcode = 0;

	for (int i = 0; i < code.length(); ++i)
	{
		switch (code[i])
		{
		case '0':
			outcode += 6;
			break;
		case '1':
			outcode += 2;
			break;
		case '2':
			outcode += 5;
			break;
		case '3':
			outcode += 5;
			break;
		case '4':
			outcode += 4;
			break;
		case '5':
			outcode += 5;
			break;
		case '6':
			outcode +=6;
			break;
		case '7':
			outcode += 3;
			break;
		case '8':
			outcode += 7;
			break;
		case '9':
			outcode += 6;
			break;
		}		
	}
	return outcode;
}

int main()
{
	CheckFunction cg;
	string c = "73254370932875002027963295052175";
	int code = cg.newFunction(c);
	return 0;
}

