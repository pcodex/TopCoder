// srm216.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>

using namespace std;

class CultureShock
{
public:
	string translate(string text);
};

string CultureShock::translate(string text)
{
	
	/*string txtCopy = text;
	size_t pos = 0;

	while ((pos = txtCopy.find("ZEE", pos)) != std::string::npos)
	{		
		if ((pos == 0) &&
			((txtCopy[pos + 3] == ' ')||(txtCopy[pos+3]=='\0')))
		{
			txtCopy.replace(pos + 2, 1, "D");
		}
		else if (((txtCopy[pos - 1] == ' ') && (txtCopy[pos + 3] == ' '))
			||
				((txtCopy[pos - 1] == ' ') && (txtCopy[pos + 3] == '\0')))
		{
			txtCopy.replace(pos+2, 1, "D");
		}

		pos += 1;
	}
	
	return txtCopy;
	*/

	// someone's soln
	stringstream s(text);
	string str;

	s >> str;
	string res = "";

	while (s >> str)
	{
		if (str.compare("ZEE") == 0)
			str = "ZED";
		res += " " + str;
	}
	res.erase(0, 1);
	return res;
}

int main()
{
	CultureShock cs;

	string tx = "SPELLING IN ENGLISH IS EZEE";
	string outst = cs.translate(tx);
	return 0;
}

