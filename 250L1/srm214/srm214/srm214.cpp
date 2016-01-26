// srm214.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

class bloggoShortcuts
{
public:
	string expand(string text);
};

string bloggoShortcuts::expand(string text)
{
	string txtOut = text;

	size_t pos = 0;
	int udCnt = -1;	

	while (((pos = txtOut.find('_', pos))!=std::string::npos) &&
		(pos < txtOut.length()))
	{
		if (pos != std::string::npos)
		{
			udCnt += 1;			
		}

		if ((udCnt % 2) == 0)
		{
			txtOut.replace(pos, 1, "<i>");
		}
		else
		{
			txtOut.replace(pos, 1, "</i>");
		}

		pos += 1;
	}

	pos = 0;
	int astCnt = -1;

	while (((pos = txtOut.find('*', pos)) != std::string::npos) &&
		   (pos < txtOut.length()))
	{		

		if (pos != std::string::npos)
		{
			astCnt += 1;			
		}

		if ((astCnt % 2) == 0)
		{
			txtOut.replace(pos, 1, "<b>");
		}
		else
		{
			txtOut.replace(pos, 1, "</b>");
		}

		pos += 1;
	}

	return txtOut;
}


int main()
{
	bloggoShortcuts bs;

	string t = " _ _ __  _ yabba dabba _   *  dooooo  * ****";
	
	string out = bs.expand(t);
	return 0;
}

