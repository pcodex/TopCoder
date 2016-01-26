// srm228.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class ProfitCalculator
{
public:
	int percent(vector <string> items);
};


int ProfitCalculator::percent(vector <string> items)
{
	float totprice = 0;
	float totcost = 0;

	for (int i = 0; i < items.size(); ++i)
	{
		stringstream ss(items[i]);
		float nos;
		float price[2];
		int j = 0;

		while (ss >> nos)
		{
			price[j++] = nos;
		}

		totprice += price[0];
		totcost += price[1];
	}

	int margin = ((totprice - totcost) / (totprice)) * 100;

	return margin;
}


	int main()
{

	ProfitCalculator pcl;

	vector<string> it = { "012.99 008.73", "099.99 050.00", "123.45 101.07" };

	int margin = pcl.percent(it);
	return 0;
}

