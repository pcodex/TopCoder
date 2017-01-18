// srm274.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

class SimpleDuplicateRemover
{
public:
	vector <int> process(vector <int> sequence);
};


vector <int> SimpleDuplicateRemover::process(vector <int> sequence)
{
	vector<int> st;

	for (int i = sequence.size()-1; i >= 0; --i)
	{
		if (find(st.begin(), st.end(), sequence[i]) == st.end())
		{
			st.push_back(sequence[i]);
		}
	}

	reverse(st.begin(), st.end());

	return st;

}

	int main()
{
	SimpleDuplicateRemover sdr;
	vector<int> s = { 1, 5, 5, 1, 6, 1 };
	vector<int> o = sdr.process(s);
	return 0;
}

