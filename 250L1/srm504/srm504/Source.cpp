#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

class ComparerInator
{
public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted);
};


int ComparerInator::makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
{
	int ans1 = 1;
	int ans2 = 7;
	int wantdcnt = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] == wanted[i])
			wantdcnt++;
	}

	if (wantdcnt == A.size())
		return ans1;

	wantdcnt = 0;
	for (int i = 0; i < B.size(); ++i)
	{
		if (B[i] == wanted[i])
			wantdcnt++;
	}

	if (wantdcnt == B.size())
		return ans1;

	wantdcnt = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] < B[i])
		{
			if(wanted[i] == A[i])
				wantdcnt++;
		}
		else
		{
			if (wanted[i] == B[i])
				wantdcnt++;
		}
	}

	if (wantdcnt == A.size())
		return ans2;

	wantdcnt = 0;
	for (int i = 0; i < B.size(); ++i)
	{
		if (A[i] < B[i])
		{
			if (wanted[i] == B[i])
				wantdcnt++;
		}
		else
		{
			if (wanted[i] == A[i])
				wantdcnt++;
		}
	}

	if (wantdcnt == A.size())
		return ans2;


	return -1;
}


int main()
{
	ComparerInator cn;
	vector<int> A = { 1, 3 };
	vector<int> B = { 2, 1 };
	vector<int> wan = { 2, 3 };

	int ans = cn.makeProgram(A, B, wan);
	return 0;
}