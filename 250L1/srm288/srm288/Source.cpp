#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>

using namespace std;

class AccountBalance
{
public:
	int processTransactions(int startingBalance, vector <string> transactions);
};

int AccountBalance::processTransactions(int startingBalance, vector <string> transactions)
{
	int  finalb = startingBalance;

	for (int i = 0; i < transactions.size(); ++i)
	{
		stringstream ss(transactions[i]);
		string typ; int trans;
		ss >> typ;
		ss >> trans;

		if (typ == "C")
			finalb += trans;
		else if (typ == "D")
			finalb -= trans;
	}

	return finalb;
}

int main()
{
	AccountBalance ab;
	int s = 53874;
	vector<string> t = { "D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567" };
	int left = ab.processTransactions(s, t);
	return 0;
}