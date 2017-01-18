// srm698.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>
#include <sstream>

using namespace std;

class Initials
{
public:
	string getInitials(string name);
};

string Initials::getInitials(string name)
{
	string inits = string(1, name[0]);
	size_t len = 0;

	while (len < name.length())
	{
		while (name[len++] != ' ' && len < name.length())
		{
			continue;
		}
		if (len<name.length())
			inits += name[len];
	}
	
	return inits;
}

int main()
{
	Initials ini;

	string acr = ini.getInitials("john fitx kenx");
	return 0;
}

