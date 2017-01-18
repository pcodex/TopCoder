#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cctype>
#include <math.h>
#include <numeric>
#include <set>
#include <stack>
#include <fstream>

using namespace std;

class MedianOfNumbers
{
public:
	int findMedian(vector<int> numbers);
};

int MedianOfNumbers::findMedian(vector<int> numbers)
{
	sort(numbers.begin(), numbers.end());

	if (numbers.size() % 2 != 0)
	{
		return numbers[numbers.size() / 2];
	}

	int lesscnt = 0, morecnt = 0;
	if (numbers[numbers.size() / 2] == numbers[(numbers.size() / 2) - 1])
		return numbers[numbers.size() / 2];
	else
		return -1;	
}



int main()
{
	MedianOfNumbers msl;
	vector<int> n = { 32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21 };
	int med = msl.findMedian(n);
	return 0;
}
