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

class PalindromizationDiv2
{
	bool isPalind(int n);
public:
	int getMinimumCost(int X);
};

bool PalindromizationDiv2::isPalind(int num)
{
	stringstream snum;
	snum << num;

	string thenum = snum.str();
	string revnum = thenum;
	reverse(revnum.begin(), revnum.end());

	if (thenum == revnum)
		return true;
	else return false;
}

int PalindromizationDiv2::getMinimumCost(int X)
{
	int tmp = X;
	int cnt1 = 0, cnt2=0;
	while (!isPalind(tmp))
	{
		tmp++;
		cnt1++;
	}

	tmp = X;
	while (!isPalind(tmp))
	{
		tmp--;
		cnt2++;
	}
	return min(cnt1,cnt2);
}

int main()
{
	PalindromizationDiv2 pd;
	int res = pd.getMinimumCost(25);
	return 0;
}