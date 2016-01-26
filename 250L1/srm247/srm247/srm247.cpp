// srm247.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
#include <math.h>

using namespace std;

class TriangleType
{
public:
	string type(int a, int b, int c);
};


string TriangleType::type(int a, int b, int c)
{
	vector<int> sides = { a, b, c };
	sort(sides.begin(), sides.end());

		if (sides[0] + sides[1] <= sides[2])
			return "IMPOSSIBLE";
		else if ((sides[0] * sides[0]) + (sides[1] * sides[1]) == (sides[2] * sides[2]))
			return "RIGHT";
		else if ((sides[0] * sides[0]) + (sides[1] * sides[1]) < (sides[2] * sides[2]))
			return "OBTUSE";
		else if ((sides[0] * sides[0]) + (sides[1] * sides[1]) > (sides[2] * sides[2]))
			return "ACUTE";
	
}


	int main()
{
	return 0;
}

