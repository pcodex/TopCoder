// srm204.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <numeric>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Medici
{
public:
	int winner(vector <int> fame, vector <int> fortune, vector <int> secrets);
};


int Medici::winner(vector <int> fame, vector <int> fortune, vector <int> secrets)
{
	vector<int> themins;
	for (int i = 0; i < fame.size(); ++i)
	{
		int min = fame[i];
		if (fortune[i] < min)
			min = fortune[i];
		if (secrets[i] < min)
			min = secrets[i];

		themins.push_back(min);
	}

	vector<int>::iterator maximal;

	maximal = max_element(themins.begin(), themins.end());
	int idx = distance(themins.begin(), maximal);

	if (count(themins.begin(), themins.end(), themins[idx]) > 1)
		return -1;
	else
	//no tie
		return idx;	
	
}


int main()
{

	Medici mci;
	vector<int> v1 = { 39, 42, 57 }, v2 = { 42, 39, 57 }, v3 = { 57, 39, 42 };

	int idx = mci.winner(v1, v2, v3);
	return 0;
}

