// srm409.cpp : Defines the entry point for the console application.
//

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

/*
64

32 \32

16 16

16 8 \8

16 4 4

16 4 2 2

16 4 2 1 \1
*/


class Stick
{
public:
	int pieces(int x);
};

int Stick::pieces(int x)
{	
	vector<int> parts;
	parts.push_back(64);
	int sum = accumulate(parts.begin(),parts.end(),0);

	while (sum > x)
	{
		int half = parts[parts.size()-1] / 2;
		int remain = sum - half;		
		
		if (remain >= x)
		{			
			parts[parts.size() - 1] = half;
		}
		else
		{
			parts[parts.size() - 1] = half;
			parts.push_back(half);
		}
		
		sum = accumulate(parts.begin(), parts.end(), 0);
		
	}

	return parts.size();
}


int main()
{
	Stick st;

	int nofpieces = st.pieces(32);
	return 0;
}

