// srm674.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <algorithm>
using namespace std;

class RelationClassifier
{
public:
	string isBijection(vector <int> domain, vector <int> range);
};

string RelationClassifier::isBijection(vector <int> domain, vector <int> range)
{
	int cnt1Domain = domain.size();	
	sort(domain.begin(), domain.end());
	vector<int>::iterator it = unique(domain.begin(), domain.end());
	int cnt2Domain = distance(domain.begin(), it);

	bool isBij = false;
	if (cnt1Domain == cnt2Domain)
		isBij = true;

	if (isBij == true)
	{
		int cnt1Range = range.size();
		sort(range.begin(), range.end());
		vector<int>::iterator it2 = unique(range.begin(), range.end());
		int cnt2Range = distance(range.begin(), it2);
		
		if (cnt1Range > cnt2Range)
			isBij = false;
	}

	if (isBij)
		return "Bijection";
	else
		return "Not";
}

int main()
{
	RelationClassifier rc;

	vector<int> dm = { 14, 12, 10, 13, 20, 18, 9, 17, 14, 9 };
	vector<int> rg = { 18, 6, 8, 15, 2, 14, 10, 13, 13, 15 };


   string isbij =	rc.isBijection(dm,rg);

   return 0;
}

