// srm220.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class LeapAge
{
private:
	bool checkIfLeap(int yr);
public:
	int getAge(int year, int born);
};


bool LeapAge::checkIfLeap(int yr)
{
	bool isLeap = false;
	if (yr % 100 == 0)
	{
		if (yr % 400==0)
			isLeap = true;
	}
	else if (yr % 4 == 0)
	{
		isLeap = true;
	}

	return isLeap;
}

int LeapAge::getAge(int year, int born)
{
	int cnt = 0;
	
	for (int i = born + 1; i <= year; ++i)
	{
		if (checkIfLeap(i))
		{
			cnt++;
			i += 3;
		}
	}

	return cnt;
}



int main()
{
	LeapAge lg;

	int y = 4642;
	int b = 3967;

	int cnt = lg.getAge(y, b);

	return 0;
}

