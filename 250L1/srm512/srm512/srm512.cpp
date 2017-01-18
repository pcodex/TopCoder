// srm512.cpp : Defines the entry point for the console application.
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

class MarbleDecoration
{
public:
	int maxLength(int R, int G, int B);
};

int MarbleDecoration::maxLength(int R, int G, int B)
{
	vector<int> v;
	v.push_back(R);
	v.push_back(G);
	v.push_back(B);

	sort(v.begin(), v.end());

	int largest = v[2];
	int smaller = v[1];

	int ans = smaller * 2;
	largest = largest - smaller;
	if (largest > 0)
		ans += 1;

	return ans;
}

int main()
{
	MarbleDecoration md;
	int ans = md.maxLength(2, 3, 5);
	return 0;
}

