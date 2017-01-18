// srm269.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class AccessChanger
{
public:
	vector <string> convert(vector <string> program);
};

vector <string> AccessChanger::convert(vector <string> program)
{
	for (int i = 0; i < program.size(); ++i)
	{
		size_t pos = std::string::npos;
		if ((pos = program[i].find("//")) == 0)
			continue;
		else
		{
			size_t poscomm = program[i].find("//");
			size_t posarr = program[i].find("->");
			if (posarr < poscomm)
			{
				while ((posarr != std::string::npos) && (posarr<poscomm) )
				{
					string p1 = string(program[i], 0, posarr);
					string p2 = string(program[i], posarr + 2, program[i].length() - posarr - 1);
					program[i] = p1 + "." + p2;
					posarr = program[i].find("->", posarr+1);
					poscomm = program[i].find("//");
				}
			}
		}
	}

	return program;
}


int main()
{
	AccessChanger ac;

	vector<string> p = {"///>//>-->/>--/----//>/->>/>>>-/--->/->-/>->--->//",
		"/>-/--/>/-/>>/->-->->/->-/--->/>/-///->>///>/>>>--"};

	vector<string>out = ac.convert(p);
	return 0;
}

