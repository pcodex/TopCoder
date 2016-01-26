// srm209.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class MovingAverages
{
public:
	vector <int> calculate(vector <string> times, int n);
};

vector <int> MovingAverages::calculate(vector <string> times, int n)
{
	vector<string> tcpy = times;
	vector<int> insecs;
	vector<int> ans;

	for (int i = 0; i < tcpy.size(); ++i)
	{
		string atime = tcpy[i];

		size_t pos = 0;

		int tInsec=0;
		int cnt = 0;
		while (pos != std::string::npos)
		{
			pos = atime.find(":", pos);			
			if (pos != std::string::npos)
			{
				string hr = atime.substr(0, pos);
				atime = atime.substr(pos + 1, atime.length());
				stringstream sshr(hr);
				int hrno;
				sshr >> hrno;

				if (cnt == 0)
				{
					tInsec += (hrno * 60 * 60);
					cnt++;
				}
				else
				{
					tInsec += (hrno * 60 );
				}

			}
			else
			{
				stringstream sshr(atime);
				int hrno;
				sshr >> hrno;

				tInsec += hrno;
			}
		}

		insecs.push_back(tInsec);
	}

	int howManyAvgs = times.size() - n + 1;

	for (int i = 0; i < howManyAvgs; ++i)
	{
		int sum = 0;

		for (int j = i; j < i+n; ++j)
		{
			sum += insecs[j];
		}
		int avg = sum / n;

		ans.push_back(avg);
	}


	return ans;
}


int main()
{
	MovingAverages mv;

	vector<string> tv = { "01:19:10", "01:17:40", "01:19:44", "01:17:23", "01:17:07" };

	int n = 3;

	vector<int> ans;

	ans = mv.calculate(tv, n);
	return 0;
}

