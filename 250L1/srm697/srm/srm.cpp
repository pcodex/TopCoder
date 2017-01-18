// srm.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>
#include <numeric>

using namespace std;


class TriangleMaking
{
public:
	int maxPerimeter(int a, int b, int c);
};

int TriangleMaking::maxPerimeter(int a, int b, int c)
{
	bool isTri = false;	

	while (!isTri)
	{
		if ((a == b) && (b == c))
		{
			isTri = true;
			break;
		}

		if (a + b > c)
		{
			if (a + c > b)
			{
				if (b + c > a)
					isTri = true;
				else
					a -= 1;
			}
			else
			{
				b -= 1;
			}
		}
		else
		{
			c -= 1;
		}
	}

	if (isTri)
		return a + b + c;
}


int main()
{
	TriangleMaking tm;

	int per = tm.maxPerimeter(100, 10, 0);
	return 0;
}

