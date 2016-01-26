// srm236.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

class MassiveNumbers
{
public:
	string getLargest(string numberA, string numberB);
};


string MassiveNumbers::getLargest(string numberA, string numberB)
{
	string ba, ex;

	size_t pos = numberA.find('^');
	ba = string(numberA, 0, pos);
	ex = string(numberA, pos + 1, numberA.size() - 1 - pos);

	stringstream ssA(ba);
	int base;
	ssA >> base;

	ssA.str("");
	ssA.clear();

	ssA << ex;
	int exp;
	ssA >> exp;

	float out1 = exp*log(base);

	size_t pos2 = numberB.find("^");
	ba = string(numberB, 0, pos2);
	ex = string(numberB, pos2 + 1, numberB.size() - 1 - pos2);
	stringstream ssB(ba);
	ssB >> base;

	ssB.str(string());
	ssB.clear();
	ssB << ex;
	ssB >> exp;

	float out2 = exp*log(base);

	if (out1 > out2)
		return numberA;
	else
		return numberB;

}



int main()
{
	MassiveNumbers mn;
	string a = "46^779", b = "873^636";	

string out=	mn.getLargest(a, b);
	return 0;
}

