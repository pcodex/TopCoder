// srm267.cpp : Defines the entry point for the console application.
//

#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <set>
#include <cctype>

using namespace std;

class TaxTable
{
public:
	int income(int taxAmount);
};

int TaxTable::income(int taxAmount)
{
	double t25amt = round((((taxAmount) + 6525) * 100) / 25);
	if (t25amt >= 100000 && t25amt < 117250)
	{		
		return (int)t25amt;
	}
	

	double t28amt = round((((taxAmount) + 10042.5) * 100) / 28);
	if (t28amt >= 117250 && t28amt < 178650)
	{		
		return (int)t28amt;
	}

	double t33amt = round((((taxAmount) + 18975) * 100) / 33);
	if (t33amt >= 178650 && t33amt < 319100)
	{		
		return (int)t33amt;
	}

	double t35amt = round((((taxAmount) + 25357) * 100) / 35);
	if (t35amt >= 319100)
	{		
		return (int)t35amt;
	}
		

	return -1;

}

int main()
{
	TaxTable tt;

	int incom = tt.income(999923);
	return 0;
}

