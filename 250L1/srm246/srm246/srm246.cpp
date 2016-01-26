// srm246.cpp : Defines the entry point for the console application.
//

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

class CalcTest
{
public:
	vector <string> uniform(vector <string> numbers);
};


vector <string> CalcTest::uniform(vector <string> numbers)
{
	for (int i = 0; i < numbers.size(); ++i)
	{
		size_t pos = 0;
		while ((pos = numbers[i].find(' ')) != std::string::npos)
		{
			numbers[i].erase(pos,1);			
		}

		for (int j = 0; j < numbers[i].length(); ++j)
		{
			if (!isdigit(numbers[i][j]))
				numbers[i][j] = '.';
		}
	}

	return numbers;


}


int main()
{
	CalcTest ct;
	vector<string> n = {"8  0 81 "};
	vector<string> vv = ct.uniform(n);
	return 0;
}

