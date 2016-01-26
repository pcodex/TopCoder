// srm215.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

class DivisorDigits
{
public:
	int howMany(int number);
};

int DivisorDigits::howMany(int number)
{
	stringstream snum;

	snum << number;

	string str_num = snum.str();

	int cnt = 0;
	for (int i = 0; i < str_num.length(); ++i)
	{
		stringstream sing_num;
		sing_num << str_num[i];		

		int div = 0;

		sing_num >> div;

		if (div != 0)
		{
			if (number%div == 0)
				cnt += 1;
		}
	}
	return cnt;

}

int main()
{

	DivisorDigits dd;
	int no = 12345;
	int cnt = dd.howMany(no);

	return 0;
}

