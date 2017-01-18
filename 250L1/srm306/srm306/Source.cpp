#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

class SortMachine
{
public:
	int countMoves(vector <int> a);
};

int SortMachine::countMoves(vector <int> a)
{
		int moves = 0;
		
		bool tosort = true;
		int nt = 1;
		while (tosort)
		{
			int last = a[a.size() - nt];		
			vector<int> mv;

			for (int i = 0; i < a.size() - nt; ++i)
			{
				if (a[i] > last)
					mv.push_back(a[i]);
			}

			if (mv.size() == 0)
			{
				nt += 1;				
			}
			else
			{
				int least = *min_element(mv.begin(), mv.end());

				a.push_back(least);
				moves++;
				vector<int>::iterator it = find(a.begin(), a.end() - 2, least);
				a.erase(it);
				nt = 1;
			}

			for (int i = 0; i < a.size()-1; ++i)
			{
				if (a[i] > a[i + 1])
				{
					tosort = true;
					break;
				}
				else
					tosort = false;
			}

			if (!tosort)
				break;
		}	

	return moves;
}

int main()
{
	SortMachine sm;
	vector<int> av = { -2, -8, 9, 0 };
	int no = sm.countMoves(av);
	return 0;
}