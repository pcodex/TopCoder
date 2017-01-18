// srm513.cpp : Defines the entry point for the console application.
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
#include <numeric>

using namespace std;

class TrainingCamp
{
public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics);
};

vector <string> TrainingCamp::determineSolvers(vector <string> attendance, vector <string> problemTopics)
{
	int noofstud = attendance.size();
	int noofdays = attendance[0].length();
	int noofprobs = problemTopics.size();


	vector<string> ans(noofstud, string(noofprobs, ' '));
	for (int z = 0; z < noofstud; ++z)
	{		
		for (int i = 0; i < noofprobs; ++i)
		{
			bool studok = true;
			for (int j = 0; j < problemTopics[i].length(); ++j)
			{
				if (problemTopics[i][j] == '-')
					continue;
				else if (problemTopics[i][j] == 'X')
				{
					if (attendance[z][j] == 'X')
						studok = true;
					else
					{
						studok = false;
						break;
					}
				}
			}
			if (!studok)
				ans[z][i] = '-';
			else
				ans[z][i] = 'X';
		}		
	}

	return ans;
}

int main()
{
	TrainingCamp tc;
	vector <string> v1 = { "-----",
		"XXXXX" }
	;

	vector<string> v2 = { "XXXXX",
		"-----",
		"--X-X" }
	;

	vector<string> vo = tc.determineSolvers(v1, v2);
	return 0;

}

