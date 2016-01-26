// srm257.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cctype>

using namespace std;

class SubstitutionCode
{
public:
	int getValue(string key, string code);
};

int SubstitutionCode::getValue(string key, string code)
{
	string out = "";
	for (int i = 0; i < code.length(); ++i)
	{
		size_t pos = key.find(code[i]);

		if (pos == std::string::npos)
			continue;
		else if (pos == key.length() - 1)
			out += "0";
		else
		{			
			stringstream ss;			
			ss << pos+1;
			out += ss.str();
		}
	}

	stringstream ss2(out);
	int decod = 0;
	ss2 >> decod;

	return decod;

}


int main()
{
	SubstitutionCode sc;
	string k = "TRADINGFEW";
	string c = "LGXWEV";
	int ot = sc.getValue(k, c);
	return 0;
}

