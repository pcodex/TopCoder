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


class Taxi
{
public:
	double maxDis(int maxX, int maxY, int taxiDis);
};

double Taxi::maxDis(int maxX, int maxY, int taxiDis)
{
	int mx = maxX;
	int my = maxY;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	int lftoe = 0;
	if (mx > my)
	{
		lftoe = taxiDis - mx;
		if (lftoe < 0)
		{
			lftoe = 0;
			x1 = 0;
			x2 = taxiDis;
			mx = 0;
		}
		else
		{
			x1 = 0;
			x2 = mx;
			mx = 0;
		}
	}
	else
	{
		lftoe = taxiDis - my;
		if (lftoe < 0)
		{
			lftoe = 0;
			y1 = 0;
			y2 = taxiDis;
			my = 0;
		}
		else
		{
			y1 = 0;
			y2 = my;
			my = 0;
		}
	}

	if (mx != 0)
	{
		x1 = mx - lftoe;
		if (x1 < 0)
			return -1.0;
		x2 = mx;
	}
	else if (my != 0)
	{
		y1 = my - lftoe;
		if (y1 < 0)
			return -1.0;
		y2 = my;
	}

	double ansx = pow((x1 - x2),2);
	double ansy = pow((y2 - y1), 2);	

	double ans = sqrt(ansx + ansy);

	return ans;

}

int main()
{
	Taxi t;
	double dis = t.maxDis(999990, 10, 999990);
	return 0;
}