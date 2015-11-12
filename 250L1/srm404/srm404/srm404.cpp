// srm404.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class ReadingBooks
{
public:
	int countBooks(vector <string> readParts);
};

int ReadingBooks::countBooks(vector <string> readParts)
{

	set<string> checkBk;
	int bkcnt = 0;
	string prevsection;
	string currsection;
	for (int i = 0; i < readParts.size(); ++i)
	{
		currsection = readParts[i];

		if (currsection == prevsection) //also works
			checkBk.clear();


		checkBk.insert(currsection);
		prevsection = currsection;//also works

		if (checkBk.size() == 3)
		{
			bkcnt += 1;
			checkBk.clear();
		}
	}

	return bkcnt;
}

int main()
{
	ReadingBooks rbs;
	vector<string> readPt = { "introduction", "introduction", "introduction", "story", "introduction", "introduction", "edification", "edification", "edification" };
	int res = rbs.countBooks(readPt);
	return 0;
}

