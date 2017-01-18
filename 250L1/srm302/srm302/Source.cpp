#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <set>
#include <functional>

using namespace std;

class NounReform
{
public:
	vector <string> makePlural(vector <string> nouns);
};

vector <string> NounReform::makePlural(vector <string> nouns)
{
	for (int i = 0; i < nouns.size(); ++i)
	{		
		char lch;
		string lch2;
		if (nouns[i].length()>0)
			lch = nouns[i][nouns[i].length() - 1];

		if (nouns[i].length()>1)
			lch2 = string(nouns[i], nouns[i].length() - 2, 2);

		if ((lch == 's') || (lch == 'z') || (lch == 'x') ||(lch2 == "ch") || (lch2 == "sh"))
			nouns[i] += "es";

		else if ((lch2 == "ay") || (lch2 == "ey") || (lch2 == "iy") ||(lch2 == "oy") || (lch2 == "uy"))
			nouns[i] += "s";

		else if (lch == 'y')
		{
			nouns[i][nouns[i].length() - 1] = 'i';
			nouns[i] += "es";
		}
		else
			nouns[i] += "s";		
	}
	return nouns;	
}

int main()
{
	NounReform m;
	vector<string> n = { "a", "s", "oy", "y", "yy" };
	vector<string> o = m.makePlural(n);
	return 0;
}
