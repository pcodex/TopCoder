// srm270.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class BuyingCheap
{
public:
	int thirdBestPrice(vector <int> prices);
};

int BuyingCheap::thirdBestPrice(vector <int> prices)
{
	sort(prices.begin(), prices.end());
	vector<int>::iterator it = unique(prices.begin(), prices.end());

	vector<int> rankedl = vector<int>(prices.begin(), it);

	if (rankedl.size() < 3)
		return -1;
	else
		return(rankedl[2]);
}


int main()
{
	BuyingCheap bc;

	vector<int> p = { 10, 10, 10, 10, 20,
		20, 30, 30, 40, 40 };
	int pric = bc.thirdBestPrice(p);
	return 0;
}

