// srm235.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <numeric>

using namespace std;

class NoisySensor
{
public:
	vector <int> medianFilter(vector <int> data);
};

vector <int> NoisySensor::medianFilter(vector <int> data)
{
	vector<int> tmp;
		vector<int> output = { data[0] };

	for (int i = 1; i < data.size()-1; ++i)
	{
		tmp.push_back(data[i]);
		tmp.push_back(data[i-1]);
		tmp.push_back(data[i+1]);
		sort(tmp.begin(), tmp.end());
		output.push_back(tmp[1]);
		tmp.clear();
	}

	if (data.size()>1)
	output.push_back(data[data.size() - 1]);
	return output;
}


int main()
{
	NoisySensor ns;

	vector<int> d = {static_cast<int>(-2147483648)};

	vector<int> out = ns.medianFilter(d);
	return 0;
}

