// srm210.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;

class TitleString
{
public:
	string toFirstUpperCase(string title);
};


string TitleString::toFirstUpperCase(string title)
{
	string titCpy = title;

	for (int i = 0; i < titCpy.length(); ++i)
	{

		if (titCpy[i] == ' ')
			continue;
		else
		{
			titCpy[i] = toupper(titCpy[i]);

			while ((i < titCpy.length()) && (titCpy[i + 1] != ' '))
				i++;
		}
	}

	return titCpy;
}


	int main()
{

	TitleString ts;

	string st = "i amp ants";
	string out = ts.toFirstUpperCase(st);
	return 0;
}

