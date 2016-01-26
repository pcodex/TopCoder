// srm201.cpp : Defines the entry point for the console application.
//


#include <vector>


class Multiples
{
public:
	int number(int min, int max, int factor);
};

int Multiples::number(int min, int max, int factor)
{
	
	int noOfMults = 0;

	for (int i = min; i <= max;i++)
	{
		if (i%factor == 0)
			noOfMults++;
	}


	return noOfMults;

}


int main()
{
	Multiples mps;
	int min = -75312,
		max = 407891,
		factor = 14;
	
	int nos = mps.number(min, max, factor);
	return 0;
}

