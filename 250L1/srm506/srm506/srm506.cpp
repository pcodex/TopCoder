#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <cctype>
#include <vector>
#include <numeric>

using namespace std;

class SlimeXSlimeRancher2
{
public:
	int train(vector <int> attributes);

};

int SlimeXSlimeRancher2::train(vector <int> attributes)
{
	int ini = accumulate(attributes.begin(), attributes.end(), 0);

	int maxi = *(max_element(attributes.begin(), attributes.end()));

	return ((maxi*attributes.size()) - ini);
}

int main()
{
	SlimeXSlimeRancher2 st;
	vector<int> ss = { 900, 500, 100 };

	int res = st.train(ss);
	return 0;
}