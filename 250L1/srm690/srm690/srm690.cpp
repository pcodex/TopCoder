// srm690.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <math.h>
#include <cctype>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

class DoubleString
{
public:
	string check(string S);
};


string DoubleString::check(string S)
{
	string res = "not square";

	if (S.length() % 2)
		return res;

	string p1 = string(S, 0, (S.length() / 2));

	string chk = p1 + p1;
	if (chk == S)
		res = "square";

	return res;
}


int main()
{
	DoubleString ds;

	string out= ds.check("CANCAN");
	return 0;
}

