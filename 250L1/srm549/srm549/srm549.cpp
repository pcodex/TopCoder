// srm549.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class BallAndHats
{
public:
	int getHat(string hats, int numSwaps);
};


int BallAndHats::getHat(string hats, int numSwaps)
{
	size_t hatpos = hats.find("o");
	int ret = hatpos;

	if (numSwaps > 0)
	{
		switch (hatpos)
		{
		case 0:
		case 2:
		{
			if (numSwaps % 2 == 0)
				ret = 0;
			else
				ret = 1;
			break;
		}

		case 1:
		{
			if (numSwaps % 2 == 0)
				ret = 1;
			else
				ret = 0;
		}
		break;
		}
	}
	return ret;
}

int main()
{
	BallAndHats bhs;
	string hats = "o..";
	int nswaps = 101;

	int finpos = bhs.getHat(hats, nswaps);
	return 0;
}

