#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class CuttingPoles
{
public:
	int countCuts(vector <int> poles);
};

int CuttingPoles::countCuts(vector <int> poles)
{
	int noC = 0;

	int avg = accumulate(poles.begin(), poles.end(), 0) / poles.size();	
	vector<int> chk=poles;
	sort(poles.begin(), poles.end());

	while (chk.size()!=1)
	{		
			vector<int>::iterator itmin = min_element(poles.begin(), poles.end());
			vector<int>::iterator itmax = max_element(poles.begin(), poles.end());

			if (*itmin != *itmax)
			{
				int idmin = distance(poles.begin(), itmin);
				int idmax = distance(poles.begin(), itmax);
			
				poles[idmin] += poles[idmax] - avg;
				poles[idmax] = avg;
				noC++;
			}

			sort(poles.begin(), poles.end());
			int avg = accumulate(poles.begin(), poles.end(), 0) / poles.size();
	
			chk = poles;
		
			vector<int>::iterator ed = unique(chk.begin(), chk.end());
			chk = vector<int>(chk.begin(),ed);
	}

	return noC;
}

int main()
{
	CuttingPoles cp;
	vector<int> p = { 10, 10, 10 };

	int c = cp.countCuts(p);
	return 0;
}