// srm219.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <math.h>

using namespace std;

class WaiterTipping
{
public:
	int maxPercent(int total, int taxPercent, int money);
};


int WaiterTipping::maxPercent(int total, int taxPercent, int money)
{
	int tipPer = -1;
	
	float taxAmt = (float)total*taxPercent / 100;
	
	float tipAmt = floor(money - (total + taxAmt));
	
	if (tipAmt >= 0){

		tipPer = (tipAmt * 100) / total;

		while (total + floor(total*taxPercent / 100) + floor(total*tipPer / 100) <= money)
		{
			tipPer += 1;
		}
		tipPer -= 1;
	}

	return tipPer;

}


	int main()
{

	WaiterTipping wt;

	int t = 850;
	int tp = 8;
	int m = 870;
	int tpPer = wt.maxPercent(t, tp, m);
	return 0;
}

