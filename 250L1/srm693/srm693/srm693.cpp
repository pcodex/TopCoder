// srm693.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
using namespace std;

class TriangleEasy
{	
public:
	int find(int n, vector <int> x, vector <int> y);
};



int TriangleEasy::find(int n, vector <int> x, vector <int> y)
{
	if (x.size() == 0 || y.size() == 0)
		return 3;

	int edgesneeded = 2;
	int oldedgesneeded1 = edgesneeded;
	int oldedgesneeded2 = edgesneeded;
	int oldedgesneeded3 = edgesneeded;

	int u = -1, v = -1, w = -1;

	for (int i = 0; i < x.size(); ++i)
	{
		for (int j = 0; j < x.size(); ++j)
		{
			if (i == j)
				continue;

			if (x[i] == x[j])
			{
				if (y[i] == y[j])
					continue;
				else
				{
					u = x[i];
					v = y[i];
					w = y[j];
					edgesneeded -= 1;
					break;
				}
			}			
		}
		if (edgesneeded == 1)
		{
			vector<int>::iterator it = x.begin();
			while ((it = std::find(it, x.end(), v)) != x.end())
			{
				size_t idx = distance(x.begin(), it);
				if (y[idx] == w){
					edgesneeded -= 1;
					break;
				}
				it++;
			}

			if (oldedgesneeded1 > edgesneeded)
				oldedgesneeded1 = edgesneeded;
			
			if (edgesneeded == 0)
				break;
			
			vector<int>::iterator it2 = y.begin();
			while ((it2 = std::find(it2, y.end(), v)) != y.end() && (edgesneeded == 1))
			{
				size_t idx = distance(y.begin(), it2);
				if (x[idx] == w){
					edgesneeded -= 1;
					break;
				}
				it2++;
			}
			
			if (oldedgesneeded1 > edgesneeded)
				oldedgesneeded1 = edgesneeded;

			if (edgesneeded == 0)
				break;
		}

		edgesneeded = 2;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	
	if (edgesneeded == 2)
	{
		for (int i = 0; i < y.size(); ++i)
		{
			for (int j = 0; j < y.size(); ++j)
			{
				if (i == j)
					continue;

				if (y[i] == y[j])
				{
					if (x[i] == x[j])
						continue;
					else
					{
						u = y[i];
						v = x[i];
						w = x[j];
						edgesneeded -= 1;
						break;
					}
				}
			}
			if (edgesneeded == 1)
			{
				vector<int>::iterator it = x.begin();
				while ((it = std::find(it, x.end(), v)) != x.end())
				{
					size_t idx = distance(x.begin(), it);
					if (y[idx] == w){
						edgesneeded -= 1;
						break;
					}
					it++;
				}

				if (oldedgesneeded2 > edgesneeded)
					oldedgesneeded2 = edgesneeded;

				if (edgesneeded == 0)
					break;

				vector<int>::iterator it2 = y.begin();
				while ((it2 = std::find(it2, y.end(), v)) != y.end() && (edgesneeded == 1))
				{
					size_t idx = distance(y.begin(), it2);
					if (x[idx] == w){
						edgesneeded -= 1;
						break;
					}
					it2++;
				}

				if (oldedgesneeded2 > edgesneeded)
					oldedgesneeded2 = edgesneeded;

				if (edgesneeded == 0)
					break;
			}	

			edgesneeded = 2;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	if (edgesneeded == 2)
	{
		for (int i = 0; i < x.size(); ++i)
		{
			for (int j = 0; j < y.size(); ++j)
			{
				if (i == j)
					continue;

				if (x[i] == y[j])
				{
					if (y[i] == x[j])
						continue;
					else
					{
						u = x[i];
						v = y[i];
						w = x[j];
						edgesneeded -= 1;
						break;
					}
				}
			}
			if (edgesneeded == 1)
			{
				vector<int>::iterator it = x.begin();
				while ((it = std::find(it, x.end(), v)) != x.end())
				{
					size_t idx = distance(x.begin(), it);
					if (y[idx] == w){
						edgesneeded -= 1;
						break;
					}
					it++;
				}

				if (oldedgesneeded3 > edgesneeded)
					oldedgesneeded3 = edgesneeded;

				if (edgesneeded == 0)
					break;

				vector<int>::iterator it2 = y.begin();
				while ((it2 = std::find(it2, y.end(), v)) != y.end() && (edgesneeded == 1))
				{
					size_t idx = distance(y.begin(), it2);
					if (x[idx] == w){
						edgesneeded -= 1;
						break;
					}
					it2++;
				}

				if (oldedgesneeded3 > edgesneeded)
					oldedgesneeded3 = edgesneeded;

				if (edgesneeded == 0)
					break;
			}

			edgesneeded = 2;
		}
	}
	
	vector<int> mins;
	mins.push_back(oldedgesneeded1);
	mins.push_back(oldedgesneeded2);
	mins.push_back(oldedgesneeded3);

	vector<int>::iterator zit = min_element(mins.begin(),mins.end());
	edgesneeded = *zit;

	return edgesneeded;
}

int main()
{
	TriangleEasy tes;
	
	vector<int> x = { 0, 2 };
	
	vector<int> y = { 1, 0 };

	int out = tes.find(3, x, y);

	return 0;
}

