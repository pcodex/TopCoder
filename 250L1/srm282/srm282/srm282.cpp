// srm282.cpp : Defines the entry point for the console application.
//

#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>

using namespace std;

class FixTheAverage
{
public:
	double add(vector <double> list, double target);
};

double FixTheAverage::add(vector <double> list, double target)
{
	double 	out = target*(list.size() + 1);

	double sum = 0;
	for (int i = 0; i < list.size(); ++i)
		sum += list[i];

	out = out - sum;

	return out;
}


int main()
{
	FixTheAverage tf;
	vector<double> l = { 3.0, 7.0, 2.5 };
	double t = 4.5;
	double nu = tf.add(l, t);

	return 0;
}

