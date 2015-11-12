// srm664.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <set>
#include <sstream>

using namespace std;

class BearCheats
{
public:
	string eyesight(int A, int B);
};

string BearCheats::eyesight(int A, int B)
{
	stringstream ss;

	ss << A;


	string no1 = ss.str();
	ss.str(string());
	ss.clear();

	ss << B;
	string no2 = ss.str();

	size_t ls1 = no1.length();	
	int chngcnt = 0;
	
	for (size_t s = 0; s < ls1; s++)
	{		
		if (no1[s] != no2[s])
			chngcnt++;

		if (chngcnt > 1)
			break;
	}

	
	string res = "glasses";
	if ((chngcnt == 0) ||
		(chngcnt == 1)
		)
		res = "happy";

	return res;
}

int main()
{
	BearCheats bcc;
	int A[] = { 8072, 3072, 508, 540, 854000, 854000, 1, 6, 385900, 123000 };
	string res = "";

	for (int i = 0; i < (sizeof(A) / sizeof(int)) - 1; i += 2)		{
		res = bcc.eyesight(A[i], A[i + 1]);
		cout << res<<endl;
	}

	return 0;
}

