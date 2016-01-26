// srm223.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class MostProfitable
{
public:
	string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items);
};


string MostProfitable::bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items)
{
	int max = 0;
	string profIt = "";

	for (int i = 0; i < prices.size(); ++i)
	{
		if ((sales[i] * prices[i]) - (sales[i] * costs[i]) > max)
		{
			max = (sales[i] * prices[i]) - (sales[i] * costs[i]);
			profIt = items[i];
		}
	}

	return profIt;
}

int main()
{
	MostProfitable mpf;

	vector<int> c = {100, 120, 150, 1000 };
	vector<int> p = { 110, 110, 200, 2000 };
	vector<int> s = { 20, 100, 50, 3 };
	vector<string> i = { "Video Card", "256M Mem", "CPU/Mobo combo", "Complete machine" };

	
	string out = mpf.bestItem(c, p, s, i);
	return 0;
}

