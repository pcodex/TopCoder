// srm705.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

class SuperUserDo
{
public:
	int install(vector <int> A, vector <int> B);
};

int SuperUserDo::install(vector <int> A, vector <int> B)
{
	set<int> myset;

	for (int i = 0; i < A.size(); ++i)
	{
		int inset = A[i];
		while (inset<=B[i])
		{
			myset.insert(inset);
			inset++;
		}
	}

	int num = myset.size();
	return num;
}


int main()
{
	SuperUserDo sdo;
	vector<int> a = { 1, 101 };
	vector<int> b = { 10, 110 };
	int ret= sdo.install(a, b);
	return 0;
}

