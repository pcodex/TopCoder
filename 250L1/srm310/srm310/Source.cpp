#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class MeasuringTemperature
{
public:
	double averageTemperature(vector<int> measuredValues);
};

double MeasuringTemperature::averageTemperature(vector<int> measuredValues)
{
	int cnt = measuredValues.size();
	vector<int> invmask(measuredValues.size());

	for (int i = 0; i < measuredValues.size(); ++i)
	{
		if (measuredValues[i] < -273)
		{
			cnt--;
			invmask[i] = 1;
			continue;
		}

		int invalidlftcnt = 0;
		int invalidrtcnt = 0;
		int lftcnt = 0;
		int rtcnt = 0;
		bool lftinvld = false;
		bool rtinvld = false;

		if ((i - 1) >= 0)
		{
			lftcnt++;
			if (abs(measuredValues[i - 1] - measuredValues[i]) > 2)
			{
				invalidlftcnt += 1;
			}			
		}

		if ((i - 2) >= 0)
		{
			lftcnt++;
			if (abs(measuredValues[i - 2] - measuredValues[i]) > 2)
			{
				invalidlftcnt += 1;
			}			
		}

		if ((lftcnt > 0)&&(lftcnt == invalidlftcnt))
			lftinvld = true;

		if ((i + 2) < measuredValues.size())
		{
			rtcnt++;
			if (abs(measuredValues[i + 2] - measuredValues[i]) > 2)
			{
				invalidrtcnt += 1;
			}
		}

		if ((i + 1) < measuredValues.size())
		{
			rtcnt++;
			if (abs(measuredValues[i + 1] - measuredValues[i]) > 2)
			{
				invalidrtcnt += 1;
			}
		}
		
		if ((rtcnt>0)&&(rtcnt == invalidrtcnt))
			rtinvld = true;

		bool allinvld = false;
		if (lftcnt > 0)
		{
			if (lftinvld)
			{
				allinvld = true;
				if (rtcnt > 0)
				{
					if (rtinvld)
						allinvld = true;
					else
						allinvld = false;
				}			
			}			
			if (allinvld)
			{
				invmask[i] = 1;
				cnt-=1;
				continue;
			}
		}

		if (rtcnt > 0 && lftcnt==0)
		{
			if (rtinvld)
			{
				allinvld = true;
			}

			if (allinvld)
			{
				invmask[i] = 1;
				cnt-=1;
				continue;
			}
		}		
	}

	double sum = 0;
	for (int i = 0; i < measuredValues.size(); ++i)
	{
		if (invmask[i] != 1)
			sum += measuredValues[i];
	}

	if (cnt == 0)
		return -300;

	double avg = sum / cnt;

	return avg;
}

int main()
{
	MeasuringTemperature mt;
	vector<int> v = { 10, 20, 30, 40 };
	double cn = mt.averageTemperature(v);
	return 0;
}