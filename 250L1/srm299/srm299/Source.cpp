#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <set>
#include <functional>

using namespace std;

class TemperatureScales
{
public:
	double convert(int f1, int b1, int f2, int b2, int t);
};

double TemperatureScales::convert(int f1, int b1, int f2, int b2, int t)
{
	int unit1 = abs(f1 - b1);
	int unit2 = abs(f2 - b2);

	double eqv = (double)unit2 / (double)unit1;

	int howmany = abs(t - f1);
	double toadd = eqv*howmany;

	double t2;
	if (t<f1)
		t2 = f2 - toadd;
	else
		t2 = f2 + toadd;

	return t2;

}


int main()
{
	TemperatureScales t;
	//double t2= t.convert(-1000,-999,-1000,1000,1000);
	double t2 = t.convert(-507, 239, -802, -469, -678);
	return 0;
}