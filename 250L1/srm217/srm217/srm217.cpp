// srm217.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>

using namespace std;

class FuelConsumption
{
public:
	double maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel);
};

double FuelConsumption::maximalDistance(vector <int> velocities, vector <int> consumptions, int fuel)
{

	double max = 0;

	for (int i = 0; i < velocities.size(); ++i)
	{
		double ithConsume = (double)fuel / consumptions[i];
		double dist = ithConsume*velocities[i];

		if (dist > max)
			max = dist;		
	}

	return max;

}


int main()
{

	FuelConsumption fc;

	vector<int> v = { 5, 10, 20, 40, 80 };
	vector<int> c = { 1000, 2500, 6250, 9000, 18000 };
	int fu = 47832;

	double di = fc.maximalDistance(v, c, fu);
	return 0;
}

