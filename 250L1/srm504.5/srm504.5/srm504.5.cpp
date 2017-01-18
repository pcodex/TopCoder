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

class TheJackpotDivTwo
{
public:
	vector <int> find(vector <int> money, int jackpot);
};

vector <int> TheJackpotDivTwo::find(vector <int> money, int jackpot)
{
	while (jackpot > 0)
	{
		sort(money.begin(), money.end());		
		money[0] += 1;
		jackpot--;
	}

	sort(money.begin(), money.end());

	return money;
}


int main()
{
	TheJackpotDivTwo jd;
	vector<int> mn = { 1, 2, 3, 4 };
	int jk = 2;

	vector<int> vv = jd.find(mn, jk);
	return 0;
}