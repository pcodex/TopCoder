// srm669.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

class LiveConcert
{
public:
	int maxHappiness(vector <int> h, vector <string> s);
};

int LiveConcert::maxHappiness(vector <int> h, vector <string> s)
{
	map<string, int> m_art_song;


	for (int i = 0; i < s.size(); ++i)
	{
		if (m_art_song[s[i]] < h[i])
			m_art_song[s[i]] = h[i];
	}

	int maxhapp = 0;
	for (map<string,int>::iterator cnt = m_art_song.begin(); cnt != m_art_song.end(); cnt++)
	{
		maxhapp += cnt->second;
	}

	return maxhapp;
}


int main()
{
	vector<int> v = { 10, 5, 6, 7, 1, 2 };
	vector<string> vs = { "ciel", "bessie", "john", "bessie", "bessie", "john" };

	LiveConcert lc;
	int out = lc.maxHappiness(v, vs);


	return 0;
}

