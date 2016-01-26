// srm544.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class ElectionFraudDiv2
{
public:
	string IsFraudulent(vector <int> percentages);
};

string ElectionFraudDiv2::IsFraudulent(vector <int> percentages)
{
	double s1 = 0, s2 = 0;
	for (int i = 0; i < percentages.size(); ++i)
	{
		if (percentages[i])
			s1 += percentages[i] - 0.5;
		s2 += percentages[i] + 0.5;
	}

	if (s1>100.0 || s2 <= 100.0)
		return "YES";
	else
		return "NO";
}



int main()
{
	ElectionFraudDiv2 efd;

	//vector<int> vv = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8 };
	vector<int> vv = {12,12,12,12,12,12,12,12};
	//vector<int> vv = {28,38,33};
	//vector<int> vv = { { 23, 0, 17, 17, 24, 0, 21, 0, 0 } }

	string re = efd.IsFraudulent(vv);
	
	return 0;
}

