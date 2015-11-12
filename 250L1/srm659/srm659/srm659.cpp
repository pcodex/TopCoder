// srm659.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <set>

using namespace std;

class FilipTheFrog
{
public:
	int countReachableIslands(vector <int> positions, int L);
};

int FilipTheFrog::countReachableIslands(vector <int> positions, int L)
{
	set<int> reached;

	reached.insert(positions[0]);
	int start = positions[0];

	//first time
	for (int i = 1; i <= L; ++i)
	{
		int fwd = positions[0] + i;
		int bwd = positions[0] - i;

		if (find(positions.begin(), positions.end(), fwd) != positions.end())
		{
			reached.insert(fwd);
			positions.erase(find(positions.begin(), positions.end(), fwd));
		}

		if (find(positions.begin(), positions.end(), bwd) != positions.end())
		{
			reached.insert(bwd);
			positions.erase(find(positions.begin(), positions.end(), bwd));
		}
	}
	positions.erase(find(positions.begin(), positions.end(), start));

	int currsz, prevsz = positions.size();
	while (positions.size() > 0)
	{		
		prevsz = positions.size();
		
		set<int>::iterator sit;
		for (sit = reached.begin(); sit != reached.end(); sit++)
		{
			for (int i = 1; i <= L; ++i)
			{
				int fwd = *sit + i;
				int bwd = *sit - i;

				if (find(positions.begin(), positions.end(), fwd) != positions.end())
				{
					reached.insert(fwd);
					positions.erase(find(positions.begin(), positions.end(), fwd));
				}

				if (find(positions.begin(), positions.end(), bwd) != positions.end())
				{
					reached.insert(bwd);
					positions.erase(find(positions.begin(), positions.end(), bwd));
				}
			}
		}
		currsz = positions.size();
		if (currsz < prevsz)
			continue;
		else
			break;

	}

	return reached.size();

}

int main()
{
	FilipTheFrog ffg;
	vector<int> posi = { 0 };
	int l = 1000;

	int cnt = ffg.countReachableIslands(posi, l);
	return 0;
}

