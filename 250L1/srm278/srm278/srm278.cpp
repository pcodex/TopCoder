// srm278.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class RectangleGroups
{
public:
	string maximalIndexed(vector <string> rectangles);
};

string RectangleGroups::maximalIndexed(vector <string> rectangles)
{

	map<char, int> rect;

	for (int i = 0; i < rectangles.size(); ++i)
	{
		stringstream ss(rectangles[i]);
		char gp;
		int len=0,wid=0;
		ss >> gp >> len >> wid;
		int area = len*wid;
		rect[gp] += area;
	}

	map<char, int>::iterator mit = rect.begin();
	char lg;
	int maxar = 0;
	for (mit; mit != rect.end(); mit++)
	{
		if (mit->second > maxar)
		{
			maxar = mit->second;
		}
	}
	mit = rect.begin();
	for (mit; mit != rect.end(); mit++)
	{
		if (mit->second == maxar)
		{
			lg = mit->first;
			break;
		}
	}	
	

	string out = string(1,lg);
	out += ' ';
	stringstream ss;
	ss << maxar;
	out += (ss.str());

	return out;
	
}


int main()
{
	RectangleGroups rg;
	vector<string> r = { "D 1 6", "F 2 3", "G 1 1", "G 5 1", "C 3 2" };
	string a = rg.maximalIndexed(r);
	return 0;
}

