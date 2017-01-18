#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;


class CustomerStatistics
{
public:
	vector <string> reportDuplicates(vector <string> customerNames);
};

vector <string> CustomerStatistics::reportDuplicates(vector <string> customerNames)
{

	map<string, int> mc;

	for (int i = 0; i < customerNames.size(); ++i)
	{
		mc[customerNames[i]] += 1;
	}

	vector<string> out;
	map<string, int>::iterator mit;
	for (mit = mc.begin(); mit != mc.end(); mit++)
	{
		if (mit->second > 1)
		{
			stringstream ss;
			ss << mit->second;
			string occur = ss.str();
			string label = mit->first + " " + occur;
			out.push_back(label);
		}
	}

	return out;
}


int main()
{
	CustomerStatistics cs;
	vector<string> c = { "YETTI", "YETTI", "YETTI", "BIGFOOT", "BIGFOOT" };
	cs.reportDuplicates(c);
	return 0;
}