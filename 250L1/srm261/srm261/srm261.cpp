// srm261.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <numeric>
#include <cctype>
#include <sstream>

using namespace std;

class SpreadsheetColumn
{
public:
	string getLabel(int column);
};

string SpreadsheetColumn::getLabel(int column)
{
	string abt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int idx = column - 1;

	int num1 = idx / 26;
	int num2 = idx % 26;

	string out = "";

	if (num1 != 0)
	{
		out += abt[num1-1];
	}

	out += abt[num2];

	return out;
}


int main()
{
	SpreadsheetColumn sc;

	string out = sc.getLabel(702);
	return 0;
}

