// srm225.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SignatureDecorator
{
public:
	string applyDecoration(string name, vector <string> commands, vector <string> decorations);
};

string SignatureDecorator::applyDecoration(string name, vector <string> commands, vector <string> decorations)
{
	string finalNm = name;

	for (int i = 0; i < commands.size(); ++i)
	{
		if (commands[i] == "append")
		{
			finalNm += decorations[i];
		}
		else if (commands[i] == "prepend")
		{
			finalNm = decorations[i] + finalNm;
		}
		else
		{	

			finalNm = decorations[i] + finalNm;

			reverse(decorations[i].begin(), decorations[i].end());
			finalNm += decorations[i];
		}
	}

	return finalNm;
}


int main()
{
	SignatureDecorator sdl;

	string n = "RacEcaR";
	vector<string> c = { "surround" };
	vector<string> d = { "([{/" };

	string fN = sdl.applyDecoration(n, c, d);

	return 0;
}

