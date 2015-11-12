// srrm551.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class ColorfulBricks
{
public:
	int countLayouts(string bricks);
};


int ColorfulBricks::countLayouts(string bricks)
{
	sort(bricks.begin(), bricks.end());

	map<char, int>mm;
	for (int i = 0; i < bricks.length(); ++i)
	{
		mm[bricks[i]] = count(bricks.begin(), bricks.end(), bricks[i]);
	}

	if (mm.size() > 2 || mm.size() < 1)
		return 0;
	else if (mm.size() == 1)
		return 1;
	else
		return 2;

}


int main()
{
	ColorfulBricks cb;
	string ss = "AAAAB";
	int re = cb.countLayouts(ss);
	return 0;
}

