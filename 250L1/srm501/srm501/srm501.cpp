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

class FoxProgression
{
public:
	int theCount(vector <int> seq);
};


int FoxProgression::theCount(vector <int> seq)
{
	int sz = seq.size();
	int ret = 0;
	int apd = 0; float geod = 0;
	int newaptrm = 0, newgptrm = 0;
		
	if (sz == 1)
		ret = -1;

	if (sz > 1)
	{
		apd = (seq[1] - seq[0]);
		geod = (float)seq[1] / (float)seq[0];


		bool apdgood = false;
		bool geodgood = false;

		for (int i = 0; i < seq.size() - 1; ++i)
		{
			if ((seq[i+1] - seq[i]) == apd)
				apdgood = true;
			else
			{
				apdgood = false;
				break;
			}
			
		}


		for (int i = 0; i < seq.size() - 1; ++i)
		{			
			if (floor(geod) == geod)
			{
				if (((float)seq[i + 1] / seq[i]) == geod)
					geodgood = true;
				else
				{
					geodgood = false;
					break;
				}
			}
		}


		if (apdgood)
		{
			newaptrm = seq[seq.size() - 1] + apd;
			ret = 1;
		}

		if (geodgood)
		{
			newgptrm = seq[seq.size() - 1] * geod;
			if (newgptrm != newaptrm)
				ret += 1;
		}

	}
	
	return ret;	
}


int main()
{
	FoxProgression fp;
	vector<int> sw = { 5,3, 1 };


	int nos = fp.theCount(sw);

	return 0;
}