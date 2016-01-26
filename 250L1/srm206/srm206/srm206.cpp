// srm206.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <math.h>
using namespace std;

class Bits
{
public:
	int minBits(int n);
};


int Bits::minBits(int n)
{

	int runningcnt = 0;
	int bitsNeeded = 0;
	while (runningcnt < n)
	{
		runningcnt += pow(2, bitsNeeded);
		bitsNeeded += 1;
	}

	return bitsNeeded;
}


	int main()
{
	Bits bs;

	int num = 12;

	int minbis = bs.minBits(num);
	return 0;
}

