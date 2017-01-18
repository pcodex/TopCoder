// srm503.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

class ToastXRaspberry
{
public:
	int apply(int upper_limit, int layer_count);
};


int ToastXRaspberry::apply(int upper_limit, int layer_count)
{

	int noApp = 0;
	if (upper_limit > 0)
	 noApp = layer_count / upper_limit;

	int ans = 0;

	if (noApp < 1 && layer_count>0)
		ans = 1;
	else
	{
		if (layer_count%upper_limit == 0)
			ans = noApp;
		else
		{
			noApp += 1;
			ans = noApp;
		}	
	}

	return ans;


}

int main()
{
	ToastXRaspberry trb;

	int res = trb.apply(2, 5);
	return 0;
}

