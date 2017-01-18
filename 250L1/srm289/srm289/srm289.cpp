// srm289.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <functional>

using namespace std;

class ObjectFall
{
public:
	int howLong(int x, int y, vector <string> obstacles);
};

int ObjectFall::howLong(int x, int y, vector <string> obstacles)
{
	int drop = y;
	sort(obstacles.begin(), obstacles.end());

	map<int, string, std::greater<int> > ml;

	for (int i = 0; i < obstacles.size(); ++i)
	{
		stringstream ss(obstacles[i]);
		int yo, x1, x2;

		ss >> yo;
		ss >> x1; ss >> x2;
		stringstream ss2;
		ss2 << x1 << " " << x2;
		string xs = ss2.str();

		ml[yo] = xs;
	}

	map<int, string, std::greater<int> >::iterator mit;
	for (mit = ml.begin(); mit != ml.end(); mit++)
	{
		int y0 = mit->first;
		if (y0 <= y)
		{
			stringstream ss(mit->second);
			int x1, x2;
			ss >> x1;
			ss >> x2;

			if ((x >= x1) && (x <= x2))
			{
				drop += 5;
				x = x2;
				y = y0;
			}
		}
	}

	return drop;	
}

int main()
{
	ObjectFall of;
	int x = 645;
	int y = 802;
	vector<string> o = { "739 038 799", "916 169 791", "822 372 911", "162 125 992", "261 307 545",
		"510 031 765", "592 723 742", "477 315 676", "566 143 617", "337 114 664",
		"986 648 883", "116 230 680", "254 746 943", "742 948 988", "060 117 401",
		"634 035 433", "288 741 864", "819 626 730", "906 071 222", "554 100 121",
		"573 051 551", "949 528 915", "562 151 223", "857 135 243", "621 115 474",
		"588 405 615", "895 812 919", "052 378 836", "858 116 505", "285 428 469",
		"792 244 250", "109 265 637", "714 804 885", "625 150 410", "518 593 921",
		"282 235 339", "081 212 659", "663 047 982", "556 194 345", "798 150 938",
		"391 026 813", "886 348 796", "975 007 743", "053 854 895", "243 561 875" };
	int time = of.howLong(x, y, o);

	return 0;
}

