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

class PaperRockScisQuals
{
public:
	int whoPassed(vector <string> players);
};

int PaperRockScisQuals::whoPassed(vector <string> players)
{
	int noofp = players.size();
	vector<float> pscore(noofp,0);

	for (int i = 0; i < players.size()-1; ++i)
	{		
		for (int z = i + 1; z < players.size(); ++z)
		{

			int p1cnt = 0, p2cnt = 0;
			for (int j = 0; j < players[0].length(); ++j)
			{
				if ((players[i][j] == 'P') && (players[z][j] == 'R'))
					p1cnt++;
				else if ((players[i][j] == 'P') && (players[z][j] == 'S'))
					p2cnt++;
				else if ((players[i][j] == 'R') && (players[z][j] == 'P'))
					p2cnt++;
				else if ((players[i][j] == 'R') && (players[z][j] == 'S'))
					p1cnt++;
				else if ((players[i][j] == 'S') && (players[z][j] == 'P'))
					p1cnt++;
				else if ((players[i][j] == 'S') && (players[z][j] == 'R'))
					p2cnt++;
				else
					continue;
			}
			if (p1cnt > p2cnt)
				pscore[i]++;
			else if (p2cnt > p1cnt)
				pscore[z]++;
			else
			{
				pscore[i] += 0.5;
				pscore[z] += 0.5;
			}

		}		
	}

	float hscore = *(max_element(pscore.begin(), pscore.end()));
	vector<float>::iterator it = find(pscore.begin(), pscore.end(), hscore);
	int idx = distance(pscore.begin(),it);

	return idx;

}

int main()
{
	PaperRockScisQuals p;
	vector<string> pl = { "PPRPS", "RRRPR", "SSPRS", "SSPRR", "PPRSP", "SPRPS", "SPRSP", "PRSPR", "PRSPR" };
	int win = p.whoPassed(pl);
	return 0;
}