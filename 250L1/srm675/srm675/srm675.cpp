// srm675.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

class LengthUnitCalculator
{
public:
	double calc(int amount, string fromUnit, string toUnit);
};


double LengthUnitCalculator::calc(int amount, string fromUnit, string toUnit)
{
	enum uniten { in = 0, ft, yd, mi };

	char frmUn = -1;
	char toUn = -1;

	if (fromUnit.find("in")!=std::string::npos)
		frmUn = in;
	else if (fromUnit.find("ft") != std::string::npos)
		frmUn = ft;
	else if (fromUnit.find("yd") != std::string::npos)
		frmUn = yd;
	else
		frmUn = mi;

	
	if (toUnit.find("in") != std::string::npos)
		toUn = in;
	else if (toUnit.find("ft") != std::string::npos)
		toUn = ft;
	else if (toUnit.find("yd") != std::string::npos)
		toUn = yd;
	else
		toUn = mi;

	double ans = 0;

	switch (frmUn)
	{
	case 0:
	{
		switch (toUn)
		{
			case 0:
				ans = amount;
				break;
			case 1:
				ans = (1.0/12.0)*amount;
				break;
			case 2:
				ans = (1.0/36.0)*amount;
				break;
			case 3:
				ans = (1.0/36.0)*(1.0/1760.0)*amount;
				break;
		}
		break;
	}
	case 1:
	{
		switch (toUn)
		{
			case 0:
				ans = amount * 12;
			break;

			case 1:
				ans = amount;
				break;
			
			case 2:
				ans = (1.0/3.0)*amount;
				break;

			case 3:
				ans = (1.0)/(3.0*1760.0);
				ans = ans*amount;
				break;
		}
		break;		
	}
	case 2:
	{
		switch (toUn)
		{
			case 0:
				ans = amount * 3 * 12;
				break;
			case 1:
				ans = amount * 3;
				break;
			case 2:
				ans = amount;
				break;
			case 3:
				ans = (1.0/1760.0)*amount;
				break;
		}
		break;
	}
	case 3:
	{
		switch (toUn)
		{
		case 0:
			ans = 1760 * 3 * 12 * amount;
			break;
		case 1:
			ans = 1760 * 3 * amount;
			break;
		case 2:
			ans = 1760 * amount;
			break;
		case 3:
			ans = amount;
			break;
		}
		break;
	}
	
		default:
			break;

	}

	return ans;

}



int main()
{

	LengthUnitCalculator kc;
	int amt = 47;
	string frm = "mi";
	string to = "mi";

	double ret = kc.calc(amt, frm, to);

	return 0;
}

