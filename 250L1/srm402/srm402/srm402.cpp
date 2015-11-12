// srm402.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class WordAbbreviation
{
public:
	vector <string> getAbbreviations(vector <string> words);
};

vector<string> WordAbbreviation::getAbbreviations(vector<string> words)
{
	vector<string> res;

	for (int i = 0; i < words.size(); ++i)
	{
		bool prefixfound = false;
		int j = 1;
		string pfx = "";
		while (!prefixfound)
		{
			pfx = words[i].substr(0,j);

			if (words.size() == 1){
				prefixfound = true;
				break;
			}

			for (int z = 0; z < words.size(); ++z)
			{
				if (z == i)
					continue;

				if (words[z].find(pfx) == 0)
				{
					j += 1;
					prefixfound = false;
					break;
				}
				else
				{
					prefixfound = true;
				}
			}
		}

		res.push_back(pfx);

	}

	return res;

}


int main()
{
	WordAbbreviation wab;
	vector<string> vsw = { "oneword" };

	vector<string> opw = wab.getAbbreviations(vsw);

	return 0;
}

