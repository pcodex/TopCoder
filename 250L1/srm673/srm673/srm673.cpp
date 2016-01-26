// srm673.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <algorithm>
using namespace std;

class BearSong
{
public:
	int countRareNotes(vector <int> notes);
};

int BearSong::countRareNotes(vector <int> notes)
{
	vector<int> notescpy = notes;

	sort(notescpy.begin(), notescpy.end());

	vector<int>::iterator it = unique(notescpy.begin(), notescpy.end());

	vector<int>nodups(notescpy.begin(), it);

	int singlecnt = 0;
	for (int i = 0; i < nodups.size(); ++i)
	{
		if (count(notes.begin(), notes.end(), nodups[i]) == 1)
		{
			singlecnt++;
		}
	}

	return singlecnt;
}

int main()
{
	BearSong bs;
	vector<int> v = { 8, 8, 7, 6, 7, 3, 5, 10, 9, 3 };
	int cnt = bs.countRareNotes(v);

	return 0;
}

