// srm687.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class Quorum
{
public:
	int count(vector <int> arr, int k);
};


int Quorum::count(vector <int> arr, int k)
{
	sort(arr.begin(), arr.end());
	int noofppl = 0;

	for (int i = 0; i < k; ++i)
		noofppl += arr[i];

	return noofppl;

}


int main()
{
	Quorum qq;
	vector<int> ar = { 50, 2, 9, 49, 38 };
	int l = 3;

	int ans = qq.count(ar, l);
	return 0;
}

