// srm250.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class ColorCode
{
	enum colors { black, brown, red, orange, yellow, green, blue, violet, grey, white };
	int transcolor(string col);
public:
	long long getOhms(vector <string> code);
};

int ColorCode::transcolor(string col)
{
	int colcode = -1;
	
	if (col == "black")
		colcode = black;
	
	if (col == "brown")
		colcode = brown;

	if (col == "red")
		colcode = red;

	if (col == "orange")
	colcode = orange;

	if (col == "yellow")
	colcode = yellow;

	if (col == "green")
	colcode = green;

	if (col == "blue")
	colcode = blue;

	if (col == "violet")
	colcode = violet;

	if (col == "grey")
	colcode = grey;

	if (col == "white")
	colcode = white;

	return colcode;
}

long long ColorCode::getOhms(vector <string> code)
{
	return ((transcolor(code[0]) * 10) + (transcolor(code[1])))*(pow(10, transcolor(code[2])));
}


int main()
{
	ColorCode cc;
	vector<string> c = { "yellow", "violet", "red" };
	long long rat = cc.getOhms(c);
	return 0;
}

