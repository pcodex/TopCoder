// srm403.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class TheLargestLuckyNumber
{
public:

	int find(int n);
	vector<int> gentors(int noDigs);
};


int TheLargestLuckyNumber::find(int n)
{
	int ans = 0;

	int numOfDigits = 0;
	int ncopy = n;
	while (ncopy > 0)
	{
		ncopy = ncopy / 10;
		numOfDigits += 1;
	}
	
	int minim = 0, maxim = 0;

	for (int i = 0; i < numOfDigits; ++i)
	{
		minim += 4 * (pow(10, i));
		maxim += 7 * (pow(10, i));
	}

	if (n < minim)
		return maxim / 10;
	else if (n > maxim)
		return maxim;
	else
	{
		int digit1 = n / (pow(10, numOfDigits - 1));

		if (digit1 >= 4 && digit1 < 7)
		{
			minim = minim;
			
			maxim = 4 * pow(10, numOfDigits - 1);

			for (int i = 0; i < numOfDigits-1; ++i)
			{				
				maxim += 7 * (pow(10, i));
			}

			if (n == minim)
				return minim;

			if (n == maxim)
				return maxim;

			vector<int> vs = gentors(numOfDigits);			

			int prevnum = minim, currnum=minim;
			for (int t = 0; t < vs.size(); ++t)
			{
				currnum = minim + vs[t];
				if (currnum > n)
					break;
				prevnum = currnum;
			}

			return prevnum;
		}
		else if (digit1 >= 7)
		{
			maxim = maxim;

			minim = 7 * pow(10, numOfDigits - 1);
			for (int i = 0; i < numOfDigits - 1; ++i)
			{
				minim += 4 * (pow(10, i));
			}

			if (n == minim)
				return minim;
			if (n == maxim)
				return maxim;

			int prevmaxim = 4 * pow(10, numOfDigits - 1);

			for (int i = 0; i < numOfDigits - 1; ++i)
			{
				prevmaxim += 7 * (pow(10, i));
			}

			if (n < minim)
				return prevmaxim;

			vector<int> vs = gentors(numOfDigits);			

			int prevnum = minim, currnum = minim;
			for (int t = 0; t < vs.size(); ++t)
			{
				currnum = minim + vs[t];
				if (currnum > n)
					break;
				prevnum = currnum;
			}

			return prevnum;
		}
	}
	return 0;
}

vector<int> TheLargestLuckyNumber::gentors(int noDigs)
{
	int start = 3;
	vector<int> vs = { start };
	int cnt = 1;
	int pof2 = 1;
	int noOfGens = (pow(2, noDigs - 1)) - 1;
	while (cnt < noOfGens)
	{
		cnt += 1;
		if ((cnt&(cnt - 1)) == 0){
			vs.push_back(3 * (pow(10, pof2)));
			pof2 += 1;
		}
		else
		{
			size_t sz = vs.size();
			for (int i = 0; i < sz - 1; ++i)
			{
				vs.push_back(vs[sz - 1] + vs[i]);
			}
			cnt = vs.size();
		}
	}

	return vs;
}


int main()
{
	TheLargestLuckyNumber ln;
	
	int opnum9 = ln.find(666666);//7747777	
	
	return 0;
}