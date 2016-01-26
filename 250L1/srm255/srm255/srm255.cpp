// srm255.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cctype>
#include <numeric>

using namespace std;

class SequenceOfNumbers
{
public:
	vector <string> rearrange(vector <string> sequence);
};

vector <string> SequenceOfNumbers::rearrange(vector <string> sequence)
{
	vector<int> nos;	

	for (int i = 0; i < sequence.size(); ++i)
	{
		int no = 0;
		stringstream ss(sequence[i]);
		ss >> no;
		nos.push_back(no);
	}

	sort(nos.begin(), nos.end());

	vector<string> asStr;
	for (int i = 0; i < nos.size(); ++i)
	{
		stringstream ss;
		ss << nos[i];
		asStr.push_back(ss.str());
	}

	return asStr;

}


	int main()
{
	SequenceOfNumbers sn;
	vector<string> s = { "1", "174", "23", "578", "71", "9" };
	vector<string> sou = sn.rearrange(s);
	return 0;
}

