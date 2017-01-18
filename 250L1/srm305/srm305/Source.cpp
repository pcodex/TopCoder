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

class MultiRead
{
public:
	int minCycles(string trace, int procs);
};

int MultiRead::minCycles(string trace, int procs)
{
	int cycl = 0;
	
	int i = 0;
	while (i < trace.length())
	{
		int rcnt = 0;
		while (trace[i] == 'R')
		{
			i++;
			rcnt++;
		}
		cycl += rcnt / procs;
		if (rcnt%procs > 0)
			cycl+=1;

		while (trace[i] == 'W')
		{
			cycl++;
			i++;
		}
	}
	return cycl;

	return cycl;
}

int main()
{
	MultiRead m;
	string t = "RWRRWWRWRWRRRWWRRRRWRRWRRWRRRRRRRRRWRWRWRRRRWRRRRR";
	int p = 4;
	int cys = m.minCycles(t, p);
	return 0;
}