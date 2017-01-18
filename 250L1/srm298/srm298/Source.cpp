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

class IndicatorMotion
{
public:
	string getMotion(string program, char startState);
};

string IndicatorMotion::getMotion(string program, char startState)
{
	map<char, char> LMap;
	map<char, char> RMap;
	
	map<char, char> FlpMap;

	LMap['|'] = '\\';
	LMap['\\'] = '-';
	LMap['-'] = '/';
	LMap['/'] = '|';

	RMap['|'] = '/';
	RMap['/'] = '-';
	RMap['-'] = '\\';
	RMap['\\'] = '|';

	FlpMap['\\'] = '/';
	FlpMap['/'] = '\\';
	FlpMap['-'] = '|';
	FlpMap['|'] = '-';

	string out = string(1,startState);
	char currst = startState;

	if (program.length() > 0)
	{
		for (int i = 0; i < program.size() - 2; i += 3)
		{
			char act = program[i];
			string reps = string(program, (i)+1, 2);
			stringstream nos(reps);
			int num;
			nos >> num;

			for (int mov = 0; mov < num; ++mov)
			{
				if (act == 'F')
				{
					out += FlpMap[currst];
					currst = FlpMap[currst];
				}
				else if (act == 'L')
				{
					out += LMap[currst];
					currst = LMap[currst];
				}
				else if (act == 'R')
				{
					out += RMap[currst];
					currst = RMap[currst];
				}
				else
				{
					out += currst;
				}
			}
		}
	}
	return out;
}

int main()
{
	IndicatorMotion im;
	string p = "F00R00L00S00";
	char s = '\\';
	string out = im.getMotion(p, s);
	return 0;
}