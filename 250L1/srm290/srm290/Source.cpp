#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <math.h>
#include <functional>

using namespace std;

class SpeedTyper
{
public:
	string lettersToPractice(string letters, vector <int> times);
};


string SpeedTyper::lettersToPractice(string letters, vector <int> times)
{
	vector<int> dur;
	dur.push_back(times[0]);

	for (int i = 1; i < times.size(); ++i)
	{
		dur.push_back(times[i] - times[i - 1]);
	}

	int tot = accumulate(dur.begin(), dur.end(), 0);

	int avg = tot / times.size();

	string slomo = "";
	for (int i = 0; i < dur.size(); ++i)
	{
		if (dur[i]>avg)
			slomo += letters[i];
	}

	return slomo;
}

int main()
{
	SpeedTyper st;
	vector<int> t = { 250, 300, 400, 800 };
	string sl = st.lettersToPractice("dcab",t);
	return 0;
}