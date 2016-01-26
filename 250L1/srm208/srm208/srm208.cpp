// srm208.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class ImageDithering
{
public:
	int count(string dithered, vector <string> screen);
};


int ImageDithering::count(string dithered, vector <string> screen)
{
	int totcnt = 0;
	for (int i = 0; i < dithered.length(); ++i)
	{
		for (int j = 0; j < screen.size(); ++j)
		{
			totcnt += std::count(screen[j].begin(), screen[j].end(), dithered[i]);

		}
	}

	return totcnt;

}

int main()
{
	ImageDithering imgd;

	string d = "ACEGIKMOQSUWY";
	vector<string> scr = { "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX" };

	int pixCnt = imgd.count(d, scr);
	return 0;
}

