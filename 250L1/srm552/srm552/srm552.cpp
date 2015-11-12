// srm552.cpp : Defines the entry point for the console application.
//

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class FoxAndFlowerShopDivTwo
{
public:
	int theMaxFlowers(vector <string> flowers, int r, int c);
};

int FoxAndFlowerShopDivTwo::theMaxFlowers(vector <string> flowers, int r, int c)
{	
	int r1cnt = 0, r2cnt = 0;
	int c1cnt = 0, c2cnt = 0;

	

	for (int i = 0; i < r; ++i)
	{
		r1cnt += count(flowers[i].begin(), flowers[i].end(),'F');
	}

	for (int i = r+1; i < flowers.size(); ++i)
	{
		r2cnt += count(flowers[i].begin(), flowers[i].end(), 'F');
	}
	
	int rowmax = max(r1cnt, r2cnt);


	for (int i = 0; i < flowers.size(); ++i)
	{
		c1cnt += count(flowers[i].begin(), flowers[i].begin() + c, 'F');
	}

	for (int i = 0; i < flowers.size(); ++i)
	{
		c2cnt += count(flowers[i].begin()+c+1, flowers[i].end(), 'F');
	}
	int colmax = max(c1cnt, c2cnt);

	return max(rowmax, colmax);

}

int main()
{
	FoxAndFlowerShopDivTwo fp;
	int row = 4, col = 3;

	vector<string> f = { ".FFF..F...",
		"FFF...FF.F",
		"..F.F.F.FF",
		"FF..F.FFF.",
		"..FFFFF...",
		"F....FF...",
		".FF.FF..FF",
		"..F.F.FFF.",
		".FF..F.F.F",
		"F.FFF.FF.F" };
	
	int num = fp.theMaxFlowers(f, row, col);
	return 0;
}

