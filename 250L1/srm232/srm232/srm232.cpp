// srm232.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;


class BritishCoins
{
public:
	vector <int> coins(int pence);
};

vector <int> BritishCoins::coins(int pence)
{
	//12 p = 1 shill
	//20 shill = 1 pd
	vector<int> v;

	int shill = pence / 12;
	int penceleft = pence - (shill * 12);
	int pound = shill / 20;
	int shillleft = shill - (pound * 20);

	v.push_back(pound);
	v.push_back(shillleft);
	v.push_back(penceleft);

	return v;
}



int main()
{

	BritishCoins bc;
	
	vector<int> cp = bc.coins(533);

	return 0;
}

