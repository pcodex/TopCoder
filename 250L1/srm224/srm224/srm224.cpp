// srm224.cpp : Defines the entry point for the console application.
//


#include <string>
#include <algorithm>

using namespace std;

class InsideOut
{
public:
	string unscramble(string line);
};

string InsideOut::unscramble(string line)
{
	size_t lnLnth = line.length();

	string p1 = string(line, 0, line.length() / 2);

	string p2 = string(line, (line.length() / 2), line.length()/2);

	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());

	return p1+p2;
}


int main()
{
	InsideOut ins;

	string l = "RUT OWT SNEH HCNERF EERHTEGDIRTRAP A DNA  SEVODELT";

	string out = ins.unscramble(l);
	return 0;
}

