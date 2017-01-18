// srm633.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

class Target
{
public:
	vector <string> draw(int n);
};

vector <string> Target::draw(int n)
{
	int k = (n - 1) / 4;

	vector<string> drawing;	

	for (int i = 0; i <= k; ++i)
	{
		int knum = k - i;

		if (i == 0){
			string each = string(n, '#');
			drawing.push_back(each);
		}
		
		else
		{
			string first = string(n, ' ');
			int len = first.length();
			int pos = 0;
			for (int j = 0; j < i; ++j)
			{
				first[pos] = '#';
				first[len - pos - 1] = '#';
				pos += 2;
			}
			drawing.push_back(first);

			string second = first;
			int pos2 = 0;
			for (int j = 0; j < i; ++j)
			{
				second[pos2] = '#';
				pos2 += 2;
			}

			//pos2 += 2;
			int noofstars = (4 * knum) + 1;
			for (int z = 0; z < noofstars; ++z)
			{
				second[pos2] = '#';
				pos2 += 1;
			}
			drawing.push_back(second);
		}
	}

	size_t currsz = drawing.size();
	for (int back = currsz - 2; back >= 0; --back)
	{
		drawing.push_back(drawing[back]);
	}
	return drawing;
}


int main()
{
	Target tg;

	vector<string> out = tg.draw(21);

	for (int z = 0; z < out.size(); ++z)
	{
		cout << out[z] << "\n";		
	}
	return 0;
}

